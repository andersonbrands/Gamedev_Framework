/***************************************************************************************
*	Title: PlayerBulletManager.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef PLAYER_BULLET_MANAGER_H_
#define PLAYER_BULLET_MANAGER_H_

#include "../../../Framework/Utilities/PoolAllocator.h"
#include "PlayerBullet.h"

using namespace Framework;

class PlayerBulletManager : public PoolAllocator<PlayerBullet> {
    private:
    public:
        PlayerBulletManager(int totalObjects);
        virtual ~PlayerBulletManager();

        void spawnBullet(float x, float y);
};

#endif // PLAYER_BULLET_MANAGER_H_
