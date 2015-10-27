/***************************************************************************************
*	Title: EnemyBullet.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyBullet.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Ids/SpriteIds.h"
#include "../../../Framework/Collision/CollisionManager.h"
#include "../../../Framework/GameObjects/Components/ColliderComponent.h"
#include "../../../Framework/Collision/Colliders/SphereCollider.h"
#include "../../../Framework/Collision/Colliders/AABBCollider.h"

int EnemyBullet::damage_ = 10;

EnemyBullet::EnemyBullet() {

    assert(addComponent<ColliderComponent>());

    auto tr(component_cast<TransformComponent>(this));

    auto col(component_cast<ColliderComponent>(this));
    float radius(0.4f/2.0f);
	// TODO: change collider
    //col->setCollider(new SphereCollider(tr, radius));
    col->setCollider(new AABBCollider(tr, Vector3(-radius, -radius, -2.0f), Vector3(radius, radius, 2.0f)));

}

EnemyBullet::~EnemyBullet() {
    detachEvent(ev::id::PRE_UPDATE, *this);
    detachEvent(ev::id::POST_UPDATE, *this);
}

void EnemyBullet::spawn(float x, float y) {
    Bullet::spawn(x, y);
    auto colManager = CollisionManager::getInstancePtr();

    colManager->addObjectToGroup(3, this);
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
                remove();
            }
            break;
        }
        default:
            Bullet::handleEvent(pEvent);
            break;
    }
}