/***************************************************************************************
*	Title: Collider.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef COLLIDER_H_
#define COLLIDER_H_

namespace Framework {

    class Collider {
        private:
        public:
            enum ColliderType {
                UNDEFINED, AABB, POINT, SPHERE
            };

            Collider() {}
            virtual ~Collider() {}

            virtual bool collides() = 0;
    };

}

#endif // COLLIDER_H_
