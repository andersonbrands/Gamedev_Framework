/***************************************************************************************
*	Title: Ship.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SHIP_H_
#define SHIP_H_

#include "../../Framework/GameObjects/GameObject.h"

#include "../../Framework/GameObjects/Components/TransformComponent.h"
#include "../../Framework/Renderer/Sprite/Sprite.h"

using namespace Framework;

class Ship : public GameObject {
    protected:
        int hp_;
        Sprite* pSprite_;
    public:
        Ship();
        virtual ~Ship();
        virtual void init() = 0;
        virtual int getMaxHp() = 0;
        void damage(int value);
        void heal(int value);

        int getHp() const {
            return hp_;
        }

        virtual void handleEvent(Event* pEvent) {}
};

#endif // SHIP_H_
