/***************************************************************************************
*	Title: Sprite.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "Sprite.h"
#include "../Texture/TextureManager.h"

namespace Framework {

    Sprite::Sprite() {

    }

    Sprite::~Sprite() {

    }

    void Sprite::setup(const Vector3& uuWidth, const Vector3& vvHeight, unsigned int textureId, SpriteAlign align) {
        setUVCoords(uuWidth.getX(), uuWidth.getY(), vvHeight.getX(), vvHeight.getY());

        align_ = align;
        height_ = vvHeight.getZ();
        width_ = uuWidth.getZ();

        auto texManager(TextureManager::getInstancePtr());
        assert(texManager);

        auto pTexture(texManager->getTexture(textureId));
        assert(pTexture);

        pTexture_ = pTexture;

        applySettings();
    }

}