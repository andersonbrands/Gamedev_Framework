/***************************************************************************************
*	Title: EnemyShip.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyShip.h"

#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/EventManager/EventData.h"
#include "../../../Framework/Renderer/Renderer.h"
#include "../../Ids/EventIds.h"
#include "../../../Framework/Collision/CollisionManager.h"
#include "../../../Framework/GameObjects/Components/ColliderComponent.h"
#include "../../../Framework/Collision/Colliders/SphereCollider.h"

EnemyShip::EnemyShip()  {
    attachEvent(ev::id::RENDER_EVENT, *this);
    attachEvent(ev::id::COLLISION, *this);
    assert(addComponent<ColliderComponent>());

    auto tr(component_cast<TransformComponent>(this));

    auto col(component_cast<ColliderComponent>(this));
    col->setCollider(new SphereCollider(tr, 3.0f/2.0f));
}

EnemyShip::~EnemyShip() {
    detachEvent(ev::id::RENDER_EVENT, *this);
    detachEvent(ev::id::COLLISION, *this);
}

void EnemyShip::tryToShoot() {
    if (rand_int(0, 100) < 10) {
        auto tr(component_cast<TransformComponent>(this)->getTranslation());

        // send event spawnBullet
        game::ev::data::SpawnEnemyBullet eventData;
        eventData.x = tr.getX();
        eventData.y = tr.getY();

        sendEvent(game::ev::id::SPAWN_ENEMY_BULLET, &eventData);
    }
}

void EnemyShip::remove() {
    setActive(false);
    //auto colManager = CollisionManager::getInstancePtr();
    //colManager->removeObjectFromGroup(0, this);
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
        case ev::id::COLLISION: {
            if (isActive()) {
                //auto pData(static_cast<ev::data::Collision*>(pEvent->getData()));
                remove();
            }
            break;
        }
        default:
            break;
    }

}