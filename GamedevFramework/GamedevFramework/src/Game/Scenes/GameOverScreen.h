/***************************************************************************************
*	Title: GameOverScreen.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef GAME_OVER_SCREEN_H_
#define GAME_OVER_SCREEN_H_

#include "../../Framework/Scene/iScene.h"
#include "../../Framework/Renderer/Sprite/Sprite.h"
#include "../../Framework/EventManager/EventHandler.h"

class GameOverScreen  : public iScene, public EventHandler {
    private:
        Sprite* pBackground_;

    public:
        GameOverScreen();
        virtual ~GameOverScreen();

        virtual void load();
        virtual void init(void* pData);
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

#endif // GAME_OVER_SCREEN_H_
