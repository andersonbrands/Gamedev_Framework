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
    movement->setFrictionMultiplier(0.9f);

    assert(addComponent<SpriteComponent>());
}

Bullet::~Bullet() {

}

void Bullet::spawn(float x, float y) {
    setFree(false);
    setActive(true);
    component_cast<TransformComponent>(this)->setTranslation(Vector3(x, y, 0.0f));
}

void Bullet::handleEvent(Event* pEvent) {

}
