/***************************************************************************************
*	Title: AABBCollider.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "AABBCollider.h"

namespace Framework {

    AABBCollider::AABBCollider(Transform* pTransform, const Vector3& min, const Vector3& max) : pTransform_(pTransform), min_(min), max_(max) {

    }

    AABBCollider::~AABBCollider() {

    }

    bool AABBCollider::collides(const Collider* pCollider) const {
        const AABBCollider* aabb(dynamic_cast<const AABBCollider*>(pCollider));
        if (aabb)
            return collides(*aabb);

        const PointCollider* point(dynamic_cast<const PointCollider*>(pCollider));
        if (point)
            return collides(*point);

        return Collider::collides(pCollider);
    }

    bool AABBCollider::collides(const PointCollider& pointCollider) const {
        bool collides(true);

        Vector3 point(pointCollider.getPoint());

        Vector3 pos(pTransform_->getTranslation());
        Vector3 max(pos + max_);
        Vector3 min(pos + min_);

        if (	point.getX() > max.getX() ||
                point.getX() < min.getX() ||
                point.getY() > max.getY() ||
                point.getY() < min.getY() ||
                point.getZ() > max.getZ() ||
                point.getZ() < min.getZ() ) {

            collides = false;
        }
        return collides;
    }

    bool AABBCollider::collides(const AABBCollider& bb) const {
        bool collides(true);

        if (!pTransform_) {
            return false;
        }

        Vector3 max(getMax());
        Vector3 min(getMin());
        Vector3 max2(bb.getMax());
        Vector3 min2(bb.getMin());

        if (	min.getX() > max2.getX() ||
                min.getY() > max2.getY() ||
                min.getZ() > max2.getZ() ||

                max.getX() < min2.getX() ||
                max.getY() < min2.getY() ||
                max.getZ() < min2.getZ() ) {

            collides = false;

        }

        return collides;
    }
}