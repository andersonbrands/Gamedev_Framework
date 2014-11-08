/***************************************************************************************
*	Title: iSprite.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef I_SPRITE_H_
#define I_SPRITE_H_

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

            virtual void setUVCoords(int index, float u, float v) = 0;
            virtual void setup(Texture *texture, SpriteAlign align, float h, float w) = 0;

            virtual void render() = 0;

        protected:
            virtual void applySettings() = 0;
            Texture *pTexture_;
            SpriteAlign align_;
            float height_;
            float width_;
    };

}

#endif // I_SPRITE_H_
