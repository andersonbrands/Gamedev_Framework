/***************************************************************************************
*	Title: iKeyboard.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef I_KEYBOARD_H_
#define I_KEYBOARD_H_

#include "InputObject.h"

namespace Framework {

    class iKeyboard : public InputObject {
        private:
        public:
            iKeyboard() {}
            virtual ~iKeyboard() {}

            virtual void update() = 0;

            virtual bool isKeyDown(unsigned char charCode) = 0;
            virtual bool onKeyDown(unsigned char charCode) = 0;
            virtual bool onKeyUp(unsigned char charCode) = 0;
    };

}

#endif // I_KEYBOARD_H_
