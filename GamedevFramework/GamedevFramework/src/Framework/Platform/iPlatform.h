/***************************************************************************************
*	Title: iPlatform.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original (Android.h) by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef I_PLATFORM_H_
#define I_PLATFORM_H_

#include "../Kernel/Task.h"

namespace Framework {

    class iPlatform : public Task {
        public:
            iPlatform(const unsigned int priority):Task(priority) {}
            virtual ~iPlatform() {}

            virtual bool	start()		= 0;
            virtual void	onSuspend()	= 0;
            virtual void	update()	= 0;
            virtual void	onResume()	= 0;
            virtual void	stop()		= 0;
    };
}

#endif // I_PLATFORM_H_
