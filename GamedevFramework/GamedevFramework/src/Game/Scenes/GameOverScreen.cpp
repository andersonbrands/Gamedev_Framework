/***************************************************************************************
*	Title: GameOverScreen.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "GameOverScreen.h"

#include "../../Framework/EventManager/EventManager.h"
#include "../../Framework/Input/InputManager.h"
#include "../Ids/EventIds.h"
#include "../Ids/TextureIds.h"
#include "../Ids/SpriteIds.h"
#include "../../Framework/Renderer/Renderer.h"
#include "../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Framework/Renderer/Texture/TextureManager.h"

GameOverScreen::GameOverScreen() : pBackground_(nullptr) {
    registerEvents();
    sendEvent(ev::id::ATTACH_SCENE_EVENTS);
}

GameOverScreen::~GameOverScreen() {
    sendEvent(ev::id::DETACH_SCENE_EVENTS);
    unregisterEvents();
}

void GameOverScreen::load() {
    loadTextures();

    addSprites();
}

void GameOverScreen::init(void* pData) {
    attachEvent(ev::id::RENDER_EVENT, *this);
    attachEvent(ev::id::PRE_RENDER_EVENT, *this);

    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

    // background
    pBackground_	= sprManager->getSprite(spr::GAME_OVER_BACKGROUND);
}

void GameOverScreen::loadTextures() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    Texture* pTexture = texManager->loadTexture(tex::GAME_OVER_SPR_SHEET);
}
void GameOverScreen::unloadTextures() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    texManager->unloadTexture(tex::GAME_OVER_SPR_SHEET);
}

void GameOverScreen::addSprites() {
    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

	sprManager->addSprite(spr::GAME_OVER_BACKGROUND);
}
void GameOverScreen::removeSprites() {
    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

	sprManager->removeSprite(spr::GAME_OVER_BACKGROUND);
}

void GameOverScreen::registerEvents() {

}
void GameOverScreen::unregisterEvents() {

}

void GameOverScreen::update() {
    auto pInput(InputManager::getInstancePtr());

    assert(pInput);

    game::ev::data::ReadOrWriteToFromFile readOrWrite;
    readOrWrite.setAll(false);

    if (pInput->getKeyboard()->onKeyUp(DIK_P)) {
        sendEvent(game::ev::id::PLAY_BT_PRESSED, nullptr);
    } else if(pInput->getKeyboard()->onKeyUp(DIK_R)) {
        readOrWrite.readFrom = true;
        sendEvent(game::ev::id::PLAY_BT_PRESSED, &readOrWrite);
    } else if(pInput->getKeyboard()->onKeyUp(DIK_W)) {
        readOrWrite.writeTo = true;
        sendEvent(game::ev::id::PLAY_BT_PRESSED, &readOrWrite);
    }
}

void GameOverScreen::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::RENDER_EVENT: {
            auto pRenderer = Renderer::getInstancePtr();
            assert(pRenderer);
            pRenderer->setTransform(Vector3(0.0f, 0.0f, 0.001f), Vector3(1.0f), Vector3(0.0f));
            pBackground_->render();
        }
        case ev::id::PRE_RENDER_EVENT: {
            auto pRenderer = Renderer::getInstancePtr();
            assert(pRenderer);
            pRenderer->setupViewMatrix(Vector3(0.0f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f));
            pRenderer->setupLHOrthogonalProjectionMatrix(48.0f, 32.0f, -1.0f, 4.0f);
        }

        break;
    }
}

void GameOverScreen::unload() {
    unloadTextures();

    removeSprites();

    detachEvent(ev::id::RENDER_EVENT, *this);
    detachEvent(ev::id::PRE_RENDER_EVENT, *this);
}

void GameOverScreen::dispose() {
}
