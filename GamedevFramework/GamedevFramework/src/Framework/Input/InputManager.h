/***************************************************************************************
*	Title: InputManager.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original by Mark Featherstone (C) 2013 All Rights Reserved.
*
***************************************************************************************/

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "../Kernel/Task.h"
#include "../Utilities/Singleton.h"

#include "Keyboard.h"

namespace Framework {

    class InputManager : public Task, public Singleton<InputManager> {
        private:
            Keyboard* pKeyboard_;

        public:
            InputManager(const unsigned int priority);
            virtual ~InputManager();

            virtual bool start();
            virtual void onSuspend();
            virtual void update();
            virtual void onResume();
            virtual void stop();

            bool requestKeyboard();
            Keyboard* getKeyboard() {
                return pKeyboard_;
            }
    };

}

#endif // INPUT_MANAGER_H