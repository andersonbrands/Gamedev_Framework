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

    class IsFree {
            IsFree() {}
            bool operator () (PoolObject *poolObject) {
                return poolObject->isFree();
            }
    };

}

#endif // FUNCTORS_H_
