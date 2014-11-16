/***************************************************************************************
*	Title: StarDust.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef STAR_DUST_H_
#define STAR_DUST_H_

#include "../../Framework/Utilities/PoolAllocator.h"
#include "../../Framework/Renderer/Sprite/Sprite.h"
#include "Star.h"

using namespace Framework;

class StarDust : public PoolAllocator<Star> {
    private:
        Sprite* pStarSprite_;
    public:
        StarDust(int totalObjects);
        virtual ~StarDust();

        virtual void init();

        void update();
        void render() const;
};

class Spawn {
    public:
        Spawn() {}
        void operator() (Star *star) {
            star->spawn();
        }
};

#endif // STAR_DUST_H_
