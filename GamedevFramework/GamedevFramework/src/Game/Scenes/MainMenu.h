/***************************************************************************************
*	Title: MainMenu.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "../../Framework/Scene/iScene.h"
#include "../../Framework/Renderer/Sprite/Sprite.h"
#include "../../Framework/EventManager/EventHandler.h"

using namespace Framework;

class MainMenu : public iScene, public EventHandler {
    private:
        Sprite* pBackground_;
        Sprite* pGameName_;

    public:
        MainMenu();
        virtual ~MainMenu();

        virtual void load();
        virtual void init();
        virtual void update();
        virtual void unload();
        virtual void dispose();

        virtual void handleEvent(Event* pEvent);
};

#endif // MAIN_MENU_H_
