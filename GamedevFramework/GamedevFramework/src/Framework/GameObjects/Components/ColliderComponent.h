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
#include "../../Collision/Colliders/Collider.h"

namespace Framework {

    class ColliderComponent : public Component, public EventHandler {
        private:
            Collider* pCollider_;
        public:
            ColliderComponent(GameObject* pOwner);
            virtual ~ColliderComponent();

            static ComponentId getId()	{
                return comp::COLLIDER;
            }

            bool collides(ColliderComponent* pCollider);

            Collider* getCollider() {
                return pCollider_;
            }
    };

}

#endif // COLLIDER_COMPONENT_H_
