#ifndef PARTICLEHELPER_H
#define PARTICLEHELPER_H

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class ParticleHelper {
public:
    
    static CCParticleSystemQuad* createStarParticles(int maxParticles) {

        auto dict = CCDictionary::createWithContentsOfFileThreadSafe("dragEffect.plist");

        dict->setObject(CCString::create("1"), "emitterType");
        dict->setObject(CCString::create("-1"), "duration");
        dict->setObject(CCString::createWithFormat("%i", maxParticles), "maxParticles");
        dict->setObject(CCString::create("1.5"), "particleLifespan");
        dict->setObject(CCString::create("0"), "angle");
        dict->setObject(CCString::create("180"), "angleVariance");
        dict->setObject(CCString::create("10"), "maxRadius");
        dict->setObject(CCString::create("30"), "minRadius");
        dict->setObject(CCString::create("0"), "sourcePositionx");
        dict->setObject(CCString::create("0"), "sourcePositiony");
        dict->setObject(CCString::create("0"), "sourcePositionVariancex");
        dict->setObject(CCString::create("0"), "sourcePositionVariancey");
        dict->setObject(CCString::create("4"), "startParticleSize");
        dict->setObject(CCString::create("4"), "finishParticleSize");
        dict->setObject(CCString::create("0"), "startParticleSizeVariance");
        dict->setObject(CCString::create("1"), "startColorRed");
        dict->setObject(CCString::create("1"), "startColorGreen");
        dict->setObject(CCString::create("1"), "startColorBlue");
        dict->setObject(CCString::create("1"), "startColorAlpha");
        dict->setObject(CCString::create("1"), "startColorVarianceRed");
        dict->setObject(CCString::create("1"), "startColorVarianceBlue");
        dict->setObject(CCString::create("1"), "startColorVarianceGreen");
        dict->setObject(CCString::create("0"), "startColorVarianceAlpha");
        dict->setObject(CCString::create("1"), "finishColorRed");
        dict->setObject(CCString::create("1"), "finishColorGreen");
        dict->setObject(CCString::create("1"), "finishColorBlue");
        dict->setObject(CCString::create("0"), "finishColorAlpha");
        dict->setObject(CCString::create("1"), "finishColorVarianceRed");
        dict->setObject(CCString::create("1"), "finishColorVarianceBlue");
        dict->setObject(CCString::create("1"), "finishColorVarianceGreen");
        dict->setObject(CCString::create("0"), "finishColorVarianceAlpha");

        auto p = CCParticleSystemQuad::create();
        p->initWithDictionary(dict, false);
        
        return p;
    }

    static CCParticleSystemQuad* createSquareParticles(int maxParticles, ccColor3B col) {

        auto dict = CCDictionary::createWithContentsOfFileThreadSafe("dragEffect.plist");

        dict->setObject(CCString::create("0"), "emitterType");
        dict->setObject(CCString::create("-1"), "duration");
        dict->setObject(CCString::createWithFormat("%i", maxParticles), "maxParticles");
        dict->setObject(CCString::create("3"), "particleLifespan");
        dict->setObject(CCString::create("1.5"), "particleLifespanVariance");
        dict->setObject(CCString::create("0"), "angle");
        dict->setObject(CCString::create("0"), "speed");
        dict->setObject(CCString::create("0"), "speedVariance");
        dict->setObject(CCString::create("180"), "angleVariance");
        dict->setObject(CCString::create("10"), "maxRadius");
        dict->setObject(CCString::create("30"), "minRadius");
        dict->setObject(CCString::create("0"), "sourcePositionx");
        dict->setObject(CCString::create("0"), "sourcePositiony");
        dict->setObject(CCString::create("20"), "sourcePositionVariancex");
        dict->setObject(CCString::create("20"), "sourcePositionVariancey");
        dict->setObject(CCString::create("4"), "startParticleSize");
        dict->setObject(CCString::create("2"), "finishParticleSize");
        dict->setObject(CCString::create("1"), "finishParticleSizeVariance");
        dict->setObject(CCString::createWithFormat("%i", col.r), "startColorRed");
        dict->setObject(CCString::createWithFormat("%i", col.g), "startColorGreen");
        dict->setObject(CCString::createWithFormat("%i", col.b), "startColorBlue");
        dict->setObject(CCString::create("1"), "startColorAlpha");
        dict->setObject(CCString::create("0"), "startColorVarianceRed");
        dict->setObject(CCString::create("0"), "startColorVarianceBlue");
        dict->setObject(CCString::create("0"), "startColorVarianceGreen");
        dict->setObject(CCString::create("0"), "startColorVarianceAlpha");
        dict->setObject(CCString::createWithFormat("%i", col.r), "finishColorRed");
        dict->setObject(CCString::createWithFormat("%i", col.g), "finishColorGreen");
        dict->setObject(CCString::createWithFormat("%i", col.b), "finishColorBlue");
        dict->setObject(CCString::create("0"), "finishColorAlpha");
        dict->setObject(CCString::create("0"), "finishColorVarianceRed");
        dict->setObject(CCString::create("0"), "finishColorVarianceBlue");
        dict->setObject(CCString::create("0"), "finishColorVarianceGreen");
        dict->setObject(CCString::create("0"), "finishColorVarianceAlpha");
        dict->setObject(CCString::create("0"), "gravityy");

        auto p = CCParticleSystemQuad::create();
        p->initWithDictionary(dict, false);
        
        return p;
    }
};

#endif