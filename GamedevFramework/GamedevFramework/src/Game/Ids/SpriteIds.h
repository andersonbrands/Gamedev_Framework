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
        Vector3(0.9903f, 1.0f, 0.6f),
        Vector3(0.0f, 0.0097f, 0.6f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo PLAYER_SHIP_SPRITE		= {
        6,
        Vector3(0.0f, 0.0566f, 2.9f*0.75f),
        Vector3(0.0f, 0.0468f, 2.4f*0.75f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo ENEMY_A_SHIP_SPRITE		= {
        7,
        Vector3(0.0f, 0.0585f, 3.0f*0.75f),
        Vector3(0.0468f, 0.1053f, 3.0f*0.75f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo PLAYER_BULLET_SPRITE	= {
        8,
        Vector3(0.9843f, 0.9901f, 0.3f*0.75f),
        Vector3(0.0f, 0.0097f, 0.5f*0.75f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo ENEMY_BULLET_SPRITE		= {
        9,
        Vector3(0.9785f, 0.9844f, 0.3f*0.75f),
        Vector3(0.0f, 0.0097f, 0.5f*0.75f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo GAME_OVER_BACKGROUND	= {
        10,
        Vector3(0.0f, 0.937f, 48.0f),
        Vector3(0.0f, 0.625f, 32.0f),
        tex::GAME_OVER_SPR_SHEET.id,
        SpriteAlign::CENTER
    };

    static const SpriteInfo SCORE_TEXT				= {
        11,
        Vector3(96.5f/1024.0f, 200.75f/1024.0f, 1.0f * (104.25f/27.25f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };

	static const SpriteInfo ZERO_TEXT				= {
        12,
        Vector3(204.822f/1024.0f, 225.136f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo ONE_TEXT				= {
        13,
        Vector3(225.136f/1024.0f, 245.45f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo TWO_TEXT				= {
        14,
        Vector3(245.45f/1024.0f, 265.764f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo THREE_TEXT				= {
        15,
        Vector3(265.764f/1024.0f, 286.078f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo FOUR_TEXT				= {
        16,
        Vector3(286.078f/1024.0f, 306.392f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo FIVE_TEXT				= {
        17,
        Vector3(306.392f/1024.0f, 326.706f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo SIX_TEXT				= {
        18,
        Vector3(326.706f/1024.0f, 347.02f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo SEVEN_TEXT				= {
        19,
        Vector3(347.02f/1024.0f, 367.334f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo EIGHT_TEXT				= {
        20,
        Vector3(367.334f/1024.0f, 387.648f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };
	static const SpriteInfo NINE_TEXT				= {
        21,
        Vector3(387.648f/1024.0f, 407.962f/1024.0f, 1.0f * (12.517f/20.314f)),
        Vector3(996.75f/1024.0f, 1.0, 1.0f),
        tex::IN_GAME_SPR_SHEET.id,
        SpriteAlign::CENTER_LEFT
    };

}

#endif // SPRITE_IDS_H_
