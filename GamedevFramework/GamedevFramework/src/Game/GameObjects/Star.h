/***************************************************************************************
*	Title: Star.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef STAR_H_
#define STAR_H_

#include "../../Framework/Renderer/Sprite/Sprite.h"
#include "../../Framework/Math/Vector3.h"
#include "../../Framework/Utilities/PoolObject.h"

using namespace Framework;

class Star : public PoolObject {
    private:
        Vector3 pos_;
        Vector3 scale_;
        Vector3 rotation_;

    public:
        Star();
        virtual ~Star();

        Vector3 getPos() const {
            return pos_;
        }
        Vector3 getScale() const {
            return scale_;
        }
        Vector3 getRotation() const {
            return rotation_;
        }

        void spawn(bool atTop = false);
        void spawn(float posX, float posY, float scaleX, float scaleY, float rotation);

        void update();
};

#endif // STAR_H_
