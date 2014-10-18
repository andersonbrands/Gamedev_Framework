/***************************************************************************************
*	Title: TextureManager.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "TextureManager.h"

namespace Framework {

    TextureManager::TextureManager(const string &textureDir) : UnorderedMapContainer(), TEXTURE_DIR(textureDir) {

    }

    TextureManager::~TextureManager() {

    }

    Texture* TextureManager::loadTexture(const TextureIdAndName &idAndName) {
        Texture* result = addObject(idAndName.id);
        if (result)
            result->load(TEXTURE_DIR, idAndName.name);
        return result;
    }

}