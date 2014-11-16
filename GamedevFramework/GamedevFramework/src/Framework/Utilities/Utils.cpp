/***************************************************************************************
*	Title: Utils.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "Utils.h"
namespace Framework {

    void seed() {
        srand(time(0));
    }

    int rand_int(int min, int max) {
        return min + std::rand() % ((max + 1) - min);
    }

    float rand_float(float min, float max) {
        int number(rand_int(0, 10000));
        return min + (max - min) * ((float)number / 10000.0f);
    }

}
