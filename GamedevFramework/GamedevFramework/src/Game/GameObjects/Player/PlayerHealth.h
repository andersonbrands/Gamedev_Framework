/***************************************************************************************
*	Title: PlayerHealth.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef PLAYER_HEALTH_H_
#define PLAYER_HEALTH_H_

#include "../../../Framework/Renderer/Sprite/Sprite.h"
#include "../../../Framework/EventManager/EventHandler.h"

using namespace Framework;

class PlayerHealth : public EventHandler {
    private:
        int& health_;
        const int& maxHealth_;
        Sprite* green_;
        Sprite* grey_;

    public:
        PlayerHealth(int& health, const int& maxHealth);
        virtual			~PlayerHealth();

        void			init();
        void			render() const;

        virtual void	handleEvent(Event* pEvent);
};

#endif // PLAYER_HEALTH_H_
