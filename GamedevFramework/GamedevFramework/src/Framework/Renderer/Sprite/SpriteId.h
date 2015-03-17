/***************************************************************************************
*	Title: SpriteId.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SPRITE_ID_H_
#define SPRITE_ID_H_

#include "iSprite.h"
#include "../../Math/Vector3.h"
#include "../Texture/TextureId.h"


namespace Framework {

    typedef unsigned int SpriteId;

    typedef struct {
        SpriteId id;
        Vector3 uuWidth;
        Vector3 vvHeight;
        TextureId textureId;
        SpriteAlign align;
    } SpriteInfo;

}
#endif // SPRITE_ID_H_
