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

    initCurrentScene();
    return true;
}

void GameTask::onSuspend() {
    setSuspended(true);
}

void GameTask::update() {
    if (isSuspended()) return;
    assert(pCurrentScene_);
    pCurrentScene_->update();

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
            initCurrentScene();
            break;
        case game::ev::id::BACK_TO_MAIN_MENU:
            disposeCurrentScene();
            state_ = MAIN_MENU;
            initCurrentScene();
            break;
        default:
            break;
    }
}

void GameTask::initCurrentScene() {
    switch (state_) {
        case GameTask::MAIN_MENU:
            pCurrentScene_ = new MainMenu();
            break;
        case GameTask::IN_GAME:
            pCurrentScene_ = new InGame();
            break;
        default:
            break;
    }

    pCurrentScene_->load();
    pCurrentScene_->init();
}
void GameTask::disposeCurrentScene() {
    assert(pCurrentScene_);
    pCurrentScene_->unload();
    pCurrentScene_->dispose();
    delete pCurrentScene_;
    pCurrentScene_ = nullptr;
}