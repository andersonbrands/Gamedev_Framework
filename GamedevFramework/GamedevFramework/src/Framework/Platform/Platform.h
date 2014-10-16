/***************************************************************************************
*	Title: Platform.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original (Android.h) by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "../Kernel/Task.h"
#include "../Wrapper.h"
#include "../Utilities/Singleton.h"
#include "../EventManager/EventHandler.h"
#include "../EventManager/EventManager.h"

namespace Framework {

    class Platform : public wPlatform, public EventHandler, public Singleton<Platform> {
        protected:
            static bool		isClosing_;

        public:
            Platform(const unsigned int priority);
            virtual ~Platform();

            static void clearClosing() {
                isClosing_ = false;
            }
            static bool isClosing()	{
                return isClosing_;
            }

            virtual void handleEvent(Event* pEvent);
    };
}

#endif // PLATFORM_H_
