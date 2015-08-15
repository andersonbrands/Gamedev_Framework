/***************************************************************************************
*	Title: SphereCollider.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "SphereCollider.h"

namespace Framework {

    SphereCollider::SphereCollider(Transform* pTransform, float radius) : pTransform_(pTransform), radius_(radius) {

    }

    SphereCollider::~SphereCollider() {

    }

    bool SphereCollider::collides(const Collider* pCollider) const {
        const SphereCollider* pSphere(static_cast<const SphereCollider*>(pCollider));
        if (pSphere)
            return collides(*pSphere);

        return Collider::collides(pCollider);
    }

    bool SphereCollider::collides(const SphereCollider& sphereCollider) const {
        bool collides(false);

        float bothRadius(radius_ + sphereCollider.radius_);

        const Vector3 pos = pTransform_->getTranslation();

        if (pos.distanceSquared(sphereCollider.pTransform_->getTranslation()) < pow(bothRadius, 2)) {
            collides = true;
        }

        return collides;
    }
}