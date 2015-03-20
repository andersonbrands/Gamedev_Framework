/***************************************************************************************
*	Title: EnemyBullet.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyBullet.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Ids/SpriteIds.h"

int EnemyBullet::damage_ = 10;

EnemyBullet::EnemyBullet() {

}

EnemyBullet::~EnemyBullet() {
    detachEvent(ev::id::PRE_UPDATE, *this);
    detachEvent(ev::id::POST_UPDATE, *this);
}

int		EnemyBullet::getDamage() const {
    return damage_;
}

void	EnemyBullet::init() {
    auto sprite(SpriteManager::getInstancePtr()->getSprite(spr::ENEMY_BULLET_SPRITE));
    component_cast<SpriteComponent>(this)->setSprite(sprite);

    attachEvent(ev::id::PRE_UPDATE, *this);
    attachEvent(ev::id::POST_UPDATE, *this);
}

void EnemyBullet::handleEvent(Event* pEvent) {
    if (!isActive())
        return;

    switch (pEvent->getID()) {
        case ev::id::PRE_UPDATE : {
            auto movement(component_cast<MovementComponent>(this));
            movement->accelerate(Direction::DOWN, 15.0f);
            break;
        }
        case ev::id::POST_UPDATE : {
            auto translation(component_cast<TransformComponent>(this)->getTranslation());

            if (translation.getY() < -16.0f) {
                setFree(true);
                setActive(false);
            }
            break;
        }
        default:
            break;
    }
}