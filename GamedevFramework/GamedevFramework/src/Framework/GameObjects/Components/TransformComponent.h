/***************************************************************************************
*	Title: TransformComponent.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef TRANSFORM_COMPONENT_H_
#define TRANSFORM_COMPONENT_H_

#include "../Component.h"
#include "../ComponentId.h"
#include "../../Math/Transform.h"

namespace Framework {
    class GameObject;

    class TransformComponent: public Component, public Transform {
        public:
            static ComponentId getId() {
                return comp::TRANSFORM;
            }

            explicit TransformComponent(GameObject* pOwner);
            virtual ~TransformComponent();
        private:

    };
}

#endif // TRANSFORM_COMPONENT_H_
