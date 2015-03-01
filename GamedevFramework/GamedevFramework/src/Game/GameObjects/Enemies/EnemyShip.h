/***************************************************************************************
*	Title: EnemyShip.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef ENEMY_SHIP_H_
#define ENEMY_SHIP_H_

#include "../Ship.h"

class EnemyShip : public Ship {
    private:
        bool active_;

    public:
        EnemyShip();
        virtual ~EnemyShip();

        void setActive(bool active) {
            active_ = active;
        }
        bool isActive() const {
            return active_;
        }

        virtual void	init() = 0;
        virtual int		getMaxHp() = 0;
        virtual void	update() = 0;
        virtual void	spawn(float x, float y) = 0;
        virtual void	reset() = 0;

        virtual void	handleEvent(Event* pEvent);
};

#endif // ENEMY_SHIP_H_
