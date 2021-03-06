/***************************************************************************************
*	Title: SpriteAnimation.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "SpriteAnimation.h"
#include "../../Utilities/Timer.h"
#include <cassert>

namespace Framework {

    SpriteAnimation::SpriteAnimation(unsigned int totalFrames, float fps) : totalFrames_(totalFrames), currentFrame_(0), fps_(fps), spf_(1/fps), loop_(true), playing_(false), deltaTime_(0.0f), spriteV_() {
        spriteV_.reserve(totalFrames_);
    }

    SpriteAnimation::~SpriteAnimation() {
        spriteV_.clear();
    }

    void SpriteAnimation::addFrame(Sprite* pSprite) {
        spriteV_.push_back(pSprite);
    }

    void SpriteAnimation::goToAndPlay(unsigned int frame) {
        assert(frame <= totalFrames_);
        currentFrame_ = frame;
        play();
    }
    void SpriteAnimation::goToAndPause(unsigned int frame) {
        assert(frame <= totalFrames_);
        currentFrame_ = frame;
        pause();
    }

    void SpriteAnimation::play() {
        playing_ = true;
        if (currentFrame_ == 0) {
            currentFrame_ = 1;
        }
    }

    void SpriteAnimation::stop() {
        playing_ = false;
        currentFrame_ = 0;
        deltaTime_ = 0.0f;
    }

    void SpriteAnimation::pause() {
        playing_ = false;
    }

    void SpriteAnimation::update() {
        if (!currentFrame_ || !playing_) {
            return;
        }

        assert(Timer::getInstancePtr());
        float delta = Timer::getInstancePtr()->getTimeSim();

        deltaTime_ += delta;

        if (deltaTime_ > spf_) {
            ++currentFrame_;
            deltaTime_ -= spf_;
        }

        if (currentFrame_ > totalFrames_) {
            if (loop_)
                currentFrame_ = 1;
            else
                stop();
        }

    }

    void SpriteAnimation::render() {
        if (currentFrame_)
            spriteV_.at(currentFrame_ - 1)->render();
    }

}