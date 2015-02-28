/***************************************************************************************
*	Title: EnemyAShip.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef ENEMY_A_SHIP_H_
#define ENEMY_A_SHIP_H_

#include "EnemyShip.h"

class EnemyAShip : public EnemyShip {
    private:
        static int MAX_HP;
    public:
        EnemyAShip();
        virtual ~EnemyAShip();

        virtual void	init();
        virtual int 	getMaxHp();
        virtual void	update();
        virtual void	spawn(float x, float y);
        virtual void	reset();

        virtual void	handleEvent(Event* pEvent);
};

#endif // ENEMY_A_SHIP_H_
