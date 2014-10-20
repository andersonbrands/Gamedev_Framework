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
#include <cassert>

namespace Framework {

    CollisionManager::CollisionManager() {

    }

    CollisionManager::~CollisionManager() {

    }

    void CollisionManager::addCollisionGroup() {
        collisionGroups_.push_back(CollisionGroup());
    }

    void CollisionManager::addObjectToGroup(const unsigned int binIndex, GameObject* pObject) {
        assert(binIndex < collisionGroups_.size());
        collisionGroups_[binIndex].addObject(pObject);
    }

    void CollisionManager::testAgainstGroup(const unsigned int binIndex, GameObject* pObject) {
        assert(binIndex < collisionGroups_.size());
        CollisionGroup& bin = collisionGroups_[binIndex];
        GameObject* pGroupObject = bin.getFirst();
        while (pGroupObject) {

            test(pObject, pGroupObject);

            pGroupObject = bin.getNext();
        }
    }

    void CollisionManager::test(GameObject* go1, GameObject* go2) {
        if (go1 == go2) return;

        ColliderComponent* pCollider1 = component_cast<ColliderComponent>(go1);
        ColliderComponent* pCollider2 = component_cast<ColliderComponent>(go2);

        assert (pCollider1 && pCollider2);

        // TODO: complete collision test
    }

    void CollisionManager::clearGroup(const unsigned int binIndex) {
        assert(binIndex < collisionGroups_.size());
        CollisionGroup& bin = collisionGroups_[binIndex];
        bin.clear();
    }

}