/***************************************************************************************
*	Title: Wrapper.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef WRAPPER_H_
#define WRAPPER_H_

#include "../Platform/Windows/WindowsPlatform.h"
#include "../Platform/Windows/Renderer/DirectXRenderer.h"
#include "../Platform/Windows/Utilities/TimerWindows.h"
#include "../Platform/Windows/Input/D3dKeyboard.h"

namespace Framework {

    typedef WindowsPlatform		wPlatform;
    typedef DirectXRenderer		wRenderer;
    typedef TimerWindows		wTimer;
    typedef D3dKeyboard			wKeyboard;
}

#endif // WRAPPER_H_