/***************************************************************************************
*	Title: GameApplication.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "GameApplication.h"
#include "../Framework/EventManager/EventManager.h"

GameApplication::GameApplication(): Application() {

}

GameApplication::~GameApplication() {

}

bool GameApplication::initialize() {
    bool success(true);

    createSingletons();

    return success;
}

void GameApplication::createSingletons() {
    new EventManager();

}
void GameApplication::destroySingletons() {

    assert(EventManager::getInstancePtr());
    delete EventManager::getInstancePtr();
}