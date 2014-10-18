/***************************************************************************************
*	Title: SpriteD3D.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef SPRITE_D3D_H_
#define SPRITE_D3D_H_

#include "../../../../Framework/Renderer/Sprite/iSprite.h"
#include <d3dx9.h>

using namespace Framework;

class SpriteD3D : public iSprite {
    private:
        struct SPRITE_VERTEX {
            D3DXVECTOR3 position;
            //D3DXVECTOR3 normal;
            FLOAT u, v;
        };
        static const DWORD FVF_SPRITE_VERTEX;

        SPRITE_VERTEX *vertices_;

        LPDIRECT3DVERTEXBUFFER9 pVertexBuffer_;

        void createVertexBuffer();

    protected:
        virtual void applySettings();

    public:
        SpriteD3D();
        virtual ~SpriteD3D();

        virtual void setUVCoords(int index, float u, float v);
        virtual void render();

        virtual void setup(Texture *texture, SpriteAlign align, float h, float w) = 0;
};

#endif // SPRITE_D3D_H_
