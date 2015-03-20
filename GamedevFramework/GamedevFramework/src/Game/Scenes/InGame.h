/***************************************************************************************
*	Title: InGame.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef IN_GAME_H_
#define IN_GAME_H_

#include "../../Framework/Scene/iScene.h"
#include "../GameObjects/StarDust.h"
#include "../GameObjects/Player/PlayerShip.h"
#include "../../Framework/EventManager/EventHandler.h"
#include "../GameObjects/Enemies/EnemyManager.h"

using namespace Framework;


class InGame : public iScene, public EventHandler {
    private:
        StarDust starDust_;
        PlayerShip playerShip_;
        EnemyManager enemyManager_;

    public:
        InGame();
        virtual ~InGame();

        virtual void load();
        virtual void init();
        virtual void update();
        virtual void unload();
        virtual void dispose();

        virtual void loadTextures();
        virtual void unloadTextures();

        virtual void addSprites();
        virtual void removeSprites();

        virtual void registerEvents();
        virtual void unregisterEvents();

        virtual void handleEvent(Event* pEvent);
};

#endif // IN_GAME_H_
