/***************************************************************************************
*	Title: SphereCollider.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef SPHERE_COLLIDER_H_
#define SPHERE_COLLIDER_H_

#include "Collider.h"
#include "../../Math/Vector3.h"

namespace Framework {

    class SphereCollider : public Collider {
        private:
            Vector3* pPos_;
            float radius_;

        public:
            SphereCollider(Vector3* pPos, float radius);
            virtual ~SphereCollider();

            virtual bool collides(Collider*) const;
            virtual bool collides(const SphereCollider&) const;

            const float getRadius() const {
                return radius_;
            }
            void setRadius(float radius) {
                radius_ = radius;
            }

            const Vector3 getPos() const {
                return *pPos_;
            }

            void setPos(Vector3* pPos) {
                pPos_ = pPos;
            }
    };

}

#endif // SPHERE_COLLIDER_H_
