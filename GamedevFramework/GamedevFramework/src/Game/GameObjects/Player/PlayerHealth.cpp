/***************************************************************************************
*	Title: PlayerHealth.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "PlayerHealth.h"
#include "../../../Framework/Renderer/Renderer.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/EventManager/Event.h"
#include "../../Ids/SpriteIds.h"
#include "../../Ids/EventIds.h"

PlayerHealth::PlayerHealth(int& health, const int& maxHealth) : health_(health), maxHealth_(maxHealth), green_(nullptr), grey_(nullptr) {

}

PlayerHealth::~PlayerHealth() {

}


void PlayerHealth::init() {
    green_ = SpriteManager::getInstancePtr()->getSprite(spr::HEALTH_GREEN);
    grey_ = SpriteManager::getInstancePtr()->getSprite(spr::HEALTH_GREY);
}
void PlayerHealth::render() const {
    auto pRenderer = Renderer::getInstancePtr();
    assert(pRenderer);

    Transform tr;
    tr.setTranslation(Vector3(15.0f, -15.0f, -0.21f));
    pRenderer->setTransform(tr);
    grey_->render();
    float scaleX(health_/(float)maxHealth_);
    tr.setScale(Vector3(scaleX, 1.0f, 1.0f));
    pRenderer->setTransform(tr);
    green_->render();
}
void PlayerHealth::handleEvent(Event* pEvent) {

}