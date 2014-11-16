/***************************************************************************************
*	Title: InGame.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "InGame.h"
#include "../../Framework/Input/InputManager.h"
#include "../../Framework/EventManager/EventManager.h"
#include "../../Framework/Renderer/Renderer.h"
#include "../../Framework/Renderer/Texture/TextureManager.h"
#include "../Ids/EventIds.h"
#include "../Ids/TextureIds.h"

InGame::InGame() : iScene(), starDust_(200) {

}

InGame::~InGame() {

}

void InGame::load() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);
    // TODO: create a new texture for this scene
    Texture* pTexture = texManager->loadTexture(tex::MAIN_MENU_SPR_SHEET);
}

void InGame::init() {
    starDust_.init();

    attachEvent(ev::id::RENDER_EVENT, *this);
    attachEvent(ev::id::PRE_RENDER_EVENT, *this);
}

void InGame::update() {
    auto pInput(InputManager::getInstancePtr());

    assert(pInput);

    if (pInput->getKeyboard()->onKeyUp(DIK_B)) {
        sendEvent(game::ev::id::BACK_TO_MAIN_MENU);
        return;
    }

    starDust_.update();
}

void InGame::unload() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    texManager->unloadTexture(tex::MAIN_MENU_SPR_SHEET);

    detachEvent(ev::id::RENDER_EVENT, *this);
    detachEvent(ev::id::PRE_RENDER_EVENT, *this);
}

void InGame::dispose() {

}

void InGame::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::RENDER_EVENT: {
            starDust_.render();
            break;
        }
        case ev::id::PRE_RENDER_EVENT: {
            auto pRenderer = Renderer::getInstancePtr();
            assert(pRenderer);
            pRenderer->setupViewMatrix(Vector3(0.0f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f));
            pRenderer->setupLHOrthogonalProjectionMatrix(48.0f, 32.0f, -1.0f, 4.0f);
            break;
        }
        default:
            break;
    }

}