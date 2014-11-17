/***************************************************************************************
*	Title: iSprite.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef I_SPRITE_H_
#define I_SPRITE_H_

#include "../../Math/Vector3.h"

namespace Framework {

    class Texture;

    enum SpriteAlign {
        TOP_LEFT,
        TOP_RIGHT,
        BOTTOM_RIGHT,
        BOTTOM_LEFT,
        CENTER,
        CENTER_LEFT,
        CENTER_TOP,
        CENTER_RIGHT,
        CENTER_BOTTOM
    };

    class iSprite {
        public:
            iSprite() {}
            virtual ~iSprite() {}

            virtual void setup(const Vector3& uuWidth, const Vector3& vvHeight, unsigned int textureId, SpriteAlign align) = 0;

            virtual void render() = 0;

        protected:
            virtual void applySettings() = 0;
            virtual void setUVCoord(int index, float u, float v) = 0;
            virtual void setUVCoords(float minU, float maxU, float minV, float maxV) = 0;
            Texture *pTexture_;
            SpriteAlign align_;
            float height_;
            float width_;
    };

}

#endif // I_SPRITE_H_
