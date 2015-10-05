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
#include "../../FileManagement/GameInputFile.h"
#include "PlayerScore.h"

using namespace Framework;

class PlayerShip : public Ship {
    private:
        static int MAX_HP;
        BulletManager<PlayerBullet> bulletManager_;
        GameInputFile* pGameInput_;
        PlayerScore playerScore_;

    public:
        PlayerShip();
        virtual ~PlayerShip();
        virtual void init();
        void initReadingFromFile();
        void initWritingToFile();
        virtual int getMaxHp();
        void update();

        virtual void handleEvent(Event* pEvent);
};

#endif // PLAYER_SHIP_H_
