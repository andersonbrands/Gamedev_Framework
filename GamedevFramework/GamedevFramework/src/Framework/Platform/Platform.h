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

namespace Framework {

    class Platform : public wPlatform {
        protected:
            static bool		isClosing_;

        public:
            Platform(const unsigned int priority);
            virtual ~Platform();

            virtual bool	start();
            virtual void	onSuspend();
            virtual void	update();
            virtual void	onResume();
            virtual void	stop();

            static void clearClosing() {
                isClosing_ = false;
            }
            static bool isClosing()	{
                return isClosing_;
            }
    };
}

#endif // PLATFORM_H_
