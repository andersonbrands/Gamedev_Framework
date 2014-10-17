/***************************************************************************************
*	Title: TimerWindows.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef TIMER_WINDOWS_H_
#define TIMER_WINDOWS_H_

#include "../../../Framework/Utilities/iTimer.h"
#include <time.h>

using namespace Framework;

class TimerWindows : public iTimer {
    public:
        TimerWindows(const unsigned int priority);
        ~TimerWindows();

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
        virtual TimeUnits	miliSecondsTime()		const;
        virtual void		sleep(long miliSeconds)	const;
};

#endif // TIMER_WINDOWS_H_
