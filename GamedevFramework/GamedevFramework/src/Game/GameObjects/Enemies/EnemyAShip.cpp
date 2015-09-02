/***************************************************************************************
*	Title: EnemyAShip.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyAShip.h"

#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/GameObjects/Components/MovementComponent.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../../Framework/Collision/CollisionManager.h"
#include "../../Ids/SpriteIds.h"
#include "../../Ids/TextureIds.h"

int EnemyAShip::MAX_HP = 30;

EnemyAShip::EnemyAShip() {
    assert(addComponent<MovementComponent>());
    component_cast<MovementComponent>(this)->setFrictionMultiplier(0.9f);
}

EnemyAShip::~EnemyAShip() {
    // detach events
    detachEvent(ev::id::UPDATE, *this);
}

void EnemyAShip::init() {
    pSprite_ = SpriteManager::getInstancePtr()->getSprite(spr::ENEMY_A_SHIP_SPRITE);

    component_cast<TransformComponent>(this)->setScale(Vector3(1.0f));
    component_cast<TransformComponent>(this)->setRotation(Vector3(0.0f));
    component_cast<TransformComponent>(this)->setTranslation(Vector3(0.0f));

    // attach events
    attachEvent(ev::id::UPDATE, *this);
}

void EnemyAShip::reset() {
    auto pMove(component_cast<MovementComponent>(this));
    pMove->setVelocity(0.0f);
    hp_ = MAX_HP;
}

void EnemyAShip::spawn(float x, float y) {
    reset();
    setActive(true);
    auto colManager = CollisionManager::getInstancePtr();
    colManager->addObjectToGroup(0, this);
    component_cast<TransformComponent>(this)->setTranslation(Vector3(x, y, -0.1f));
}

int EnemyAShip::getMaxHp() {
    return MAX_HP;
}

void EnemyAShip::update() {
    // update
    if (isActive()) {
        auto pMove(component_cast<MovementComponent>(this));
        pMove->accelerate(Direction::DOWN, 0.5f);

        // try to shoot
        tryToShoot();

        if (component_cast<TransformComponent>(this)->getTranslation().getY() < -16.0f) {
            remove();
            //setActive(false);
            //auto colManager = CollisionManager::getInstancePtr();
            //colManager->removeObjectFromGroup(0, this);
        }
    }
}

void EnemyAShip::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::UPDATE: {
            update();
            break;
        }

        default: {
            EnemyShip::handleEvent(pEvent);
            break;
        }
    }
}
