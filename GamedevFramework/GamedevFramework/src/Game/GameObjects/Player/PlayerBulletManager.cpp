/***************************************************************************************
*	Title: PlayerBulletManager.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "PlayerBulletManager.h"

PlayerBulletManager::PlayerBulletManager(int totalObjects) : PoolAllocator(totalObjects) {

}

PlayerBulletManager::~PlayerBulletManager() {

}

void PlayerBulletManager::spawnBullet(float x, float y) {
    auto next(getNextFree());

    if (next) {
        next->spawn(x, y);
    }
}