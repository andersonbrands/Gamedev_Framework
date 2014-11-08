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
#include "../Framework/Utilities/Timer.h"
#include "../Framework/Input/InputManager.h"
#include "../Framework/Renderer/Texture/TextureManager.h"
#include "../Framework/Renderer/Sprite/SpriteManager.h"

GameApplication::GameApplication(): Application(), pGameTask_(nullptr) {

}

GameApplication::~GameApplication() {
    if (pGameTask_) {
        delete pGameTask_;
        pGameTask_ = nullptr;
    }
}

bool GameApplication::initialize() {
    bool success(true);

    createSingletons();

    assert(Timer::getInstancePtr());
    kernel_.addTask(Timer::getInstancePtr());

    assert(Platform::getInstancePtr());
    kernel_.addTask(Platform::getInstancePtr());

    assert(InputManager::getInstancePtr());
    kernel_.addTask(InputManager::getInstancePtr());
    assert(InputManager::getInstancePtr()->requestKeyboard());

    assert(Renderer::getInstancePtr());
    kernel_.addTask(Renderer::getInstancePtr());

    pGameTask_ = new GameTask(Task::GAME_PRIORITY);
    kernel_.addTask(pGameTask_);

    return success;
}

void GameApplication::createSingletons() {
    new EventManager();
    new Timer ( Task::TIMER_PRIORITY );
    new Platform( Task::PLATFORM_PRIORITY );
    new InputManager( Task::INPUT_PRIORITY );
    new Renderer( Task::RENDER_PRIORITY );
    new TextureManager("data/textures/");
    new SpriteManager();
}
void GameApplication::destroySingletons() {
    assert(SpriteManager::getInstancePtr());
    delete SpriteManager::getInstancePtr();

    assert(TextureManager::getInstancePtr());
    delete TextureManager::getInstancePtr();

    assert(Renderer::getInstancePtr());
    delete Renderer::getInstancePtr();

    assert(InputManager::getInstancePtr());
    delete InputManager::getInstancePtr();

    assert(Platform::getInstancePtr());
    delete Platform::getInstancePtr();

    assert(Timer::getInstancePtr());
    delete Timer::getInstancePtr();

    assert(EventManager::getInstancePtr());
    delete EventManager::getInstancePtr();
}