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
#include "../../Math/Transform.h"

namespace Framework {

    class AABBCollider : public Collider {
        private:
            Transform* pTransform_;
            Vector3 max_;
            Vector3 min_;
        public:
            AABBCollider(Transform* pTransform, const Vector3& min, const Vector3& max);
            virtual ~AABBCollider();

            virtual bool collides(const Collider*) const;
            virtual bool collides(const AABBCollider&) const;
            virtual bool collides(const PointCollider&) const;

            void setMin(const Vector3& min) {
                min_ = min;
            }

            const Vector3 getMin() const {
                Vector3 pos(pTransform_->getTranslation());
                return min_ + pos;
            }

            void setMax(const Vector3& max) {
                max_ = max;
            }

            const Vector3 getMax() const {
                Vector3 pos(pTransform_->getTranslation());
                return max_ + pos;
            }
    };

}

#endif // AABB_COLLIDER_H_
