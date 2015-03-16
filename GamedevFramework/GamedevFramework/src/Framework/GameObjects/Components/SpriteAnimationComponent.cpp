/***************************************************************************************
*	Title: SpriteAnimationComponent.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "SpriteAnimationComponent.h"
#include "../../EventManager/EventManager.h"
#include "../../Renderer/Renderer.h"
#include "../Components/TransformComponent.h"
#include "../GameObject.h"

namespace Framework {

    SpriteAnimationComponent::SpriteAnimationComponent(GameObject* pOwner) : Component(pOwner), SpriteAnimation() {
        attachEvent(ev::id::RENDER_EVENT, *this);
        attachEvent(ev::id::UPDATE, *this);
    }

    SpriteAnimationComponent::~SpriteAnimationComponent() {
        detachEvent(ev::id::RENDER_EVENT, *this);
        detachEvent(ev::id::UPDATE, *this);
    }

    void SpriteAnimationComponent::handleEvent(Event* pEvent) {
        if (!getOwner()->isActive())
            return;

        switch (pEvent->getID()) {
            case ev::id::RENDER_EVENT: {
                assert(Renderer::getInstancePtr());

                TransformComponent* transformComp = component_cast<TransformComponent>(getOwner());
                assert(transformComp);

                transformComp->setMatrix();

                Renderer::getInstancePtr()->setTransform(transformComp->getMatrix());

                render();

            }
            break;
            case ev::id::UPDATE: {
                update();
            }
            break;
            default:
                break;
        }
    }

}
