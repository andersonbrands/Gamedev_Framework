/***************************************************************************************
*	Title: SpriteComponent.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "SpriteComponent.h"
#include "../../EventManager/EventManager.h"
#include "../../Renderer/Renderer.h"
#include "../Components/TransformComponent.h"
#include "../GameObject.h"

namespace Framework {

    SpriteComponent::SpriteComponent(GameObject* pOwner) : Component(pOwner), pSprite_(nullptr) {
        attachEvent(ev::id::RENDER_EVENT, *this);
    }

    SpriteComponent::~SpriteComponent() {
        detachEvent(ev::id::RENDER_EVENT, *this);
    }

    void SpriteComponent::handleEvent(Event* pEvent) {
        switch (pEvent->getID()) {
            case ev::id::RENDER_EVENT: {
                assert(Renderer::getInstancePtr());

                TransformComponent* transformComp = component_cast<TransformComponent>(getOwner());
                assert(transformComp);

                transformComp->setMatrix();

                Renderer::getInstancePtr()->setTransform(transformComp->getMatrix());

                assert(pSprite_);
                pSprite_->render();
            }
            break;
            default:
                break;
        }
    }

}