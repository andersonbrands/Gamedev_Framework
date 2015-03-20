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
#include "../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../Ids/EventIds.h"
#include "../Ids/TextureIds.h"
#include "../Ids/SpriteIds.h"

InGame::InGame() : iScene(), starDust_(200), playerShip_(), enemyManager_() {
    registerEvents();
}

InGame::~InGame() {
    unregisterEvents();
}

void InGame::load() {
    loadTextures();

    addSprites();
}

void InGame::unload() {
    unloadTextures();

    removeSprites();

    detachEvent(ev::id::RENDER_EVENT, *this);
    detachEvent(ev::id::PRE_RENDER_EVENT, *this);
}


void InGame::init() {
    starDust_.init();

    playerShip_.init();

    enemyManager_.init();

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


void InGame::dispose() {

}

void InGame::loadTextures() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    Texture* pTexture = texManager->loadTexture(tex::IN_GAME_SPR_SHEET);
}

void InGame::unloadTextures() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    texManager->unloadTexture(tex::IN_GAME_SPR_SHEET);
}

void InGame::addSprites() {
    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

    sprManager->addSprite(spr::STAR_SPRITE);
    sprManager->addSprite(spr::PLAYER_SHIP_SPRITE);
    sprManager->addSprite(spr::ENEMY_A_SHIP_SPRITE);
    sprManager->addSprite(spr::PLAYER_BULLET_SPRITE);
    sprManager->addSprite(spr::ENEMY_BULLET_SPRITE);
}

void InGame::removeSprites() {
    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

    sprManager->removeSprite(spr::STAR_SPRITE);
    sprManager->removeSprite(spr::PLAYER_SHIP_SPRITE);
    sprManager->removeSprite(spr::ENEMY_A_SHIP_SPRITE);
    sprManager->removeSprite(spr::PLAYER_BULLET_SPRITE);
    sprManager->removeSprite(spr::ENEMY_BULLET_SPRITE);
}

void InGame::registerEvents() {
    registerEvent(game::ev::id::SPAWN_ENEMY_BULLET);
}
void InGame::unregisterEvents() {
    unregisterEvent(game::ev::id::SPAWN_ENEMY_BULLET);
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