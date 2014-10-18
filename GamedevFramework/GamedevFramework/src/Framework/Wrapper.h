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
#include "../Platform/Windows/Renderer/Texture/TextureD3D.h"
#include "../Platform/Windows/Renderer/Sprite/SpriteD3D.h"

namespace Framework {

    typedef WindowsPlatform		wPlatform;
    typedef DirectXRenderer		wRenderer;
    typedef TimerWindows		wTimer;
    typedef D3dKeyboard			wKeyboard;
    typedef TextureD3D			wTexture;
    typedef SpriteD3D			wSprite;

}

#endif // WRAPPER_H_