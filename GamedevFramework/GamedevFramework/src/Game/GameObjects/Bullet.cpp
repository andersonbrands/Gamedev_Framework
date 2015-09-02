/***************************************************************************************
*	Title: Bullet.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "Bullet.h"

Bullet::Bullet() {
    assert(addComponent<TransformComponent>());
    assert(addComponent<MovementComponent>());
    auto movement(component_cast<MovementComponent>(this));
    movement->setMaxSpeed(45.0f);
    movement->setFrictionMultiplier(0.93f);

    assert(addComponent<SpriteComponent>());


    attachEvent(ev::id::COLLISION, *this);
}

Bullet::~Bullet() {
    detachEvent(ev::id::COLLISION, *this);
}

void Bullet::spawn(float x, float y) {
    setFree(false);
    setActive(true);
    component_cast<TransformComponent>(this)->setTranslation(Vector3(x, y, 0.0f));
}

void Bullet::remove() {
    setFree(true);
    setActive(false);
}

void Bullet::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::COLLISION: {
            if (isActive()) {
                remove();
            }
            break;
        }
        default:
            break;
    }
}
