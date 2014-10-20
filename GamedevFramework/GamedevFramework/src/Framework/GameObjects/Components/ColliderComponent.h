/***************************************************************************************
*	Title: ColliderComponent.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef COLLIDER_COMPONENT_H_
#define COLLIDER_COMPONENT_H_

#include "../Component.h"
#include "../ComponentId.h"
#include "../../Math/Vector3.h"
#include "../../EventManager/EventHandler.h"
#include "../../EventManager/Event.h"

namespace Framework {

    class ColliderComponent : public Component, public EventHandler {
        public:
            ColliderComponent(GameObject* pOwner);
            ~ColliderComponent();

            static ComponentId getId()	{
                return comp::COLLIDER;
            }
    };

}

#endif // COLLIDER_COMPONENT_H_
