/***************************************************************************************
*	Title: Utils.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef UTILS_H_
#define UTILS_H_

#include <cstdlib>
#include <ctime>

namespace Framework {
    enum Direction;
    namespace dir {
        enum Direction {
            FORWARD, BACKWARD, UP, DOWN, RIGHT, LEFT
        };
    }

    void seed();
    int rand_int(int, int);
    float rand_float(float, float);
};

#endif // UTILS_H_
