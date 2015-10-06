/***************************************************************************************
*	Title: PlayerShip.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "PlayerShip.h"
#include "../../../Framework/Input/InputManager.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/Renderer/Renderer.h"
#include "../../Ids/EventIds.h"
#include "../../Ids/SpriteIds.h"
#include "../../Ids/TextureIds.h"
#include "../Components\PlayerShipMovement.h"
#include "../../../Framework/GameObjects/Components/ColliderComponent.h"
#include "../../../Framework/Collision/Colliders/SphereCollider.h"

int PlayerShip::MAX_HP = 100;

PlayerShip::PlayerShip() : bulletManager_(20), pGameInput_(nullptr), playerScore_() {
    assert(addComponent<PlayerShipMovement>());
    assert(addComponent<ColliderComponent>());

    attachEvent(ev::id::ATTACH_SCENE_EVENTS, *this);
    attachEvent(ev::id::DETACH_SCENE_EVENTS, *this);
}

PlayerShip::~PlayerShip() {
    detachEvent(ev::id::PRE_UPDATE, *this);
    detachEvent(ev::id::RENDER_EVENT, *this);

    detachEvent(ev::id::DETACH_SCENE_EVENTS, *this);
    detachEvent(ev::id::ATTACH_SCENE_EVENTS, *this);

    if (pGameInput_) {
        delete pGameInput_;
        pGameInput_ = nullptr;
    }
}

void PlayerShip::init() {
    bulletManager_.init();
    setActive(true);

    pSprite_ = SpriteManager::getInstancePtr()->getSprite(spr::PLAYER_SHIP_SPRITE);

    auto tr(component_cast<TransformComponent>(this));
    tr->setTranslation(Vector3(0.0f, -13.5f, -0.1f));

    auto col(component_cast<ColliderComponent>(this));
    col->setCollider(new SphereCollider(tr, 2.6f/3.5f));

    // init player score
    playerScore_.init();

    attachEvent(ev::id::PRE_UPDATE, *this);
    attachEvent(ev::id::RENDER_EVENT, *this);
}

void PlayerShip::initReadingFromFile() {
    init();

    if (pGameInput_) return;

    pGameInput_ = new GameInputFile();
    pGameInput_->openReadMode();
}
void PlayerShip::initWritingToFile() {
    init();

    if (pGameInput_) return;

    pGameInput_ = new GameInputFile();
    pGameInput_->openWriteMode();
}

int PlayerShip::getMaxHp() {
    return MAX_HP;
}

void PlayerShip::update() {

}

void PlayerShip::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::ATTACH_SCENE_EVENTS : {
            attachEvent(game::ev::id::PS_MV_LEFT, *this);
            attachEvent(game::ev::id::PS_MV_UP, *this);
            attachEvent(game::ev::id::PS_MV_RIGHT, *this);
            attachEvent(game::ev::id::PS_MV_DOWN, *this);
            attachEvent(game::ev::id::PS_SHOOT, *this);
            attachEvent(game::ev::id::ENEMY_DESTROYED, playerScore_);
            break;
        }
        case ev::id::DETACH_SCENE_EVENTS : {
            detachEvent(game::ev::id::PS_MV_LEFT, *this);
            detachEvent(game::ev::id::PS_MV_UP, *this);
            detachEvent(game::ev::id::PS_MV_RIGHT, *this);
            detachEvent(game::ev::id::PS_MV_DOWN, *this);
            detachEvent(game::ev::id::PS_SHOOT, *this);
            detachEvent(game::ev::id::ENEMY_DESTROYED, playerScore_);
            break;
        }
        case ev::id::RENDER_EVENT: {
            auto pRenderer = Renderer::getInstancePtr();
            assert(pRenderer);
            pRenderer->setTransform(*static_cast<Transform*>(component_cast<TransformComponent>(this)));

            pSprite_->render();

            playerScore_.render();
            break;
        }
        case ev::id::PRE_UPDATE: {
            auto pInput(InputManager::getInstancePtr());
            assert(pInput);

            game::ev::data::PlayerInputData inputData;
            inputData.setAll(false);

            auto pMove(component_cast<MovementComponent>(this));

            if (pInput->getKeyboard()->isKeyDown(DIK_RIGHTARROW)) {
                inputData.right = true;
                sendEvent(game::ev::id::PS_MV_RIGHT);
            }
            if (pInput->getKeyboard()->isKeyDown(DIK_LEFTARROW)) {
                inputData.left = true;
                sendEvent(game::ev::id::PS_MV_LEFT);
            }

            if (pInput->getKeyboard()->isKeyDown(DIK_UPARROW)) {
                inputData.up = true;
                sendEvent(game::ev::id::PS_MV_UP);
            }
            if (pInput->getKeyboard()->isKeyDown(DIK_DOWNARROW)) {
                inputData.down = true;
                sendEvent(game::ev::id::PS_MV_DOWN);
            }

            // TODO: make it a timed event??
            if (pInput->getKeyboard()->onKeyDown(DIK_SPACE)) {
                inputData.shoot = true;
                sendEvent(game::ev::id::PS_SHOOT);
            }

            if (pGameInput_) {
                if (pGameInput_->isReadMode()) {
                    pGameInput_->readSingleEntry();
                } else if (pGameInput_->isWriteMode()) {
                    pGameInput_->writeSingleEntry(inputData);
                }
            }

        }
        break;
        case game::ev::id::PS_MV_LEFT: {
            auto pMove(component_cast<MovementComponent>(this));
            pMove->accelerate(Direction::LEFT, 3.0f);
        }
        break;
        case game::ev::id::PS_MV_UP: {
            auto pMove(component_cast<MovementComponent>(this));
            pMove->accelerate(Direction::UP, 3.0f);
        }
        break;
        case game::ev::id::PS_MV_RIGHT: {
            auto pMove(component_cast<MovementComponent>(this));
            pMove->accelerate(Direction::RIGHT, 3.0f);
        }
        break;
        case game::ev::id::PS_MV_DOWN: {
            auto pMove(component_cast<MovementComponent>(this));
            pMove->accelerate(Direction::DOWN, 3.0f);
        }
        break;
        case game::ev::id::PS_SHOOT: {
            auto tr(component_cast<TransformComponent>(this)->getTranslation());
            bulletManager_.spawnBullet(tr.getX(), tr.getY());
        }
        break;
        default:
            break;
    }
}
