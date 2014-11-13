/***************************************************************************************
*	Title: InGame.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef IN_GAME_H_
#define IN_GAME_H_

#include "../../Framework/Scene/iScene.h"

using namespace Framework;

class InGame : public iScene {
    private:
    public:
        InGame();
        virtual ~InGame();

        virtual void load();
        virtual void init();
        virtual void update();
        virtual void unload();
        virtual void dispose();
};

#endif // IN_GAME_H_
