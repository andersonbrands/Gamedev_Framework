/***************************************************************************************
*	Title: BulletManager.h
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#ifndef BULLET_MANAGER_H_
#define BULLET_MANAGER_H_

#include "../../Framework/Utilities/PoolAllocator.h"

using namespace Framework;

template <typename T>
class BulletManager : public PoolAllocator<T> {
    private:
    public:
        BulletManager(int totalObjects) : PoolAllocator(totalObjects) {}
        virtual ~BulletManager() {}

        virtual void init() {
            PoolAllocator::init();
        }

        void spawnBullet(float x, float y) {
            auto next(getNextFree());

            if (next) {
                next->spawn(x, y);
            }
        }
};

#endif // BULLET_MANAGER_H_
