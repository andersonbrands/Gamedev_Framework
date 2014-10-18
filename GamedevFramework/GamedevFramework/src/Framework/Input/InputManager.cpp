/***************************************************************************************
*	Title: InputManager.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "InputManager.h"

namespace Framework {

    InputManager::InputManager(const unsigned int priority) : Task(priority), pKeyboard_(nullptr) {

    }

    InputManager::~InputManager() {
        if (pKeyboard_) {
            delete pKeyboard_;
            pKeyboard_ = nullptr;
        }
    }

    bool InputManager::requestKeyboard() {
        if (pKeyboard_) {
            return false;
        } else {
            pKeyboard_ = new Keyboard();
            return true;
        }
    }

    bool InputManager::start() {

        return 1;
    }

    void InputManager::onSuspend() {

    }

    void InputManager::update() {
        if (isSuspended())
            return;

        if (pKeyboard_) {
            pKeyboard_->update();
        }
    }

    void InputManager::onResume() {

    }

    void InputManager::stop() {

    }



}