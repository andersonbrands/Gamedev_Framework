/***************************************************************************************
*	Title: CollisionManager.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original (CollisionManager.cpp) by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#include "CollisionManager.h"
#include "../GameObjects/Components/ColliderComponent.h"
#include "Colliders\Collider.h"
#include "../EventManager/EventManager.h"
#include "../EventManager/EventData.h"
#include <cassert>

namespace Framework {

    CollisionManager::CollisionManager() {

    }

    CollisionManager::~CollisionManager() {

    }

    void CollisionManager::addCollisionGroup(CollisionGroupId groupId) {
        addObject(groupId);
    }

    void CollisionManager::addObjectToGroup(CollisionGroupId groupId, GameObject* pObject) {
        auto group(getObject(groupId));
        assert(group);
        group->addObject(pObject);
    }

    void CollisionManager::testAgainstGroup(CollisionGroupId groupId, GameObject* pObject) {
        auto group(getObject(groupId));
        assert(group);

        GameObject* pGroupObject = group->getFirst();
        while (pGroupObject) {

            test(pObject, pGroupObject);

            pGroupObject = group->getNext();
        }
    }

    void CollisionManager::test(GameObject* go1, GameObject* go2) {
        if (go1 == go2) return;

        ColliderComponent* pCollider1 = component_cast<ColliderComponent>(go1);
        ColliderComponent* pCollider2 = component_cast<ColliderComponent>(go2);

        assert (pCollider1 && pCollider2);

        if (pCollider1->getCollider()->collides(pCollider2->getCollider())) {
            ev::data::Collision collisionData;
            collisionData.pGameObject = go2;
            sendEventToHandler(ev::id::COLISION, *go1, &collisionData);
            collisionData.pGameObject = go1;
            sendEventToHandler(ev::id::COLISION, *go2, &collisionData);
        }
    }

    void CollisionManager::clearGroup(CollisionGroupId groupId) {
        auto group(getObject(groupId));
        assert(group);
        group->clear();
    }

}
