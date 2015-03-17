/***************************************************************************************
*	Title: SpriteIds.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SPRITE_IDS_H_
#define SPRITE_IDS_H_

#include "../../Framework/Renderer/Sprite/SpriteId.h"
#include "TextureIds.h"

using namespace Framework;

namespace spr {
    /*
    static const SpriteInfo SPRITE_NAME				= {
    	id,
    	uuWidth,
    	vvHeight,
    	textureId,
    	align
    }
    */
    static const SpriteInfo SAMPLE					= {
        0,
        Vector3(0.0f, 0.0f, 1.0f),
        Vector3(1.0f, 1.0f, 1.0f),
        tex::SAMPLE_TEXTURE.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo MAIN_MENU_BACKGROUND	= {
        1,
        Vector3(0.0f, 0.937f, 48.0f),
        Vector3(0.0f, 0.625f, 32.0f),
        tex::MAIN_MENU_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo MAIN_MENU_GAME_NAME		= {
        2,
        Vector3(0.0f, 0.468f, 24.0f),
        Vector3(0.625f, 0.781f, 8.0f),
        tex::MAIN_MENU_SPR_SHEET.id,
        SpriteAlign::CENTER_TOP
    };

    static const SpriteInfo MAIN_MENU_PLAY_BT		= {
        3,
        Vector3(0.0f, 0.195f, 10.0f),
        Vector3(0.781f, 0.843f, 3.2f),
        tex::MAIN_MENU_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo MAIN_MENU_SETTINGS_BT	= {
        4,
        Vector3(0.0f, 0.195f, 10.0f),
        Vector3(0.843f, 0.906f, 3.2f),
        tex::MAIN_MENU_SPR_SHEET.id,
        SpriteAlign::CENTER_TOP
    };

    static const SpriteInfo STAR_SPRITE				= {
        5,
        Vector3(0.9903f, 1.0f, 1.0f),
        Vector3(0.0f, 0.0097f, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo PLAYER_SHIP_SPRITE		= {
        6,
        Vector3(0.0f, 0.0566f, 2.9f),
        Vector3(0.0f, 0.0468f, 2.4f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo ENEMY_A_SHIP_SPRITE		= {
        7,
        Vector3(0.0f, 0.0585f, 3.0f),
        Vector3(0.0468f, 0.1053f, 3.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER
    };
}

#endif // SPRITE_IDS_H_
