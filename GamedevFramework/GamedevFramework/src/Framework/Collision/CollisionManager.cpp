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

    CollisionManager::CollisionManager(const unsigned int priority) : Task(priority), EventHandler() {

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
    void CollisionManager::removeObjectFromGroup(CollisionGroupId groupId, GameObject* pObject) {
        auto group(getObject(groupId));
        assert(group);
        group->removeObject(pObject);
    }
    void CollisionManager::testAgainstGroup(CollisionGroupId groupId, GameObject* pObject) {
        auto group(getObject(groupId));
        assert(group);

        GameObject* pGroupObject = group->getFirst();
        while (pGroupObject) {
            auto pCopy = pGroupObject;
            test(pObject, pCopy);
            pGroupObject = group->getNext();
        }
    }

    void CollisionManager::testGroups(CollisionGroupId groupId1, CollisionGroupId groupId2) {
        auto group(getObject(groupId1));
        assert(group);

        GameObject* pGroupObject = group->getFirst();
        while (pGroupObject) {

            testAgainstGroup(groupId2, pGroupObject);

            pGroupObject = group->getNext();
        }
    }

    void CollisionManager::test(GameObject* go1, GameObject* go2) {
        if (go1 == go2 || !go1->isActive() || !go2->isActive()) return;

        ColliderComponent* pCollider1 = component_cast<ColliderComponent>(go1);
        ColliderComponent* pCollider2 = component_cast<ColliderComponent>(go2);

        assert (pCollider1 && pCollider2);


        if (pCollider1->getCollider()->collides(pCollider2->getCollider())) {
            ev::data::Collision collisionData;
            collisionData.pGameObject = go2;
            sendEventToHandler(ev::id::COLLISION, *go1, &collisionData);
            collisionData.pGameObject = go1;
            sendEventToHandler(ev::id::COLLISION, *go2, &collisionData);
        }
    }

    void CollisionManager::clearGroup(CollisionGroupId groupId) {
        auto group(getObject(groupId));
        assert(group);
        group->clear();
    }


    bool CollisionManager::start() {
        registerEvent(ev::id::COLLISION_CHECK);
        registerEvent(ev::id::COLLISION);
        return true;
    }
    void CollisionManager::onSuspend() {
        setSuspended(true);
    }
    void CollisionManager::update() {
        sendEvent(ev::id::COLLISION_CHECK);
    }
    void CollisionManager::onResume() {
        setSuspended(false);
    }
    void CollisionManager::stop() {
        unregisterEvent(ev::id::COLLISION_CHECK);
        unregisterEvent(ev::id::COLLISION);
    }

    void CollisionManager::handleEvent(Event* pEvent) {
        switch (pEvent->getID()) {
            case ev::id::PLATFORM_SUSPEND:
                onSuspend();
                break;
            case ev::id::PLATFORM_RESUME:
                onResume();
                break;
            default:
                break;
        }
    }
}
