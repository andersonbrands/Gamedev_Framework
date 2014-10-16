/***************************************************************************************
*	Title: GameApplication.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "GameApplication.h"
#include "../Framework/EventManager/EventManager.h"
#include "../Framework/Platform/Platform.h"

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
    new Platform( Task::PLATFORM_PRIORITY );
}
void GameApplication::destroySingletons() {

    assert(Platform::getInstancePtr());
    delete Platform::getInstancePtr();

    assert(EventManager::getInstancePtr());
    delete EventManager::getInstancePtr();
}