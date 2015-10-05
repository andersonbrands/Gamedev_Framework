/***************************************************************************************
*	Title: EnemyManager.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "EnemyManager.h"
#include "../../../Framework/Utilities/Utils.h"
#include "../../../Framework/EventManager/EventManager.h"


EnemyManager::EnemyManager() : readyToSpawn_(false), paused_(true), bulletManager_(25) {

}

EnemyManager::~EnemyManager() {
    // detach events
    detachEvent(ev::id::UPDATE, *this);
}

void EnemyManager::init() {
    for (int i(0); i < 5; ++i) {
        enemyA_[i].init();
    }
    for (int i(0); i < 3; ++i) {
        enemyB_[i].init();
    }
    for (int i(0); i < 5; ++i) {
        enemyC_[i].init();
    }
    readyToSpawn_ = true;
    setPaused(false);

    bulletManager_.init();

    // attach events
    attachEvent(ev::id::UPDATE, *this);
}

bool EnemyManager::areAllEnemiesGone() const {
    for (int i(0); i < 5; ++i) {
        if (enemyA_[i].isActive())
            return false;
    }
    for (int i(0); i < 3; ++i) {
        if (enemyB_[i].isActive())
            return false;
    }
    for (int i(0); i < 5; ++i) {
        if (enemyC_[i].isActive())
            return false;
    }

    return true;
}

void EnemyManager::update() {
    if (!isPaused()) {
        if (readyToSpawn_) {
            // try to spawn
            if (rand_int(0, 1000) < 40)
                spawnEnemies();

        } else {
            // check enemies are gone
            if (areAllEnemiesGone()) {
                readyToSpawn_ = true;
            }
        }
    }
}

void EnemyManager::spawnEnemies() {
    int i(rand_int(1, 3));

    switch (i) {
        case 1:
            enemyA_[0].spawn(0.0f, 18.0f);

            if (!rand_int(0,2)) {
                enemyA_[1].spawn(-12.0f, 18.0f);
                enemyA_[2].spawn(12.0f, 18.0f);
            } else {
                enemyA_[1].spawn(-8.0f, 18.0f);
                enemyA_[2].spawn(8.0f, 18.0f);
                enemyA_[3].spawn(-16.0f, 18.0f);
                enemyA_[4].spawn(16.0f, 18.0f);
            }
            break;
        case 2:
            enemyB_[0].spawn(0.0f, 18.0f, Direction::DOWN);
            enemyB_[1].spawn(-4.0f, 18.0f, Direction::LEFT);
            enemyB_[2].spawn(4.0f, 18.0f, Direction::RIGHT);
            break;
        case 3:
            enemyC_[0].spawn(0.0f, 18.0f);

            if (!rand_int(0,2)) {
                enemyC_[1].spawn(-12.0f, 18.0f);
                enemyC_[2].spawn(12.0f, 18.0f);
            } else {
                enemyC_[1].spawn(-8.0f, 18.0f);
                enemyC_[2].spawn(8.0f, 18.0f);
                enemyC_[3].spawn(-16.0f, 18.0f);
                enemyC_[4].spawn(16.0f, 18.0f);
            }
            break;
        default:
            return;
    }
    readyToSpawn_ = false;
}

void EnemyManager::handleEvent(Event* pEvent) {
    switch (pEvent->getID()) {
        case ev::id::UPDATE: {
            update();
            break;
        }

        default:
            break;

    }
}