/***************************************************************************************
*	Title: EnemyBulletManager.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyBulletManager.h"

EnemyBulletManager::EnemyBulletManager(int totalObjects) : BulletManager(totalObjects) {
    attachEvent(ev::id::ATTACH_SCENE_EVENTS, *this);
    attachEvent(ev::id::DETACH_SCENE_EVENTS, *this);
}

EnemyBulletManager::~EnemyBulletManager() {
    detachEvent(ev::id::DETACH_SCENE_EVENTS, *this);
    detachEvent(ev::id::ATTACH_SCENE_EVENTS, *this);
}

void EnemyBulletManager::init() {
    BulletManager::init();
}

void EnemyBulletManager::handleEvent(Event* pEvent) {

    switch (pEvent->getID()) {
        case ev::id::ATTACH_SCENE_EVENTS : {
            attachEvent(game::ev::id::SPAWN_ENEMY_BULLET, *this);
            break;
        }
        case ev::id::DETACH_SCENE_EVENTS : {
            detachEvent(game::ev::id::SPAWN_ENEMY_BULLET, *this);
            break;
        }

        case game::ev::id::SPAWN_ENEMY_BULLET : {
            game::ev::data::SpawnEnemyBullet* pData =
                static_cast<game::ev::data::SpawnEnemyBullet*>(pEvent->getData());

            if (pData) {
                spawnBullet(pData->x, pData->y);
            }

            break;
        }
        default:
            break;
    }
}