/***************************************************************************************
*	Title: ColliderComponent.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "ColliderComponent.h"

#include <cassert>

namespace Framework {

    ColliderComponent::ColliderComponent(GameObject* pOwner) : Component(pOwner), collider_(nullptr), colliderType_(Collider::ColliderType::UNDEFINED) {

    }
    ColliderComponent::~ColliderComponent() {
    }

}
