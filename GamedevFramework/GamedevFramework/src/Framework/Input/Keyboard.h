/***************************************************************************************
*	Title: Keyboard.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "InputObject.h"
#include "../Wrapper.h"

namespace Framework {

    class Keyboard : public wKeyboard {
        private:
        public:
            Keyboard();
            virtual ~Keyboard();
    };

}

#endif // KEYBOARD_H_
