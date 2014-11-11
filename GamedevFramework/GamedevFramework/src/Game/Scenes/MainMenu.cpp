/***************************************************************************************
*	Title: MainMenu.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "MainMenu.h"
#include "../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Framework/Renderer/Texture/TextureManager.h"
#include "../../Framework/Renderer/Renderer.h"
#include "../../Framework/EventManager/EventManager.h"
#include "../../Framework/EventManager/EventId.h"
#include "../Ids/TextureIds.h"
#include "../Ids/SpriteIds.h"

MainMenu::MainMenu() {

}

MainMenu::~MainMenu() {

}

void MainMenu::load() {

}
void MainMenu::init() {
    attachEvent(ev::id::RENDER_EVENT, *this);
    attachEvent(ev::id::PRE_RENDER_EVENT, *this);
}
void MainMenu::update() {

}

void MainMenu::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::RENDER_EVENT: {

        }
        case ev::id::PRE_RENDER_EVENT: {

        }

        break;
    }
}

void MainMenu::unload() {

}
void MainMenu::dispose() {

}