/***************************************************************************************
*	Title: EnemyBulletManager.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyBulletManager.h"

EnemyBulletManager::EnemyBulletManager(int totalObjects) : BulletManager(totalObjects) {

}

EnemyBulletManager::~EnemyBulletManager() {
    detachEvent(game::ev::id::SPAWN_ENEMY_BULLET, *this);
}

void EnemyBulletManager::init() {
    BulletManager::init();

    attachEvent(game::ev::id::SPAWN_ENEMY_BULLET, *this);
}

void EnemyBulletManager::handleEvent(Event* pEvent) {

    switch (pEvent->getID()) {
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