/***************************************************************************************
*	Title: AABBCollider.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "AABBCollider.h"

namespace Framework {

    AABBCollider::AABBCollider() {

    }

    AABBCollider::~AABBCollider() {

    }

    bool AABBCollider::collides(Collider* pCollider) const {
        AABBCollider* aabb(static_cast<AABBCollider*>(pCollider));
        if (aabb)
            return collides(*aabb);

        PointCollider* point(static_cast<PointCollider*>(pCollider));
        if (point)
            return collides(*point);

        return Collider::collides(pCollider);
    }

    bool AABBCollider::collides(const PointCollider& pointCollider) const {
        bool collides(true);

        Vector3 point(pointCollider.getPoint());

        if (	point.getX() > max_.getX() ||
                point.getX() < min_.getX() ||
                point.getY() > max_.getY() ||
                point.getY() < min_.getY() ||
                point.getZ() > max_.getZ() ||
                point.getZ() < min_.getZ() ) {

            collides = false;
        }
        return collides;
    }

    bool AABBCollider::collides(const AABBCollider& bb) const {
        bool collides(true);

        if (	min_.getX() > bb.max_.getX() ||
                min_.getY() > bb.max_.getY() ||
                min_.getZ() > bb.max_.getZ() ||

                max_.getX() < bb.min_.getX() ||
                max_.getY() < bb.min_.getY() ||
                max_.getZ() < bb.min_.getZ() ) {

            collides = false;

        }

        return collides;
    }
}