#ifndef COMPONENT_ID_H_
#define COMPONENT_ID_H_

namespace Framework {
    typedef unsigned int ComponentId;

    namespace comp {
        //static const ComponentId COMPONENT_ID_COMPONENT_NAME	= value;
        static const ComponentId SAMPLE				= 0;
        static const ComponentId TRANSFORM			= 1;
        static const ComponentId MOVEMENT			= 2;
        static const ComponentId SPRITE_ANIMATION	= 3;
		static const ComponentId COLLIDER			= 4;
    }
}

#endif // COMPONENT_ID_H_
