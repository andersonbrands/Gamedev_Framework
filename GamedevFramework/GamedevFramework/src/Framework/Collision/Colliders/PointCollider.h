/***************************************************************************************
*	Title: PointCollider.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef POINT_COLLIDER_H_
#define POINT_COLLIDER_H_

#include "Collider.h"
#include "../../Math/Vector3.h"

namespace Framework {

    class PointCollider : public Collider {
        private:
            Vector3 point_;
        public:
            PointCollider();
            virtual ~PointCollider();

            const Vector3 getPoint() const {
                return point_;
            }
            void setPoint(const Vector3& point) {
                point_ = point;
            }
    };

}

#endif // POINT_COLLIDER_H_
