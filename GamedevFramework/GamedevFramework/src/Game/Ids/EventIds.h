/***************************************************************************************
*	Title: EventIds.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef EVENT_IDS_H_
#define EVENT_IDS_H_

#include "../../Framework/EventManager/EventId.h"

using namespace Framework;

namespace game {
    namespace ev {
        namespace id {
            // static const EventId EVENT_NAME	= EVENT_ID_OFFSET + value;
            static const EventId PLAY_BT_PRESSED		= EVENT_ID_OFFSET + 1;
            static const EventId SETTINGS_BT_PRESSED	= EVENT_ID_OFFSET + 2;
            static const EventId BACK_TO_MAIN_MENU		= EVENT_ID_OFFSET + 3;
        }
    }
}

#endif // EVENT_IDS_H_
