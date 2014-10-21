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

namespace Framework {

    class CollisionManager : public UnorderedMapContainer<CollisionGroupId, CollisionGroup>, public Singleton<CollisionManager> {
        private:
            void test(GameObject*, GameObject*);

        public:
            CollisionManager();
            virtual ~CollisionManager();

            void addCollisionGroup(CollisionGroupId groupId);
            void addObjectToGroup(CollisionGroupId groupId, GameObject* pObject);
            void testAgainstGroup(CollisionGroupId groupId, GameObject* pObject);
            void clearGroup(CollisionGroupId groupId);

    };

}
#endif // COLLISION_MANAGER_H_
