/***************************************************************************************
*	Title: CollisionManager.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original (CollisionManager.h) by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef COLLISION_MANAGER_H_
#define COLLISION_MANAGER_H_

#include "../Utilities/Singleton.h"
#include "../Utilities/UnorderedMapContainer.h"
#include "CollisionGroupId.h"
#include "CollisionGroup.h"
#include "../Kernel/Task.h"
#include "../EventManager/EventHandler.h"

namespace Framework {

    class CollisionManager : public Task, public EventHandler, public UnorderedMapContainer<CollisionGroupId, CollisionGroup>, public Singleton<CollisionManager> {
        private:
            void test(GameObject*, GameObject*);

        public:
            CollisionManager(const unsigned int priority);
            virtual ~CollisionManager();

            void addCollisionGroup(CollisionGroupId groupId);
            void addObjectToGroup(CollisionGroupId groupId, GameObject* pObject);
            void removeObjectFromGroup(CollisionGroupId groupId, GameObject* pObject);

            void testAgainstGroup(CollisionGroupId groupId, GameObject* pObject);
            void clearGroup(CollisionGroupId groupId);

            virtual bool	start();
            virtual void	onSuspend();
            virtual void	update();
            virtual void	onResume();
            virtual void	stop();

            virtual void handleEvent(Event* pEvent);
    };

}
#endif // COLLISION_MANAGER_H_
