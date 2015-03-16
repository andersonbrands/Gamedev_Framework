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

}

MainMenu::~MainMenu() {

}

void MainMenu::load() {
    pPlayBt_ = new GameObject;
	pPlayBt_->setActive(true);
    assert(pPlayBt_->addComponent<TransformComponent>());
    TransformComponent* tr(component_cast<TransformComponent>(pPlayBt_));
    tr->setTranslation(Vector3(0.0f, 0.0f, 0.0f));
    tr->setRotation(Vector3(0.0f));
    tr->setScale(Vector3(1.0f));
    assert(pPlayBt_->addComponent<SpriteComponent>());
    //assert(pPlayBt_->addComponent<ColliderComponent>());

    pSettingBt_ = new GameObject;
	pSettingBt_->setActive(true);
    assert(pSettingBt_->addComponent<TransformComponent>());
    tr = component_cast<TransformComponent>(pSettingBt_);
    tr->setTranslation(Vector3(0.0f, -3.4f, 0.0f));
    tr->setRotation(Vector3(0.0f));
    tr->setScale(Vector3(1.0f));
    assert(pSettingBt_->addComponent<SpriteComponent>());
    //assert(pSettingBt_->addComponent<ColliderComponent>());


    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    Texture* pTexture = texManager->loadTexture(tex::MAIN_MENU_SPR_SHEET);

    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

    pBackground_	= sprManager->addSprite(spr::MAIN_MENU_BACKGROUND);
    pBackground_->setup(Vector3(0.0f, 0.937f, 48.0f), Vector3(0.0f, 0.625f, 32.0f), tex::MAIN_MENU_SPR_SHEET.id, SpriteAlign::CENTER);

    pGameName_		= sprManager->addSprite(spr::MAIN_MENU_GAME_NAME);
    pGameName_->setup(Vector3(0.0f, 0.468f, 24.0f), Vector3(0.625f, 0.781f, 8.0f), tex::MAIN_MENU_SPR_SHEET.id, SpriteAlign::CENTER_TOP);

    Sprite* pPlaySprite		= sprManager->addSprite(spr::MAIN_MENU_PLAY_BT);
    pPlaySprite->setup(Vector3(0.0f, 0.195f, 10.0f), Vector3(0.781f, 0.843f, 3.2f), tex::MAIN_MENU_SPR_SHEET.id, SpriteAlign::CENTER);
    component_cast<SpriteComponent>(pPlayBt_)->setSprite(pPlaySprite);

    Sprite* pSettingSprite		= sprManager->addSprite(spr::MAIN_MENU_SETTINGS_BT);
    pSettingSprite->setup(Vector3(0.0f, 0.195f, 10.0f), Vector3(0.843f, 0.906f, 3.2f), tex::MAIN_MENU_SPR_SHEET.id, SpriteAlign::CENTER_TOP);
    component_cast<SpriteComponent>(pSettingBt_)->setSprite(pSettingSprite);
}
void MainMenu::init() {
    attachEvent(ev::id::RENDER_EVENT, *this);
    attachEvent(ev::id::PRE_RENDER_EVENT, *this);

}
void MainMenu::update() {
    auto pInput(InputManager::getInstancePtr());

    assert(pInput);

    if (pInput->getKeyboard()->onKeyUp(DIK_P)) {
        sendEvent(game::ev::id::PLAY_BT_PRESSED);
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
            pGameName_->render();
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
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    texManager->unloadTexture(tex::MAIN_MENU_SPR_SHEET);

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