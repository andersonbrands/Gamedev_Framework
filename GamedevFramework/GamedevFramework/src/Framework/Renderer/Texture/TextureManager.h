/***************************************************************************************
*	Title: TextureManager.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include "../../Utilities/UnorderedMapContainer.h"
#include "../../Utilities/Singleton.h"
#include "Texture.h"
#include "TextureId.h"
#include <string>

using namespace std;

namespace Framework {

    class TextureManager : public UnorderedMapContainer<TextureId, Texture>, public Singleton<TextureManager> {
        private:
            const string TEXTURE_DIR;
        public:
            TextureManager(const string &textureDir);
            virtual ~TextureManager();

            const string getDir() {
                return TEXTURE_DIR;
            }

            Texture* loadTexture(const TextureIdAndName &idAndName);
            void unloadTexture(const TextureIdAndName &idAndName);

            Texture* getTexture(const TextureId &id) {
                return getObject(id);
            }
    };

}

#endif // TEXTURE_MANAGER_H_
