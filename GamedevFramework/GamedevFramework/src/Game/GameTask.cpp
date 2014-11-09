/***************************************************************************************
*	Title: GameTask.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "GameTask.h"

GameTask::GameTask(const unsigned int priority) : Task(priority), state_(MAIN_MENU), pMainMenu_(nullptr) {

}

GameTask::~GameTask() {
    if (pMainMenu_) {
        delete pMainMenu_;
        pMainMenu_ = nullptr;
    }
}

bool GameTask::start() {
    pMainMenu_ = new MainMenu();

    pMainMenu_->load();
    pMainMenu_->init();

    return true;
}

void GameTask::onSuspend() {
    setSuspended(true);
}

void GameTask::update() {
    if (isSuspended()) return;

    switch (state_) {
        case MAIN_MENU:
            break;
        case IN_GAME:
            break;
        default:
            break;
    }
}

void GameTask::onResume() {
    setSuspended(false);
}

void GameTask::stop() {

}
