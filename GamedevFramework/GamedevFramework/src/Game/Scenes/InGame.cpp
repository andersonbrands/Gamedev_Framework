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
#include "../../Framework/Collision/CollisionManager.h"
#include "../Ids/EventIds.h"
#include "../Ids/TextureIds.h"
#include "../Ids/SpriteIds.h"

InGame::InGame() : iScene(), starDust_(200), playerShip_(), enemyManager_() {
    registerEvents();
    sendEvent(ev::id::ATTACH_SCENE_EVENTS);
}

InGame::~InGame() {
    sendEvent(ev::id::DETACH_SCENE_EVENTS);
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


void InGame::init(void* pData) {
    auto colManager = CollisionManager::getInstancePtr();

    starDust_.init();


    colManager->addCollisionGroup(2); // add player bullet collision group

    // TODO: check pData read from file or write to file
    game::ev::data::ReadOrWriteToFromFile* pReadOrWrite =
        static_cast<game::ev::data::ReadOrWriteToFromFile*>(pData);

    if (pReadOrWrite) {
        if (pReadOrWrite->readFrom) {
            playerShip_.initReadingFromFile();
        } else if (pReadOrWrite->writeTo) {
            playerShip_.initWritingToFile();
        }
    } else {
        playerShip_.init();
    }
    colManager->addCollisionGroup(1); // add player collision group
    colManager->addObjectToGroup(1, &playerShip_);

    colManager->addCollisionGroup(3); // add enemy bullets collision group
    colManager->addCollisionGroup(0); // add enemies collision group
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


    auto colManager = CollisionManager::getInstancePtr();
    colManager->testAgainstGroup(0, &playerShip_);
    colManager->testAgainstGroup(3, &playerShip_);
    colManager->testGroups(0, 2);
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
    registerEvent(game::ev::id::PS_MV_LEFT);
    registerEvent(game::ev::id::PS_MV_UP);
    registerEvent(game::ev::id::PS_MV_RIGHT);
    registerEvent(game::ev::id::PS_MV_DOWN);
    registerEvent(game::ev::id::PS_SHOOT);
}
void InGame::unregisterEvents() {
    unregisterEvent(game::ev::id::SPAWN_ENEMY_BULLET);

    unregisterEvent(game::ev::id::PS_MV_LEFT);
    unregisterEvent(game::ev::id::PS_MV_UP);
    unregisterEvent(game::ev::id::PS_MV_RIGHT);
    unregisterEvent(game::ev::id::PS_MV_DOWN);
    unregisterEvent(game::ev::id::PS_SHOOT);
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