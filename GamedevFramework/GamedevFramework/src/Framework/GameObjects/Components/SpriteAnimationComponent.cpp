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

    SpriteAnimationComponent::SpriteAnimationComponent(GameObject* pOwner) : Component(pOwner), animation_(25, 12) {
        attachEvent(ev::id::RENDER_EVENT, *this);
        attachEvent(ev::id::UPDATE, *this);
    }

    SpriteAnimationComponent::~SpriteAnimationComponent() {

    }

    void SpriteAnimationComponent::handleEvent(Event* pEvent) {
        switch (pEvent->getID()) {
            case ev::id::RENDER_EVENT: {
                assert(Renderer::getInstancePtr());

                TransformComponent* transformComp = component_cast<TransformComponent>(getOwner());
                assert(transformComp);
                Transform& tr = transformComp->getTransform();

                tr.setMatrix();

                Renderer::getInstancePtr()->setTransform(tr.getMatrix());

                animation_.render();

            }
            break;
            case ev::id::UPDATE: {
                animation_.update();
            }
            break;
            default:
                break;
        }
    }

}
