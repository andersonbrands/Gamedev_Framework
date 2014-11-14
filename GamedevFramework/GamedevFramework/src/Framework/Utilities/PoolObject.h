/***************************************************************************************
*	Title: PoolObject.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef POOL_OBJECT_H_
#define POOL_OBJECT_H_

class PoolObject {
    private:
        bool free_;
    public:
        PoolObject();
        virtual ~PoolObject();

        bool isFree() const {
            return free_;
        }

        void setIsFree(bool free) {
            free_ = free;
        }
};

#endif // POOL_OBJECT_H_
