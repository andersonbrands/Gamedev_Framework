/***************************************************************************************
*	Title: GameObject.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <unordered_map>
#include "Component.h"
#include "ComponentId.h"
#include "../EventManager/EventHandler.h"

namespace Framework {
    class GameObject : public EventHandler {
            template <class T>
            friend T* component_cast(GameObject& object);

            template <class T>
            friend T* component_cast(GameObject* pObject);

        private:
            typedef std::tr1::unordered_map<ComponentId, Component*>	ComponentUnorderedMap;
            typedef ComponentUnorderedMap::iterator						ComponentUnorderedMapIterator;
            ComponentUnorderedMap	components_;

            template <class T>
            T*	getComponent() {
                return static_cast<T*>(getComponent(T::getId()));
            }

            Component*	getComponent(ComponentId id);

            bool active_;

        public:
            GameObject();
            virtual ~GameObject();

            void setActive(bool active) {
                active_ = active;
            }
            bool isActive() const {
                return active_;
            }

            virtual void handleEvent(Event* pEvent) {}

            template <class T>
            bool addComponent();

            virtual void update();
    };

    template <class T>
    T* component_cast(const GameObject& object) {
        return object.getComponent<T>();
    }

    template <class T>
    T* component_cast(const GameObject* pObject) {
        T* pComponent = nullptr;
        if (pObject) {
            pComponent = pObject->getComponent<T>();
        }

        return pComponent;
    }

    template <class T>
    bool GameObject::addComponent() {
        bool added = false;

        ComponentUnorderedMapIterator result = components_.find(T::getId());
        if (result == components_.end()) {
            T* pNewComponent = new T(this);

            if (pNewComponent) {
                std::pair<ComponentId, Component*> newComponent(T::getId(), pNewComponent);
                std::pair<ComponentUnorderedMapIterator, bool> addedIter = components_.insert(newComponent);
                added = addedIter.second;
            }
        }
        return added;
    }
}

#endif // GAME_OBJECT_H_
