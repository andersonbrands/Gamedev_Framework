/***************************************************************************************
*	Title: Timer.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "../Wrapper.h"
#include "../EventManager/EventHandler.h"
#include "../Utilities/Singleton.h"

namespace Framework {
    class Timer : public wTimer, public EventHandler, public Singleton<Timer> {
        public:

            Timer(const unsigned int priority);
            virtual ~Timer();

            // task interface
            virtual bool	start();
            virtual void 	onSuspend();
            virtual void 	update();
            virtual void 	onResume();
            virtual void 	stop();

            // timer interface
            virtual float		getTimeFrame() const;
            virtual float		getTimeSim() const;
            virtual void		setSimMultiplier(const float simMultiplier);
            virtual float		getSimMultiplier();
            virtual float		getFPS() const;
            virtual float		getGameTime() const;
            virtual TimeUnits	getUpdateFrame() const;

            virtual void handleEvent(Event* pEvent);

            const int UPDATES_PER_SECOND;

        private:
            TimeUnits	timeLastFrame_;
            int			frameDt_;// delta frame in miliseconds
            float		simulationMultiplier_;
            TimeUnits	gameTime_;// game time in miliseconds

            // used to have a fixed frame rate
            long long currentUpdate_;
            long long nextUpdate_;

    };

    inline float Timer::getFPS() const {
        return 1000.0f / (float)frameDt_;
    }

    // get total game time in seconds
    inline float Timer::getGameTime() const {
        const float MILI_TO_SECONDS_MULTIPLIER = 0.001f;
        return gameTime_ * MILI_TO_SECONDS_MULTIPLIER;
    }

    // get delta frame in seconds
    inline float Timer::getTimeFrame() const {
        const float MILI_TO_SECONDS_MULTIPLIER = 0.001f;
        return frameDt_ * MILI_TO_SECONDS_MULTIPLIER;
    }

    // get delta simulation time in seconds
    inline float Timer::getTimeSim() const {
        return getTimeFrame() * simulationMultiplier_;
    }

    inline void Timer::setSimMultiplier(const float simMultiplier) {
        simulationMultiplier_ = simMultiplier;
    }

    inline float Timer::getSimMultiplier() {
        return simulationMultiplier_;
    }
}

#endif // TIMER_H_
