/***************************************************************************************
*	Title: GameTask.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "GameTask.h"
#include "../Framework/EventManager/EventManager.h"
#include "Ids\EventIds.h"

GameTask::GameTask(const unsigned int priority) : Task(priority), state_(MAIN_MENU), pCurrentScene_(nullptr) {

}

GameTask::~GameTask() {
    if (pCurrentScene_) {
        disposeCurrentScene();
    }
}

bool GameTask::start() {
    registerEvent(game::ev::id::PLAY_BT_PRESSED);
    attachEvent(game::ev::id::PLAY_BT_PRESSED, *this);

    registerEvent(game::ev::id::BACK_TO_MAIN_MENU);
    attachEvent(game::ev::id::BACK_TO_MAIN_MENU, *this);

    registerEvent(game::ev::id::GAME_OVER_SCREEN);
    attachEvent(game::ev::id::GAME_OVER_SCREEN, *this);

    attachEvent(ev::id::PLATFORM_SUSPEND, *this);
    attachEvent(ev::id::PLATFORM_RESUME, *this);

    registerEvent(ev::id::UPDATE);
    registerEvent(ev::id::PRE_UPDATE);
    registerEvent(ev::id::POST_UPDATE);

    registerEvent(ev::id::ATTACH_SCENE_EVENTS);
    registerEvent(ev::id::DETACH_SCENE_EVENTS);

    initCurrentScene(nullptr);
    return true;
}

void GameTask::onSuspend() {
    setSuspended(true);
}

void GameTask::update() {
    if (isSuspended()) return;

    sendEvent(ev::id::PRE_UPDATE);

    assert(pCurrentScene_);
    pCurrentScene_->update();
    sendEvent(ev::id::UPDATE);

    sendEvent(ev::id::POST_UPDATE);
}

void GameTask::onResume() {
    setSuspended(false);
}

void GameTask::stop() {

}

void GameTask::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case game::ev::id::PLAY_BT_PRESSED:
            disposeCurrentScene();
            state_ = IN_GAME;
            initCurrentScene(pEvent->getData());
            break;
        case game::ev::id::BACK_TO_MAIN_MENU:
            disposeCurrentScene();
            state_ = MAIN_MENU;
            initCurrentScene(nullptr);
            break;
        case game::ev::id::GAME_OVER_SCREEN:
            disposeCurrentScene();
            state_ = GAME_OVER;
            initCurrentScene(nullptr);
            break;
        case ev::id::PLATFORM_SUSPEND:
            onSuspend();
            break;
        case ev::id::PLATFORM_RESUME:
            onResume();
            break;
        default:
            break;
    }
}

void GameTask::initCurrentScene(void* pData) {
    switch (state_) {
        case GameTask::MAIN_MENU:
            pCurrentScene_ = new MainMenu();
            break;
        case GameTask::IN_GAME:
            pCurrentScene_ = new InGame();
            break;
        case GameTask::GAME_OVER:
            pCurrentScene_ = new GameOverScreen();
            break;
        default:
            break;
    }

    pCurrentScene_->load();
    pCurrentScene_->init(pData);
}
void GameTask::disposeCurrentScene() {
    assert(pCurrentScene_);
    pCurrentScene_->unload();
    pCurrentScene_->dispose();
    delete pCurrentScene_;
    pCurrentScene_ = nullptr;
}