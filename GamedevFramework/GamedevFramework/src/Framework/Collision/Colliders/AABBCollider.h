/***************************************************************************************
*	Title: AABBCollider.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef AABB_COLLIDER_H_
#define AABB_COLLIDER_H_

#include "Collider.h"
#include "PointCollider.h"
#include "../../Math/Vector3.h"

namespace Framework {

    class AABBCollider : public Collider {
        private:
            Vector3 max_;
            Vector3 min_;
        public:
            AABBCollider();
            virtual ~AABBCollider();

            virtual bool collides(Collider*) const;
            virtual bool collides(const AABBCollider&) const;
            virtual bool collides(const PointCollider&) const;

            void setMin(const Vector3& min) {
                min_ = min;
            }

            const Vector3 getMin() const {
                return min_;
            }

            void setMax(const Vector3& max) {
                max_ = max;
            }

            const Vector3 getMax() const {
                return max_;
            }
    };

}

#endif // AABB_COLLIDER_H_
