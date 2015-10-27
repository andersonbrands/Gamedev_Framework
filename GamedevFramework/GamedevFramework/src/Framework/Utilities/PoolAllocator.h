/***************************************************************************************
*	Title: PoolAllocator.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <vector>
#include <algorithm>
#include "../../MyAssert.h"
#include "Functors.h"

namespace Framework {

    using namespace std;

    template <typename T>
    class PoolAllocator {
        protected:
            // total objects held in array
            int totalObjects_;
            //array of all objects
            vector<T*> objects_;
            typedef typename vector<T*>::iterator Iter;

        public:
            PoolAllocator<T>(int totalObjects):totalObjects_(totalObjects) {
                assert(objects_.empty());
                objects_.insert(objects_.begin(), totalObjects_, nullptr);

                for(int i=0; i<totalObjects_; ++i) {
                    objects_[i] = new T();
                }
            };
            virtual ~PoolAllocator<T>() {
                for(int i=0; i<(int)objects_.size(); ++i)
                    delete objects_[i];
                objects_.clear();
            };

            virtual void init() {
                PoolObjectInit poolObjectInit;
                for_each(objects_.begin(), objects_.end(), poolObjectInit);
            }

            int getTotalObjects() {
                return totalObjects_;
            };

            std::vector<T*> &getObjects() {
                return objects_;
            };

            T* getNextFree() {
                PoolObjectIsFree free;
                Iter iter = find_if(objects_.begin(), objects_.end(), free);
                if (iter != objects_.end())
                    return *iter;
                else
                    return nullptr;
            }
    };

}

#endif