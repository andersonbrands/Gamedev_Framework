/***************************************************************************************
*	Title: SpriteAnimationComponent.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SPRITE_ANIMATION_COMPONENT_H_
#define SPRITE_ANIMATION_COMPONENT_H_

#include "../Component.h"
#include "../ComponentId.h"
#include "../../Renderer/Sprite/SpriteAnimation.h"
#include "../../EventManager/EventHandler.h"
#include "../../EventManager/Event.h"

namespace Framework {

    class SpriteAnimationComponent : public Component, public EventHandler, public SpriteAnimation {
        private:
        public:
            explicit SpriteAnimationComponent(GameObject* pOwner);
            virtual ~SpriteAnimationComponent();

            static ComponentId getId()	{
                return comp::SPRITE_ANIMATION;
            }

            void handleEvent(Event* pEvent);
    };

}

#endif // SPRITE_ANIMATION_COMPONENT_H_
