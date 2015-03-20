/***************************************************************************************
*	Title: iScene.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef I_SCENE_H_
#define I_SCENE_H_

namespace Framework {

    class iScene {
        private:
        public:
            iScene() {}
            virtual ~iScene() {}

            virtual void load()		= 0;
            virtual void init()		= 0;
            virtual void update()	= 0;
            virtual void unload()	= 0;
            virtual void dispose()	= 0;

            virtual void loadTextures() = 0;
            virtual void unloadTextures() = 0;

            virtual void addSprites() = 0;
            virtual void removeSprites() = 0;

            virtual void registerEvents() = 0;
            virtual void unregisterEvents() = 0;
    };

}

#endif // I_SCENE_H_
