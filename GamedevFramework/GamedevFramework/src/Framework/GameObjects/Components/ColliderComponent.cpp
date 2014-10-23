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

    ColliderComponent::ColliderComponent(GameObject* pOwner) : Component(pOwner), collider_(nullptr) {

    }
    ColliderComponent::~ColliderComponent() {
    }

    bool ColliderComponent::collides(ColliderComponent* pCollider) {
        return collider_->collides(pCollider->getCollider());
    }
}