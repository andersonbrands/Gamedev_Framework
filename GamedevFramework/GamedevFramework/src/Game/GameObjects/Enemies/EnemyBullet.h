/***************************************************************************************
*	Title: EnemyBullet.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef ENEMY_BULLET_H_
#define ENEMY_BULLET_H_

#include "../Bullet.h"

class EnemyBullet : public Bullet {
    private:
        static int damage_;
    public:
        EnemyBullet();
        virtual ~EnemyBullet();

        virtual int getDamage() const;
        virtual void init();
        virtual void	spawn(float x, float y);

        virtual void handleEvent(Event* pEvent);
};

#endif // ENEMY_BULLET_H_
