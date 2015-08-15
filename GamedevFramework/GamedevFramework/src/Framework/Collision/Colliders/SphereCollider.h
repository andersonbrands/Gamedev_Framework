/***************************************************************************************
*	Title: SphereCollider.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef SPHERE_COLLIDER_H_
#define SPHERE_COLLIDER_H_

#include "Collider.h"
#include "../../Math/Transform.h"

namespace Framework {

    class SphereCollider : public Collider {
        private:
            Transform* pTransform_;
            float radius_;

        public:
            SphereCollider(Transform* pTransform, float radius);
            virtual ~SphereCollider();

            virtual bool collides(const Collider*) const;
            virtual bool collides(const SphereCollider&) const;

            const float getRadius() const {
                return radius_;
            }
            void setRadius(float radius) {
                radius_ = radius;
            }

            const Transform getTransform() const {
                return *pTransform_;
            }

            void setPos(Transform* pTransform) {
                pTransform_ = pTransform;
            }
    };

}

#endif // SPHERE_COLLIDER_H_
