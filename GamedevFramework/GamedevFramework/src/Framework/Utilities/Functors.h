/***************************************************************************************
*	Title: Functors.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef FUNCTORS_H_
#define FUNCTORS_H_

#include "PoolObject.h"

namespace Framework {

    class PoolObjectIsFree {
            PoolObjectIsFree() {}
            bool operator () (PoolObject *poolObject) {
                return poolObject->isFree();
            }
    };

    class PoolObjectInit {
        public:
            PoolObjectInit() {}
            void operator() (PoolObject *object) {
                object->init();
            }
    };


}

#endif // FUNCTORS_H_
