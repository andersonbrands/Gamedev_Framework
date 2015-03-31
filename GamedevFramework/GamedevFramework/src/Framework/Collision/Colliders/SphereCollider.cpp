/***************************************************************************************
*	Title: SphereCollider.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "SphereCollider.h"

namespace Framework {

    SphereCollider::SphereCollider(Vector3* pPos, float radius) : pPos_(pPos), radius_(radius) {

    }

    SphereCollider::~SphereCollider() {

    }

    bool SphereCollider::collides(Collider* pCollider) const {
        SphereCollider* pSphere(static_cast<SphereCollider*>(pCollider));
        if (pSphere)
            return collides(*pSphere);

        return Collider::collides(pCollider);
    }

    bool SphereCollider::collides(const SphereCollider& sphereCollider) const {
        bool collides(false);

        float bothRadius(radius_ + sphereCollider.radius_);

        if (pPos_->distanceSquared(*sphereCollider.pPos_) < pow(bothRadius, 2)) {
            collides = true;
        }

        return collides;
    }
}