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

    auto pTexture(texManager->getTexture(tex::IN_GAME_SPR_SHEET.id));

    // configure sprite
    pStarSprite_->setUVCoords(0.9903f, 1.0f, 0.0f, 0.0097f);
    pStarSprite_->setup(pTexture, SpriteAlign::CENTER, 1.0f, 1.0f);

    Spawn sp;
    for_each(objects_.begin(), objects_.end(), sp);
}

void StarDust::update() {
    auto iter(objects_.begin());
    while (iter!=objects_.end()) {
        Star* pStar(*iter);
        if (!pStar->isFree()) {
            pStar->update();
        }
        ++iter;
    }
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
        ++iter;
    }

}
