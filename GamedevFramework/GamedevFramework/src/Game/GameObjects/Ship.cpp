/***************************************************************************************
*	Title: Ship.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "Ship.h"

Ship::Ship() : hp_(0), pSprite_(nullptr) {
    assert(addComponent<TransformComponent>());
    assert(addComponent<MovementComponent>());
}

Ship::~Ship() {

}

void Ship::damage(int value) {
    assert(value >= 0);
    hp_ -= value;
}
void Ship::heal(int value) {
    assert(value >= 0);
    hp_ += value;
    if (hp_ > getMaxHp()) {
        hp_ = getMaxHp();
    }
}
