/***************************************************************************************
*	Title: EnemyShip.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyShip.h"

#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/Renderer/Renderer.h"

EnemyShip::EnemyShip() : active_(false) {
    attachEvent(ev::id::RENDER_EVENT, *this);
}

EnemyShip::~EnemyShip() {
    detachEvent(ev::id::RENDER_EVENT, *this);
}

void EnemyShip::handleEvent(Event* pEvent) {

    switch (pEvent->getID()) {
        case ev::id::RENDER_EVENT: {
            if (isActive()) {
                auto pRenderer = Renderer::getInstancePtr();
                assert(pRenderer);
                pRenderer->setTransform(*static_cast<Transform*>(component_cast<TransformComponent>(this)));

                pSprite_->render();
            }
            break;
        }
        default:
            break;
    }

}