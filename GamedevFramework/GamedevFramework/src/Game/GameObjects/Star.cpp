/***************************************************************************************
*	Title: Star.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "Star.h"
#include "../../Framework/Utilities/Utils.h"

Star::Star() : PoolObject(), pos_(), scale_(), rotation_() {
    setIsFree(false);
}

Star::~Star() {

}

void Star::spawn() {
    float posX		= rand_float(-24.0f, 24.0f);
    float posY		= rand_float(-16.0f, 16.0f);
    float scaleX	= rand_float(0.2f, 0.35f);
    float scaleY	= rand_float(0.2f, 0.35f);
    float rotation	= rand_float(0.0f, 6.28f);

    spawn(posX, posY, scaleX, scaleY, rotation);
}

void Star::spawn(float posX, float posY, float scaleX, float scaleY, float rotation) {
    pos_ = Vector3(posX, posY, 0.0f);
    scale_ = Vector3(scaleX, scaleY, 1.0f);
    rotation_ = Vector3(0.0f, 0.0f, rotation);
}

void Star::update() {

}