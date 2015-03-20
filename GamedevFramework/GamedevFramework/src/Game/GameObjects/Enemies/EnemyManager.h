/***************************************************************************************
*	Title: EnemyManager.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef ENEMY_MANAGER_H_
#define ENEMY_MANAGER_H_

#include "EnemyAShip.h"
#include "EnemyBShip.h"
#include "EnemyCShip.h"

#include "EnemyBulletManager.h"

#include "../../../Framework/EventManager/EventHandler.h"

using namespace Framework;

class EnemyManager : public EventHandler {
    private:
        EnemyAShip		enemyA_[5];
        EnemyBShip		enemyB_[3];
        EnemyCShip		enemyC_[5];

        EnemyBulletManager bulletManager_;

        bool			readyToSpawn_;
        bool			paused_;

        bool		areAllEnemiesGone() const;

    public:
        EnemyManager();
        virtual ~EnemyManager();

        void		spawnEnemies();
        void		init();
        void		update();

        virtual void handleEvent(Event* pEvent);

        bool		isPaused() const {
            return paused_;
        }
        void		setPaused(bool paused) {
            paused_ = paused;
        }
};

#endif // ENEMY_MANAGER_H_
