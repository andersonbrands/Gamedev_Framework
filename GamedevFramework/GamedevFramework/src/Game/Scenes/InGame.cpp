/***************************************************************************************
*	Title: InGame.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "InGame.h"
#include "../../Framework/Input/InputManager.h"
#include "../../Framework/EventManager/EventManager.h"
#include "../Ids/EventIds.h"

InGame::InGame() {

}

InGame::~InGame() {

}

void InGame::load() {

}

void InGame::init() {

}

void InGame::update() {
    auto pInput(InputManager::getInstancePtr());

    assert(pInput);

    if (pInput->getKeyboard()->onKeyUp(DIK_B)) {
        sendEvent(game::ev::id::BACK_TO_MAIN_MENU);
    }
}

void InGame::unload() {

}

void InGame::dispose() {

}