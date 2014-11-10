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

MainMenu::MainMenu() : pBackground_(nullptr), pGameName_(nullptr), pPlayBt_(nullptr), pSettingBt_(nullptr) {

}

MainMenu::~MainMenu() {

}

void MainMenu::load() {
    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);

    Texture* pTexture = texManager->loadTexture(tex::MAIN_MENU_SPR_SHEET);

    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);

    pBackground_	= sprManager->addSprite(spr::MAIN_MENU_BACKGROUND);
    pBackground_->setUVCoords(0.0f, 0.937f, 0.0f, 0.625f);
    pBackground_->setup(pTexture, SpriteAlign::CENTER, 32.0f, 48.0f);

    pGameName_		= sprManager->addSprite(spr::MAIN_MENU_GAME_NAME);
    pGameName_->setUVCoords(0.0f, 0.468f, 0.625f, 0.781f);
    pGameName_->setup(pTexture, SpriteAlign::CENTER_TOP, 8.0f, 24.0f);

    pPlayBt_		= sprManager->addSprite(spr::MAIN_MENU_PLAY_BT);
    pPlayBt_->setUVCoords(0.0f, 0.195f, 0.781f, 0.843f);
    pPlayBt_->setup(pTexture, SpriteAlign::CENTER, 3.2f, 10.0f);

    pSettingBt_		= sprManager->addSprite(spr::MAIN_MENU_SETTINGS_BT);
    pSettingBt_->setUVCoords(0.0f, 0.195f, 0.843f, 0.906f);
    pSettingBt_->setup(pTexture, SpriteAlign::CENTER_TOP, 3.2f, 10.0f);
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
            auto pRenderer = Renderer::getInstancePtr();
            assert(pRenderer);
            pRenderer->setTransform(Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f), Vector3(0.0f));
            pBackground_->render();
            pRenderer->setTransform(Vector3(0.0f, 15.0f, 0.0f), Vector3(1.0f), Vector3(0.0f));
            pGameName_->render();
            pRenderer->setTransform(Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f), Vector3(0.0f));
            pPlayBt_->render();
            pRenderer->setTransform(Vector3(0.0f, -3.4f, 0.0f), Vector3(1.0f), Vector3(0.0f));
            pSettingBt_->render();
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
}
void MainMenu::dispose() {

}