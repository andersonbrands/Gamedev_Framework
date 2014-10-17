/***************************************************************************************
*	Title: GameApplication.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "GameApplication.h"
#include "../Framework/EventManager/EventManager.h"
#include "../Framework/Platform/Platform.h"
#include "../Framework/Renderer/Renderer.h"

GameApplication::GameApplication(): Application() {

}

GameApplication::~GameApplication() {

}

bool GameApplication::initialize() {
    bool success(true);

    createSingletons();

    assert(Platform::getInstancePtr());
    kernel_.addTask(Platform::getInstancePtr());

    assert(Renderer::getInstancePtr());
    kernel_.addTask(Renderer::getInstancePtr());

    return success;
}

void GameApplication::createSingletons() {
    new EventManager();
    new Platform( Task::PLATFORM_PRIORITY );
    new Renderer( Task::RENDER_PRIORITY );
}
void GameApplication::destroySingletons() {
    assert(Renderer::getInstancePtr());
    delete Renderer::getInstancePtr();

    assert(Platform::getInstancePtr());
    delete Platform::getInstancePtr();

    assert(EventManager::getInstancePtr());
    delete EventManager::getInstancePtr();
}