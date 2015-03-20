/***************************************************************************************
*	Title: EnemyShip.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef ENEMY_SHIP_H_
#define ENEMY_SHIP_H_

#include "../Ship.h"
#include "EnemyBullet.h"
#include "../BulletManager.h"

#include "../../../Framework/Utilities/Utils.h"

class EnemyShip : public Ship {
    private:

    public:
        EnemyShip();
        virtual ~EnemyShip();

        virtual void	init() = 0;
        virtual int		getMaxHp() = 0;
        virtual void	update() = 0;
        virtual void	spawn(float x, float y) = 0;
        virtual void	reset() = 0;

        void tryToShoot();

        virtual void	handleEvent(Event* pEvent);
};

#endif // ENEMY_SHIP_H_
