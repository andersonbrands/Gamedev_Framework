/***************************************************************************************
*	Title: Platform.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "Platform.h"

namespace Framework {
    bool Platform::isClosing_	= false;

    Platform::Platform(const unsigned int priority)
        :	wPlatform(priority) {
        attachEvent(ev::id::PLATFORM_CLOSE, *this);
    }

    Platform::~Platform() {
    }

    void Platform::handleEvent(Event* pEvent) {
        switch (pEvent->getID()) {
            case ev::id::PLATFORM_CLOSE:
                isClosing_ = true;
                break;
            default:
                break;
        }
    }
}
