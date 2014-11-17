/***************************************************************************************
*	Title: Sprite.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SPRITE_H_
#define SPRITE_H_

#include "../../Wrapper.h"
#include "../../Math/Vector3.h"

namespace Framework {

    class Sprite : public wSprite {
        private:
        public:
            Sprite();
            virtual ~Sprite();

            virtual void setup(const Vector3& uuWidth, const Vector3& vvHeight, unsigned int textureId, SpriteAlign align);
    };

}

#endif // SPRITE_H_
