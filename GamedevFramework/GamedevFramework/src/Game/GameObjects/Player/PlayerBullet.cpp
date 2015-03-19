/***************************************************************************************
*	Title: PlayerBullet.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "PlayerBullet.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Ids/SpriteIds.h"

int PlayerBullet::damage_ = 10;

PlayerBullet::PlayerBullet() {
    
}

PlayerBullet::~PlayerBullet() {
    detachEvent(ev::id::PRE_UPDATE, *this);
    detachEvent(ev::id::POST_UPDATE, *this);
}

int		PlayerBullet::getDamage() const {
    return damage_;
}

void	PlayerBullet::init() {
    auto sprite(SpriteManager::getInstancePtr()->getSprite(spr::PLAYER_BULLET_SPRITE));
    component_cast<SpriteComponent>(this)->setSprite(sprite);

    attachEvent(ev::id::PRE_UPDATE, *this);
    attachEvent(ev::id::POST_UPDATE, *this);
}

void PlayerBullet::handleEvent(Event* pEvent) {
    if (!isActive())
        return;

    switch (pEvent->getID()) {
        case ev::id::PRE_UPDATE : {
            auto movement(component_cast<MovementComponent>(this));
            movement->accelerate(Direction::UP, 15.0f);
            break;
        }
        case ev::id::POST_UPDATE : {
            auto translation(component_cast<TransformComponent>(this)->getTranslation());

            if (translation.getY() > 16.0f) {
                setFree(true);
                setActive(false);
            }
            break;
        }
        default:
            break;
    }
}