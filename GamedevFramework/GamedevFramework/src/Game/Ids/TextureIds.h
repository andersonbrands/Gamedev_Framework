/***************************************************************************************
*	Title: TextureIds.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef TEXTURE_IDS_H_
#define TEXTURE_IDS_H_

#include "../../Framework/Renderer/Texture/TextureId.h"

using namespace Framework;

namespace tex {
    //static const TextureIdAndName TEXTURE_NAME	= { id, name };
    static const TextureIdAndName SAMPLE				= { 0, "sample.png" };
    static const TextureIdAndName MAIN_MENU_SPR_SHEET		= { 1, "main_menu_sprite_sheet.png" };
    static const TextureIdAndName IN_GAME_SPR_SHEET		= { 2, "in_game_sprite_sheet.png" };
}

#endif // TEXTURE_IDS_H_
