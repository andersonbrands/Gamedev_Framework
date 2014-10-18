/***************************************************************************************
*	Title: Sprite.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "Sprite.h"

namespace Framework {

    Sprite::Sprite() {

    }

    Sprite::~Sprite() {

    }

    void Sprite::setup(Texture *texture, SpriteAlign align, float h, float w) {
        align_ = align;
        height_ = h;
        width_ = w;

        pTexture_ = texture;

        applySettings();
    }

}