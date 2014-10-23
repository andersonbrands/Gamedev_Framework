/***************************************************************************************
*	Title: PointCollider.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "PointCollider.h"
#include "AABBCollider.h"

namespace Framework {

    PointCollider::PointCollider() : point_() {

    }

    PointCollider::~PointCollider() {

    }

    bool PointCollider::collides(Collider* pCollider) const {
        AABBCollider* aabb(static_cast<AABBCollider*>(pCollider));
        if (aabb)
            return aabb->collides(*this);

        PointCollider* point(static_cast<PointCollider*>(pCollider));
        if (point)
            return collides(*point);

        return Collider::collides(pCollider);
    }

    bool PointCollider::collides(const PointCollider& pointCollider) const {
        bool collides(true);

        if (point_ == pointCollider.point_) {
            collides = true;
        }

        return collides;
    }
}