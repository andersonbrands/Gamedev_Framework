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

namespace Framework {

    typedef WindowsPlatform		wPlatform;

    typedef DirectXRenderer		wRenderer;

}



#endif // WRAPPER_H_