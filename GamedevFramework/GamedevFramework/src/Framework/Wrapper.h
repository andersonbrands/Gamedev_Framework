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

namespace Framework {

    typedef WindowsPlatform		wPlatform;

    typedef DirectXRenderer		wRenderer;

    typedef TimerWindows		wTimer;
}



#endif // WRAPPER_H_