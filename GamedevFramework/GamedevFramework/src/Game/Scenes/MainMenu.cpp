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
#include "../Ids/EventIds.h"
#include "../../Framework/Input/InputManager.h"
#include "../../Framework/GameObjects/Components/TransformComponent.h"
#include "../../Framework/GameObjects/Components/SpriteComponent.h"
#include "../../Framework/GameObjects/Components/ColliderComponent.h"


MainMenu::MainMenu() : pBackground_(nullptr), pGameName_(nullptr), pPlayBt_(nullptr), pSettingBt_(nullptr) {
    registerEvents();
    sendEvent(ev::id::ATTACH_SCENE_EVENTS);
}

MainMenu::~MainMenu() {
    sendEvent(ev::id::DETACH_SCENE_EVENTS);
    unregisterEvents();
}

void MainMenu::load() {
    loadTextures();

    addSprites();
}
void MainMenu::init(void* pData) {
    attachEvent(ev::id::RENDER_EVENT, *this);
    attachEvent(ev::id::PRE_RENDER_EVENT, *this);

    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

    // init playBt
    pPlayBt_ = new GameObject;
    assert(pPlayBt_->addComponent<TransformComponent>());
    TransformComponent* tr(component_cast<TransformComponent>(pPlayBt_));
    tr->setTranslation(Vector3(0.0f, 0.0f, 0.0f));
    tr->setRotation(Vector3(0.0f));
    tr->setScale(Vector3(1.0f));
    assert(pPlayBt_->addComponent<SpriteComponent>());
    component_cast<SpriteComponent>(pPlayBt_)->setSprite(sprManager->getSprite(spr::MAIN_MENU_PLAY_BT));
    //assert(pPlayBt_->addComponent<ColliderComponent>());
    pPlayBt_->setActive(false);


    // init settingBt
    pSettingBt_ = new GameObject;
    assert(pSettingBt_->addComponent<TransformComponent>());
    tr = component_cast<TransformComponent>(pSettingBt_);
    tr->setTranslation(Vector3(0.0f, -3.4f, 0.0f));
    tr->setRotation(Vector3(0.0f));
    tr->setScale(Vector3(1.0f));
    assert(pSettingBt_->addComponent<SpriteComponent>());
    component_cast<SpriteComponent>(pSettingBt_)->setSprite(sprManager->getSprite(spr::MAIN_MENU_SETTINGS_BT));
    //assert(pSettingBt_->addComponent<ColliderComponent>());
    pSettingBt_->setActive(false);

    // background
    pBackground_	= sprManager->getSprite(spr::MAIN_MENU_BACKGROUND);

    // game name
    pGameName_		= sprManager->getSprite(spr::MAIN_MENU_GAME_NAME);

}


void MainMenu::loadTextures() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    Texture* pTexture = texManager->loadTexture(tex::MAIN_MENU_SPR_SHEET);
}
void MainMenu::unloadTextures() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    texManager->unloadTexture(tex::MAIN_MENU_SPR_SHEET);
}

void MainMenu::addSprites() {
    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

    sprManager->addSprite(spr::MAIN_MENU_BACKGROUND);
    sprManager->addSprite(spr::MAIN_MENU_GAME_NAME);
    sprManager->addSprite(spr::MAIN_MENU_PLAY_BT);
    sprManager->addSprite(spr::MAIN_MENU_SETTINGS_BT);
}
void MainMenu::removeSprites() {
    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

    sprManager->removeSprite(spr::MAIN_MENU_BACKGROUND);
    sprManager->removeSprite(spr::MAIN_MENU_GAME_NAME);
    sprManager->removeSprite(spr::MAIN_MENU_PLAY_BT);
    sprManager->removeSprite(spr::MAIN_MENU_SETTINGS_BT);
}

void MainMenu::registerEvents() {

}
void MainMenu::unregisterEvents() {

}


void MainMenu::update() {
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

void MainMenu::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::RENDER_EVENT: {
            auto pRenderer = Renderer::getInstancePtr();
            assert(pRenderer);
            pRenderer->setTransform(Vector3(0.0f, 0.0f, 0.001f), Vector3(1.0f), Vector3(0.0f));
            pBackground_->render();
            pRenderer->setTransform(Vector3(0.0f, 15.0f, 0.0f), Vector3(1.0f), Vector3(0.0f));
            //pGameName_->render();
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

void MainMenu::unload() {
    unloadTextures();

    removeSprites();

    detachEvent(ev::id::RENDER_EVENT, *this);
    detachEvent(ev::id::PRE_RENDER_EVENT, *this);
}
void MainMenu::dispose() {
    if (pPlayBt_) {
        delete pPlayBt_;
        pPlayBt_ = nullptr;
    }

    if (pSettingBt_) {
        delete pSettingBt_;
        pSettingBt_ = nullptr;
    }
}