/***************************************************************************************
*	Title: EnemyCShip.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyCShip.h"

#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/GameObjects/Components/MovementComponent.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../../Framework/Collision/CollisionManager.h"
#include "../../Ids/SpriteIds.h"
#include "../../Ids/TextureIds.h"

int		EnemyCShip::MAX_HP = 30;
int		EnemyCShip::MIN_FLIP_PROB = 1;

EnemyCShip::EnemyCShip() :EnemyShip(), horizontalDirection_(Direction::LEFT), flipProbability_(MIN_FLIP_PROB) {
    assert(addComponent<MovementComponent>());
    component_cast<MovementComponent>(this)->setFrictionMultiplier(0.9f);
}

EnemyCShip::~EnemyCShip() {
    // detach events
    detachEvent(ev::id::UPDATE, *this);
}

void EnemyCShip::init() {
    // TODO: change sprite
    pSprite_ = SpriteManager::getInstancePtr()->getSprite(spr::ENEMY_A_SHIP_SPRITE);

    component_cast<TransformComponent>(this)->setScale(Vector3(1.0f));
    component_cast<TransformComponent>(this)->setRotation(Vector3(0.0f));
    component_cast<TransformComponent>(this)->setTranslation(Vector3(0.0f));

    // attach events
    attachEvent(ev::id::UPDATE, *this);
}

void EnemyCShip::reset() {
    auto pMove(component_cast<MovementComponent>(this));
    pMove->setVelocity(0.0f);
    hp_ = MAX_HP;
}

void EnemyCShip::spawn(float x, float y) {
    reset();
    setActive(true);

    auto colManager = CollisionManager::getInstancePtr();
    colManager->addObjectToGroup(0, this);

    horizontalDirection_ = (std::rand()%2)?Direction::LEFT:Direction::RIGHT;

    component_cast<TransformComponent>(this)->setTranslation(Vector3(x, y, -0.1f));
}

void EnemyCShip::flipH() {
    switch (horizontalDirection_) {
        case Direction::RIGHT:
            horizontalDirection_ = Direction::LEFT;
            break;
        case Direction::LEFT:
            horizontalDirection_ = Direction::RIGHT;
            break;
        default:
            break;
    }
    flipProbability_ = MIN_FLIP_PROB;
}

int EnemyCShip::getMaxHp() {
    return MAX_HP;
}

void EnemyCShip::reachHorizontalLimit(Direction directionToGo, float limit) {
    auto tr(component_cast<TransformComponent>(this));

    horizontalDirection_ = directionToGo;
    tr->translate(Vector3(-tr->getTranslation().getX() + limit, 0.0f, 0.0f));
    flipProbability_ = MIN_FLIP_PROB;
}

void EnemyCShip::update() {
    // update
    if (isActive()) {
        float limitH(22.5f);
        auto tr(component_cast<TransformComponent>(this));

        if (tr->getTranslation().getX() < -limitH)
            reachHorizontalLimit(Direction::RIGHT, -limitH);
        else if (tr->getTranslation().getX() > limitH)
            reachHorizontalLimit(Direction::LEFT, limitH);
        else if (rand_int(0, 8000) < flipProbability_++)
            flipH();

        // try to shoot
        tryToShoot();

        auto pMove(component_cast<MovementComponent>(this));
        pMove->accelerate(Direction::DOWN, 0.2f);
        pMove->accelerate(horizontalDirection_, 0.8f);

        if (tr->getTranslation().getY() < -16.0f) {
            remove();
            //setActive(false);
            //auto colManager = CollisionManager::getInstancePtr();
            //colManager->removeObjectFromGroup(0, this);
        }
    }
}

void EnemyCShip::handleEvent(Event* pEvent) {
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