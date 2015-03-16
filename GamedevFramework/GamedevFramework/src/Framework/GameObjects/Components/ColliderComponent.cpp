/***************************************************************************************
*	Title: ColliderComponent.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "ColliderComponent.h"
#include "../GameObject.h"
#include <cassert>

namespace Framework {

    ColliderComponent::ColliderComponent(GameObject* pOwner) : Component(pOwner), pCollider_(nullptr) {

    }

    ColliderComponent::~ColliderComponent() {
    }

    bool ColliderComponent::collides(ColliderComponent* pCollider) {
        if (!getOwner()->isActive() || !pCollider->getOwner()->isActive())
            return false;


        return pCollider_->collides(pCollider->getCollider());
    }
}