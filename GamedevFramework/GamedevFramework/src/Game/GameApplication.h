/***************************************************************************************
*	Title: GameApplication.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef GAME_APPLICATION_H_
#define GAME_APPLICATION_H_

#include "../Framework\Application\Application.h"

using namespace Framework;

class GameApplication : public Application {
    private:

    protected:
        virtual void createSingletons();
        virtual void destroySingletons();

    public:
        explicit GameApplication();
        virtual ~GameApplication();

        virtual bool	initialize();
};

#endif // GAME_APPLICATION_H_
