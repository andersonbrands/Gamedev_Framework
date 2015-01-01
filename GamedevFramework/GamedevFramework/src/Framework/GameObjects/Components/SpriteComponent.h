/***************************************************************************************
*	Title: SpriteComponent.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef SPRITE_COMPONENT_H_
#define SPRITE_COMPONENT_H_

#include "../Component.h"
#include "../ComponentId.h"
#include "../../Renderer/Sprite/Sprite.h"
#include "../../EventManager/EventHandler.h"
#include "../../EventManager/Event.h"


namespace Framework {

    class SpriteComponent : public Component, public EventHandler {
        private:
            Sprite* pSprite_;
        public:
            explicit SpriteComponent(GameObject* pOwner);
            virtual ~SpriteComponent();

            static ComponentId getId()	{
                return comp::SPRITE_ANIMATION;
            }

            void setSprite(Sprite* pSprite) {
                pSprite_ = pSprite;
            }

            void handleEvent(Event* pEvent);
    };

}

#endif // SPRITE_COMPONENT_H_
