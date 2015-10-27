/***************************************************************************************
*	Title: ColliderComponent.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "ColliderComponent.h"
#include "../GameObject.h"
#include "../../../MyAssert.h"

namespace Framework {

    ColliderComponent::ColliderComponent(GameObject* pOwner) : Component(pOwner), pCollider_(nullptr) {

    }

    ColliderComponent::~ColliderComponent() {
        if (pCollider_) {
            delete pCollider_;
            pCollider_ = nullptr;
        }
    }

    bool ColliderComponent::collides(ColliderComponent* pCollider) {
        if (!getOwner()->isActive() || !pCollider->getOwner()->isActive())
            return false;


        return pCollider_->collides(pCollider->getCollider());
    }
}