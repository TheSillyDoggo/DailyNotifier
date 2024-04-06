#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/RewardsPage.hpp>
#include "ParticleHelper.hpp"

using namespace geode::prelude;

Ref<RewardsPage> currentPage = nullptr;
Ref<LoadingCircle> circle = nullptr;
Ref<CCSprite> ex = nullptr;
Ref<CCParticleSystem> particles = nullptr;
bool hasGotten = false;

bool left = false;
bool right = false;

class $modify (RewardsPage)
{
	void onReward(cocos2d::CCObject* sender)
	{
		RewardsPage::onReward(sender);

		if (as<CCMenuItemSpriteExtra*>(sender) == m_leftChest)
			left = false;

		if (as<CCMenuItemSpriteExtra*>(sender) == m_rightChest)
			right = false;

		if (circle)
			circle->setVisible(false);

		if (ex)
		{
			ex->setOpacity((left && right) ? 255 : 175);
			ex->setVisible(left || right);
			ex->setScale((left && right) ? 0.6f : 0.45f);
		}

		if (particles)
			particles->setVisible(left || right);
	}

	virtual TodoReturn rewardsStatusFailed()
	{
		if (this == currentPage)
		{
			geode::Notification::create("Daily Notifier | Something went wrong", NotificationIcon::Error)->show();

			this->release();
			return;
		}

		RewardsPage::rewardsStatusFailed();
	}

	virtual TodoReturn rewardsStatusFinished(int p0)
	{
		RewardsPage::rewardsStatusFinished(p0);

		if (this == currentPage)
		{
			left = std::string(m_leftLabel->getString()).starts_with("Open"); //this is really, really shit
			right = std::string(m_rightLabel->getString()).starts_with("Open");
			hasGotten = true;

			log::info("loaded, left: {}, right: {}", left, right);
			log::info("left: {}, right: {}", m_leftLabel->getString(), m_rightLabel->getString());

			if (circle)
				circle->setVisible(false);

			if (ex)
			{
				ex->setOpacity((left && right) ? 255 : 175);
				ex->setVisible(left || right);
				ex->setScale((left && right) ? 0.6f : 0.45f);
			}

			if (particles)
				particles->setVisible(left || right);

			this->release();

			return;
		}
	}
};

class $modify(MenuLayer)
{
	virtual bool init()
	{
		if (!MenuLayer::init())
			return false;

		if (!hasGotten && !currentPage)
		{
			currentPage = RewardsPage::create();
			currentPage->retain();
		}

		auto chest = getChildByID("right-side-menu")->getChildByID("daily-chest-button");

		if (!chest)
			return true;

		circle = LoadingCircle::create();
		circle->setContentSize(ccp(0, 0));
		circle->setScale(0.25f);
		circle->setPosition(ccp(38, 38));
		circle->m_sprite->setPosition(ccp(0, 0));
		circle->setVisible(!hasGotten);
		circle->runAction(CCRepeatForever::create(CCRotateBy::create(1, 360)));

		ex = CCSprite::createWithSpriteFrameName("exMark_001.png");
		ex->setPosition(ccp(38, 38));
		ex->setScale(0.45f);
		ex->setVisible(false);

		particles = ParticleHelper::createSquareParticles(25, ccc3(255, 0, 0));
		particles->setPosition(chest->getContentSize() / 2);
		particles->setVisible(false);

		if (hasGotten)
		{
			ex->setVisible(left || right);
			ex->setOpacity((left && right) ? 255 : 175);
			ex->setScale((left && right) ? 0.6f : 0.45f);
			particles->setVisible(left || right);
		}

		chest->addChild(circle);
		chest->addChild(particles);
		chest->addChild(ex);
		return true;
	}
};

