/***************************************************************************************
*	Title: GameInputFile.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "GameInputFile.h"


GameInputFile::GameInputFile() : file_(), writeMode_(false), readMode_(false) {
    if (file_.is_open()) {
        file_.close();
    }
}

GameInputFile::~GameInputFile() {
    if (file_.is_open()) {
        file_.close();
    }
}

bool GameInputFile::openWriteMode() {
    writeMode_ = true;
    readMode_ = false;

    file_.open("inputdata.csv");
    if (file_.is_open()) {
        return true;
    } else {
        return false;
    }
}

bool GameInputFile::openReadMode() {
    writeMode_ = false;
    readMode_ = true;
    file_.open("inputdata.csv", ios::in);
    if (file_.is_open()) {
        return true;
    } else {
        return false;
    }
}

void GameInputFile::writeSingleEntry(const game::ev::data::PlayerInputData& pInputData) {
    if (file_.is_open()) {
        file_ << endl
              << pInputData.left	<<	","
              << pInputData.up		<<	","
              << pInputData.right	<<	","
              << pInputData.down	<<	","
              << pInputData.shoot;
    }
}

bool GameInputFile::isWriteMode() {
    return writeMode_;
}
bool GameInputFile::isReadMode() {
    return readMode_;
}

void GameInputFile::readSingleEntry() {
    game::ev::data::PlayerInputData pInput;
    char comma;

    if (file_.is_open() && !file_.eof()) {
        file_ >> pInput.left;
        file_ >> comma;
        file_ >> pInput.up;
        file_ >> comma;
        file_ >> pInput.right;
        file_ >> comma;
        file_ >> pInput.down;
        file_ >> comma;
        file_ >> pInput.shoot;

        if (pInput.left) {
            sendEvent(game::ev::id::PS_MV_LEFT);
        }
        if (pInput.up) {
            sendEvent(game::ev::id::PS_MV_UP);
        }
        if (pInput.right) {
            sendEvent(game::ev::id::PS_MV_RIGHT);
        }
        if (pInput.down) {
            sendEvent(game::ev::id::PS_MV_DOWN);
        }
        if (pInput.shoot) {
            sendEvent(game::ev::id::PS_SHOOT);
        }
    }
}

bool GameInputFile::close() {
    if (file_.is_open()) {
        file_.close();
    }
    return true;
}

void GameInputFile::handleEvent(Event* pEvent) {

}

