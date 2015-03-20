/***************************************************************************************
*	Title: EnemyBShip.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyBShip.h"

#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/GameObjects/Components/MovementComponent.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Ids/SpriteIds.h"
#include "../../Ids/TextureIds.h"

int			EnemyBShip::MAX_HP = 50;
float		EnemyBShip::BORDER_LIMIT = 22.0f;
float		EnemyBShip::STOP_HEIGHT = 12.0f;

EnemyBShip::EnemyBShip() : EnemyShip(), borderDirection_(Direction::DOWN), spawnX_(0.0f), currentStep_(EnemyBShip::NEUTRAL) {
    assert(addComponent<MovementComponent>());
    component_cast<MovementComponent>(this)->setFrictionMultiplier(0.93f);
}

EnemyBShip::~EnemyBShip() {
    // detach events
    detachEvent(ev::id::UPDATE, *this);
}

void EnemyBShip::init() {
    // TODO: change sprite
    pSprite_ = SpriteManager::getInstancePtr()->getSprite(spr::ENEMY_A_SHIP_SPRITE);

    component_cast<TransformComponent>(this)->setScale(Vector3(1.0f));
    component_cast<TransformComponent>(this)->setRotation(Vector3(0.0f));
    component_cast<TransformComponent>(this)->setTranslation(Vector3(0.0f));

    // attach events
    attachEvent(ev::id::UPDATE, *this);
}

void EnemyBShip::reset() {
    auto pMove(component_cast<MovementComponent>(this));
    pMove->setVelocity(0.0f);
    hp_ = MAX_HP;
    currentStep_ = EnemyBShip::NEUTRAL;
    spawnX_ = 0.0f;
    borderDirection_ = Direction::DOWN;
}

void EnemyBShip::spawn(float x, float y) {
    if (borderDirection_ == Direction::DOWN) {
        currentStep_ = EnemyBShip::STEP_01_CENTER;
    } else {
        currentStep_ = EnemyBShip::STEP_01;
    }

    spawnX_ = x;

    component_cast<TransformComponent>(this)->setTranslation(Vector3(x, y, -0.1f));
}

void EnemyBShip::spawn(float x, float y, Direction borderDirection) {
    reset();
    setActive(true);

    borderDirection_ = borderDirection;

    spawn(x, y);
}

int EnemyBShip::getMaxHp() {
    return MAX_HP;
}

void EnemyBShip::update() {
    // update
    if (isActive()) {

        auto pMove(component_cast<MovementComponent>(this));
        const float speed(0.85f);// static??
        auto tr(component_cast<TransformComponent>(this)->getTranslation());

        switch (currentStep_) {
            case EnemyBShip::NEUTRAL:
                break;
            case EnemyBShip::STEP_01_CENTER:
                if (tr.getY() < STOP_HEIGHT) {
                    pMove->setVelocity(0.0f);

                    // try to shoot
                    tryToShoot();

                    // try to leave
                    if (rand_int(0, 8000) < 25)
                        currentStep_ = EnemyBShip::STEP_05;

                } else {
                    pMove->accelerate(Direction::DOWN, speed);
                }
                break;
            case EnemyBShip::STEP_01:
                pMove->accelerate(Direction::DOWN, speed);
                if (tr.getY() < STOP_HEIGHT) {
                    currentStep_ = EnemyBShip::STEP_02;
                    pMove->setVelocity(0.0f);
                }
                break;
            case EnemyBShip::STEP_02:
                pMove->accelerate(borderDirection_, speed);

                if (tr.getX() < -BORDER_LIMIT || tr.getX() > BORDER_LIMIT) {
                    currentStep_ = EnemyBShip::STEP_03;
                    pMove->setVelocity(0.0f);
                } else {
                    // try to shoot
                    tryToShoot();
                }
                break;
            case EnemyBShip::STEP_03:
                pMove->accelerate(borderDirection_, -speed);
                if ((borderDirection_ == Direction::LEFT && tr.getX() > spawnX_) ||
                        (borderDirection_ == Direction::RIGHT && tr.getX() < spawnX_)) {
                    currentStep_ = EnemyBShip::STEP_04;
                    pMove->setVelocity(0.0f);
                } else {
                    // try to shoot
                    tryToShoot();
                }
                break;
            case EnemyBShip::STEP_04:
                pMove->accelerate(borderDirection_, speed);

                if (tr.getX() < -BORDER_LIMIT || tr.getX() > BORDER_LIMIT) {
                    currentStep_ = EnemyBShip::STEP_05;
                    pMove->setVelocity(0.0f);
                } else {
                    // try to shoot
                    tryToShoot();

                    // try to leave
                    if (rand_int(0, 1500) < 25) {
                        currentStep_ = EnemyBShip::STEP_05;
                        pMove->setVelocity(0.0f);
                    }
                }
                break;
            case EnemyBShip::STEP_05:
                pMove->accelerate(Direction::DOWN, speed);

                if (component_cast<TransformComponent>(this)->getTranslation().getY() < -16.0f) {
                    setActive(false);
                }
                break;
            default:
                break;
        }

    }
}

void EnemyBShip::handleEvent(Event* pEvent) {
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
