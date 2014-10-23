/***************************************************************************************
*	Title: Collider.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef COLLIDER_H_
#define COLLIDER_H_

#include <cassert>

namespace Framework {

    class Collider {
        private:
        public:
            Collider() {}
            virtual ~Collider() {}

            virtual bool collides(const Collider*) const = 0 {
                // collision have to be properly handled by derived classes
                assert(false);
                return false;
            }
    };

}

#endif // COLLIDER_H_
