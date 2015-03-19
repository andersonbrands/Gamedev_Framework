/***************************************************************************************
*	Title: PlayerBullet.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef PLAYER_BULLET_H_
#define PLAYER_BULLET_H_

#include "../Bullet.h"

class PlayerBullet : public Bullet {
    private:
        static int		damage_;
    public:
        PlayerBullet();
        virtual ~PlayerBullet();

        virtual int		getDamage() const;
        virtual void	init();

        virtual void handleEvent(Event* pEvent);
};

#endif // PLAYER_BULLET_H_
