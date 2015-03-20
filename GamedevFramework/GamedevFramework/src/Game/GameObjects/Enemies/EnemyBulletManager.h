/***************************************************************************************
*	Title: EnemyBulletManager.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef ENEMY_BULLET_MANAGER_H_
#define ENEMY_BULLET_MANAGER_H_

#include "../BulletManager.h"
#include "EnemyBullet.h"
#include "../../../Framework/EventManager/EventHandler.h"
#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/EventManager/Event.h"

#include "../../Ids/EventIds.h"


class EnemyBulletManager : public BulletManager<EnemyBullet>, public EventHandler {
    private:
    public:
        EnemyBulletManager(int totalObjects);
        virtual ~EnemyBulletManager();

        virtual void init();

        virtual void handleEvent(Event* pEvent);
};

#endif // ENEMY_BULLET_MANAGER_H_
