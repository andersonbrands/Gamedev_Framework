/***************************************************************************************
*	Title: Sprite.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SPRITE_H_
#define SPRITE_H_

#include "../../Wrapper.h"

namespace Framework {

    class Sprite : public wSprite {
        private:
        public:
            Sprite();
            virtual ~Sprite();

            void setup(Texture *texture, SpriteAlign align, float h, float w);
    };

}

#endif // SPRITE_H_
