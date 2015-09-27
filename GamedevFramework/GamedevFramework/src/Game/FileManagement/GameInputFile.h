/***************************************************************************************
*	Title: GameInputFile.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef GAME_INPUT_FILE_H_
#define GAME_INPUT_FILE_H_

#include <iostream>
#include <fstream>
#include "../../Framework/EventManager/EventHandler.h"
#include "../../Framework/EventManager/EventManager.h"
#include "../Ids/EventIds.h"

using namespace std;
using namespace Framework;

class GameInputFile : public EventHandler {
    private:
        fstream file_;
        bool writeMode_;
        bool readMode_;

    public:
        GameInputFile();
        virtual ~GameInputFile();

        bool openWriteMode();
        bool openReadMode();
        void writeSingleEntry(const game::ev::data::PlayerInputData& pInputData);
        void readSingleEntry();
        bool close();

        bool isWriteMode();
        bool isReadMode();

        virtual void handleEvent(Event* pEvent);
};

#endif // GAME_INPUT_FILE_H_
