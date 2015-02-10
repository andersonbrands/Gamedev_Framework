/***************************************************************************************
*	Title: PlayerShipMovement.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef PLAYER_SHIP_MOVEMENT_H_
#define PLAYER_SHIP_MOVEMENT_H_

#include "../../../Framework/GameObjects/Components/MovementComponent.h"

using namespace Framework;

class PlayerShipMovement : public MovementComponent {
    private:
    public:
        explicit PlayerShipMovement(GameObject* pOwner);
        virtual ~PlayerShipMovement();

        static ComponentId getId() {
            return comp::MOVEMENT;
        }

        virtual void preMovement();
        virtual void postMovement();
};

#endif // PLAYER_SHIP_MOVEMENT_H_
