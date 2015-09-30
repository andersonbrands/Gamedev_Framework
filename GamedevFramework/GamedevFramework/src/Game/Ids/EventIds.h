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
            // static const EventId EVENT_NAME			= EVENT_ID_OFFSET + value;
            static const EventId PLAY_BT_PRESSED		= EVENT_ID_OFFSET + 1;
            static const EventId SETTINGS_BT_PRESSED	= EVENT_ID_OFFSET + 2;
            static const EventId BACK_TO_MAIN_MENU		= EVENT_ID_OFFSET + 3;
            static const EventId SPAWN_ENEMY_BULLET		= EVENT_ID_OFFSET + 4;
            static const EventId GAME_OVER_SCREEN		= EVENT_ID_OFFSET + 5;

            // player ship input events
            static const EventId PS_MV_LEFT				= EVENT_ID_OFFSET + 6;
            static const EventId PS_MV_UP				= EVENT_ID_OFFSET + 7;
            static const EventId PS_MV_RIGHT			= EVENT_ID_OFFSET + 8;
            static const EventId PS_MV_DOWN				= EVENT_ID_OFFSET + 9;
            static const EventId PS_SHOOT				= EVENT_ID_OFFSET + 10;
        }

        namespace data {

            class SpawnEnemyBullet {
                public:
                    float x;
                    float y;
            };
            class ReadOrWriteToFromFile {
                public:
                    bool readFrom;
                    bool writeTo;
                    void setAll(bool flag) {
                        readFrom = flag;
                        writeTo  = flag;
                    }
            };
            class PlayerInputData {
                public:
                    bool left;
                    bool up;
                    bool right;
                    bool down;
                    bool shoot;

                    void setAll(bool flag) {
                        left	= flag;
                        up		= flag;
                        right	= flag;
                        down	= flag;
                        shoot	= flag;
                    }
            };

        }
    }
}

#endif // EVENT_IDS_H_
