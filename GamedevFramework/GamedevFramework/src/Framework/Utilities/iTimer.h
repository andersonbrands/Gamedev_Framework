/***************************************************************************************
*	Title: iTimer.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef I_TIMER_H_
#define I_TIMER_H_

#include "../Kernel/Task.h"

namespace Framework {
    class iTimer : public Task {
        public:
            typedef long long	TimeUnits;

            iTimer(const unsigned int priority) : Task( priority ) {}
            virtual ~iTimer() {}

            // task interface
            virtual bool	start()						= 0;
            virtual void 	onSuspend()					= 0;
            virtual void 	update()					= 0;
            virtual void 	onResume()					= 0;
            virtual void 	stop()						= 0;

            // timer interface
            virtual float		getTimeFrame() const							= 0;
            virtual float		getTimeSim() const								= 0;
            virtual void		setSimMultiplier(const float simMultiplier)		= 0;
            virtual float		getSimMultiplier()								= 0;
            virtual float		getFPS() const									= 0;
            virtual float		getGameTime() const								= 0;
            virtual TimeUnits	getUpdateFrame() const							= 0;

        protected:
            // platform interface
            virtual TimeUnits	miliSecondsTime() const			= 0;
            virtual void		sleep(long miliSeconds) const	= 0;

    };

}

#endif // I_TIMER_H_
