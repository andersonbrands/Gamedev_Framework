/***************************************************************************************
*	Title: SpriteManager.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SPRITE_MANAGER_H_
#define SPRITE_MANAGER_H_

#include "../../Utilities/UnorderedMapContainer.h"
#include "../../Utilities/Singleton.h"
#include "SpriteId.h"
#include "Sprite.h"

namespace Framework {

    class SpriteManager : UnorderedMapContainer<SpriteId, Sprite>, public Singleton<SpriteManager> {
        private:
        public:
            SpriteManager();
            virtual ~SpriteManager();

            Sprite* getSprite(const SpriteInfo &info) {
                Sprite* pSprite(getObject(info.id));
                assert(pSprite);
                return pSprite;
            }

            void addSprite(const SpriteInfo &info) {
                Sprite* pSprite(addObject(info.id));
                assert(pSprite);
                pSprite->setup(info.uuWidth, info.vvHeight, info.textureId, info.align);
            }

            void removeSprite(const SpriteInfo &info) {
                removeObject(info.id);
            }
    };

}

#endif // SPRITE_MANAGER_H_
