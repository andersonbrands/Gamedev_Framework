/***************************************************************************************
*	Title: Bullet.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef BULLET_H_
#define BULLET_H_

#include "../../Framework/Utilities/PoolObject.h"
#include "../../Framework/GameObjects/GameObject.h"
#include "../../Framework/GameObjects/Components/TransformComponent.h"
#include "../../Framework/GameObjects/Components/MovementComponent.h"
#include "../../Framework/GameObjects/Components/SpriteComponent.h"
#include "../../Framework/EventManager/EventManager.h"
#include "../../Framework/Renderer/Renderer.h"


using namespace Framework;

class Bullet : public PoolObject, public GameObject {
    private:

    public:
        Bullet();
        virtual ~Bullet();

        virtual void spawn(float x, float y);
        virtual int getDamage() const = 0;
        virtual void init() = 0;
        virtual void remove();

        virtual void handleEvent(Event* pEvent);
};

#endif // BULLET_H_
