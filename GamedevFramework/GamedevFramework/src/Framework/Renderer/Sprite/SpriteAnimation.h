/***************************************************************************************
*	Title: SpriteAnimation.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SPRITE_ANIMATION_H_
#define SPRITE_ANIMATION_H_

#include "Sprite.h"
#include <vector>
#include "../Texture/TextureId.h"
#include "../../Math/Vector3.h"

using namespace std;

namespace Framework {

    class SpriteAnimation {
        private:
            // frame starts count at 1, zero means no frame is to be displayed
            unsigned int currentFrame_;
            float fps_;
            float spf_;
            bool loop_;
            bool playing_;
            float deltaTime_;

            vector<Sprite*> spriteV_;
        public:
            SpriteAnimation();
            SpriteAnimation(unsigned int totalFrames, float fps);
            SpriteAnimation(unsigned int totalFrames, float fps, bool loop);
            virtual ~SpriteAnimation();

            void addFrame(Sprite* pSprite);

            unsigned int getCurrentFrame() {
                return currentFrame_;
            }

            void goToAndPlay(unsigned int frame);
            void goToAndPause(unsigned int frame);
            void play();
            void stop();
            void pause();

            void update();

            void render();
    };

}

#endif // SPRITE_ANIMATION_H_
