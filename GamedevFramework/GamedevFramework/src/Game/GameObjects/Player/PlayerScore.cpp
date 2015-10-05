/***************************************************************************************
*	Title: PlayerScore.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "PlayerScore.h"
#include "../../../Framework/Renderer/Renderer.h"
#include "../../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Ids/SpriteIds.h"
#include <cmath>

PlayerScore::PlayerScore() : score_(0), label_(nullptr), numbers_(10, nullptr) {

}

PlayerScore::~PlayerScore() {

}

void PlayerScore::init() {
    label_ = SpriteManager::getInstancePtr()->getSprite(spr::SCORE_TEXT);

    numbers_.at(0) = (SpriteManager::getInstancePtr()->getSprite(spr::ZERO_TEXT));
    numbers_.at(1) = (SpriteManager::getInstancePtr()->getSprite(spr::ONE_TEXT));
    numbers_.at(2) = (SpriteManager::getInstancePtr()->getSprite(spr::TWO_TEXT));
    numbers_.at(3) = (SpriteManager::getInstancePtr()->getSprite(spr::THREE_TEXT));
    numbers_.at(4) = (SpriteManager::getInstancePtr()->getSprite(spr::FOUR_TEXT));
    numbers_.at(5) = (SpriteManager::getInstancePtr()->getSprite(spr::FIVE_TEXT));
    numbers_.at(6) = (SpriteManager::getInstancePtr()->getSprite(spr::SIX_TEXT));
    numbers_.at(7) = (SpriteManager::getInstancePtr()->getSprite(spr::SEVEN_TEXT));
    numbers_.at(8) = (SpriteManager::getInstancePtr()->getSprite(spr::EIGHT_TEXT));
    numbers_.at(9) = (SpriteManager::getInstancePtr()->getSprite(spr::NINE_TEXT));
}

Sprite* PlayerScore::getNumberSprite(int n) const {
    if (n < 0 || n > 9) {
        return nullptr;
    } else {
        return numbers_.at(n);
    }
}

void PlayerScore::render() const {
    auto pRenderer = Renderer::getInstancePtr();
    assert(pRenderer);

    float x = -23.0f, y = -15.0f, z = -0.21f;

    Transform tr;
    tr.setTranslation(Vector3(x, y, z));
    pRenderer->setTransform(tr);

    label_->render();

    x += label_->getWidth() + 0.2f;

    int score(score_);
	score = 567890;
    // break score into pieces
    for (int i = 0, n = 5; i < 6; ++i, --n) {
        int p = pow(10, n);
        int res(score / p);
        score = score % p;

        Sprite* pSpr(getNumberSprite(res));

        tr.setTranslation(Vector3(x + i * pSpr->getWidth(), y, z));
        pRenderer->setTransform(tr);

        pSpr->render();
    }
}