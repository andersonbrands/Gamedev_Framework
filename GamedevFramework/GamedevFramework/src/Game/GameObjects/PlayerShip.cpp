/***************************************************************************************
*	Title: PlayerShip.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "PlayerShip.h"
#include "../../Framework/Input/InputManager.h"
#include "../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Framework/EventManager/EventManager.h"
#include "../../Framework/Renderer/Renderer.h"
#include "../Ids/EventIds.h"
#include "../Ids/SpriteIds.h"
#include "../Ids/TextureIds.h"
#include "Components\PlayerShipMovement.h"

int PlayerShip::MAX_HP = 100;

PlayerShip::PlayerShip() {
    assert(addComponent<PlayerShipMovement>());
}

PlayerShip::~PlayerShip() {
    detachEvent(ev::id::PRE_UPDATE, *this);
    detachEvent(ev::id::RENDER_EVENT, *this);
}

void PlayerShip::init() {
    pSprite_ = SpriteManager::getInstancePtr()->addSprite(spr::PLAYER_SHIP_SPRITE);
    assert(pSprite_);

    pSprite_->setup(Vector3(0.0f, 0.0566f, 2.9f), Vector3(0.0f, 0.0468f, 2.4f), tex::IN_GAME_SPR_SHEET.id, SpriteAlign::CENTER);

    auto tr(component_cast<TransformComponent>(this));
    tr->setTranslation(Vector3(0.0f, -13.5f, -0.1f));

    auto move(component_cast<PlayerShipMovement>(this));
    move->setMaxSpeed(15.0f);

    attachEvent(ev::id::PRE_UPDATE, *this);
    attachEvent(ev::id::RENDER_EVENT, *this);
}

int PlayerShip::getMaxHp() {
    return MAX_HP;
}

void PlayerShip::update() {

}

void PlayerShip::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::RENDER_EVENT: {
            auto pRenderer = Renderer::getInstancePtr();
            assert(pRenderer);
            pRenderer->setTransform(*static_cast<Transform*>(component_cast<TransformComponent>(this)));

            pSprite_->render();
            break;
        }
        case ev::id::PRE_UPDATE: {
            auto pInput(InputManager::getInstancePtr());
            assert(pInput);

            auto pMove(component_cast<MovementComponent>(this));

            if (pInput->getKeyboard()->isKeyDown(DIK_RIGHTARROW)) {
                pMove->accelerate(Direction::RIGHT, 3.0f);
            }
            if (pInput->getKeyboard()->isKeyDown(DIK_LEFTARROW)) {
                pMove->accelerate(Direction::LEFT, 3.0f);
            }
        }
        break;
        default:
            break;
    }
}
