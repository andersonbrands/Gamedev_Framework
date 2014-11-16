/***************************************************************************************
*	Title: StarDust.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "StarDust.h"
#include "../../Framework/Renderer/Renderer.h"
#include "../../Framework/Renderer/Sprite/SpriteManager.h"
#include "../../Framework/Renderer/Texture/TextureManager.h"
#include "../Ids/SpriteIds.h"
#include "../Ids/TextureIds.h"

StarDust::StarDust(int totalObjects) : PoolAllocator(totalObjects), pStarSprite_(nullptr) {

}

StarDust::~StarDust() {

}

void StarDust::init() {
    auto sprManager(SpriteManager::getInstancePtr());
    assert(sprManager);
    pStarSprite_ = sprManager->addSprite(spr::STAR_SPRITE);
    assert(pStarSprite_);

    auto texManager(TextureManager::getInstancePtr());
    assert(texManager);
    // TODO: create a new Texture
    auto pTexture(texManager->loadTexture(tex::MAIN_MENU_SPR_SHEET));

    // configure sprite
    pStarSprite_->setUVCoords(0.9375f, 0.943f, 0.0f, 0.0058f);
    pStarSprite_->setup(pTexture, SpriteAlign::CENTER, 1.0f, 1.0f);

    Spawn sp;
    for_each(objects_.begin(), objects_.end(), sp);
}

void StarDust::update() {

}
void StarDust::render() const {
    auto renderer(Renderer::getInstancePtr());
    assert(renderer);

    auto iter(objects_.begin());

    while (iter != objects_.end()) {
        Star* pStar(*iter);
        if (!pStar->isFree()) {
            renderer->setTransform(pStar->getPos(), pStar->getScale(), pStar->getRotation());
            pStarSprite_->render();
        }
        iter++;
    }

}
