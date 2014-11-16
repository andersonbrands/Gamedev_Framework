/***************************************************************************************
*	Title: Star.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "Star.h"

Star::Star() : PoolObject(), pos_(), scale_(), rotation_() {

}

Star::~Star() {

}

void Star::spawn(float posX, float posY, float scaleX, float scaleY, float rotation) {
    pos_ = Vector3(posX, posY, 0.0f);
    scale_ = Vector3(scaleX, scaleY, 1.0f);
    rotation_ = Vector3(0.0f, 0.0f, rotation);
}

void Star::update() {

}