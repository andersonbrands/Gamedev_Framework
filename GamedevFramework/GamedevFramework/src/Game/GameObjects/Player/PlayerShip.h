/***************************************************************************************
*	Title: PlayerShip.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef PLAYER_SHIP_H_
#define PLAYER_SHIP_H_

#include "../Ship.h"
#include "../BulletManager.h"
#include "PlayerBullet.h"

using namespace Framework;

class PlayerShip : public Ship {
    private:
        static int MAX_HP;
        BulletManager<PlayerBullet> bulletManager_;

    public:
        PlayerShip();
        virtual ~PlayerShip();
        virtual void init();
        virtual int getMaxHp();
        void update();

        virtual void handleEvent(Event* pEvent);
};

#endif // PLAYER_SHIP_H_
