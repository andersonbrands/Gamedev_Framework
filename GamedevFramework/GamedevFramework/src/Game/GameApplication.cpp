/***************************************************************************************
*	Title: GameApplication.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "GameApplication.h"

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

}
void GameApplication::destroySingletons() {

}