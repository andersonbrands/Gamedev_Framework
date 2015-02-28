/***************************************************************************************
*	Title: EnemyCShip.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef ENEMY_C_SHIP_H_
#define ENEMY_C_SHIP_H_

#include "EnemyShip.h"
#include "../../../Framework/Utilities/Utils.h"

class EnemyCShip : public EnemyShip {
    private:
        static int		MAX_HP;
        static int		MIN_FLIP_PROB;

        Direction		horizontalDirection_;
        int				flipProbability_;

        void			flipH();
        void			reachHorizontalLimit(Direction directionToGo, float limit);
    public:
        EnemyCShip();
        virtual ~EnemyCShip();

        virtual void	init();
        virtual int		getMaxHp();
        virtual void	update();
        virtual void	spawn(float x, float y);
        virtual void	reset();

        virtual void handleEvent(Event* pEvent);
};

#endif // ENEMY_C_SHIP_H_
