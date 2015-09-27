/***************************************************************************************
*	Title: GameTask.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef GAME_TASK_H_
#define GAME_TASK_H_

#include "../Framework/Kernel/Task.h"
#include "Scenes\MainMenu.h"
#include "Scenes\InGame.h"
#include "../Framework/EventManager/EventHandler.h"

using namespace Framework;

class GameTask : public Task, public EventHandler {
        enum GameState {
            MAIN_MENU,
            IN_GAME
        };
    private:
        GameState state_;

        iScene* pCurrentScene_;
        void initCurrentScene(void* pData);
        void disposeCurrentScene();

    public:
        GameTask(const unsigned int priority);
        virtual ~GameTask();

        virtual bool	start();
        virtual void 	onSuspend();
        virtual void 	update();
        virtual void 	onResume();
        virtual void 	stop();

        virtual void handleEvent(Event* pEvent);
};

#endif // GAME_TASK_H_
