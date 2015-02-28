/***************************************************************************************
*	Title: EnemyBShip.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef ENEMY_B_SHIP_H_
#define ENEMY_B_SHIP_H_

#include "EnemyShip.h"

#include "../../../Framework/Utilities/Utils.h"

class EnemyBShip : public EnemyShip {
    private:
        enum Steps {NEUTRAL, STEP_01_CENTER, STEP_01, STEP_02, STEP_03, STEP_04, STEP_05};

        static int		MAX_HP;
        static float	BORDER_LIMIT;
        static float	STOP_HEIGHT;

        Direction	borderDirection_;
        float		spawnX_;
        Steps		currentStep_;

        virtual void	spawn(float x, float y);
    public:
        EnemyBShip();
        virtual ~EnemyBShip();

        virtual void	init();
        virtual int		getMaxHp();
        virtual void	update();
        virtual void	spawn(float x, float y, Direction borderDirection);
        virtual void	reset();

        virtual void	handleEvent(Event* pEvent);
};

#endif // ENEMY_B_SHIP_H_
