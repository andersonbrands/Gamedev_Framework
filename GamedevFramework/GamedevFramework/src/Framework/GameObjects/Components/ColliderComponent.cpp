/***************************************************************************************
*	Title: ColliderComponent.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "ColliderComponent.h"
#include "../../Collision/Colliders/AABBCollider.h"
#include "../../Collision/Colliders/PointCollider.h"

#include <cassert>

namespace Framework {

    ColliderComponent::ColliderComponent(GameObject* pOwner) : Component(pOwner), pCollider_(nullptr) {

    }
    ColliderComponent::~ColliderComponent() {
    }

    bool ColliderComponent::collides(ColliderComponent* pCollider) {
        return pCollider_->collides(pCollider->getCollider());
    }
}