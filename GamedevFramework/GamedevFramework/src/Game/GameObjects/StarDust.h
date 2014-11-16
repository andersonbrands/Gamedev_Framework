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
#include "../../Framework/Utilities/Utils.h"
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
            float posX		= rand_float(-24.0f, 24.0f);
            float posY		= rand_float(-16.0f, 16.0f);
            float scaleX	= rand_float(0.2f, 0.35f);
            float scaleY	= rand_float(0.2f, 0.35f);
            float rotation	= rand_float(0.0f, 6.28f);

            star->setIsFree(false);

            star->spawn(posX, posY, scaleX, scaleY, rotation);
        }
};

#endif // STAR_DUST_H_
