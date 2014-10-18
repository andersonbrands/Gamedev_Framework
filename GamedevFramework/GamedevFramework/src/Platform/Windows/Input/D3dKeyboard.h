/***************************************************************************************
*	Title: D3dKeyboard.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef D3D_KEYBOARD_H_
#define D3D_KEYBOARD_H_

#include "../../../Framework/Input/iKeyboard.h"

#ifndef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION 0x0800
#endif

#include <dinput.h>

using namespace Framework;

class D3dKeyboard : public iKeyboard {
    private:
        static const int BUFFER_SIZE = 256;			//keyboards are fixed size
        LPDIRECTINPUT8 mpDI_;						//main device context
        LPDIRECTINPUTDEVICE8 pDIKeyboardDevice_;	//keyboard interface

        char buffer_[BUFFER_SIZE];
        char lastBuffer_[BUFFER_SIZE];				//remember what was down previously for press+release

    public:
        D3dKeyboard();
        virtual ~D3dKeyboard();

        virtual void update();

        virtual bool isKeyDown(unsigned char charCode);
        virtual bool onKeyDown(unsigned char charCode);
        virtual bool onKeyUp(unsigned char charCode);
};

#endif // D3D_KEYBOARD_H_
