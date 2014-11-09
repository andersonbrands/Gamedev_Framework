/***************************************************************************************
*	Title: SpriteD3D.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "SpriteD3D.h"
#include "../../../../Framework/Platform/Platform.h"
#include "../../../../Framework/Renderer/Texture/Texture.h"

const DWORD SpriteD3D::FVF_SPRITE_VERTEX = (D3DFVF_XYZ /*| D3DFVF_NORMAL*/ | D3DFVF_TEX1);

SpriteD3D::SpriteD3D() : vertices_(new SPRITE_VERTEX[4]), pVertexBuffer_(nullptr) {

}

SpriteD3D::~SpriteD3D() {
    if (vertices_) {
        delete[] vertices_;
        vertices_ = nullptr;
    }
    if (pVertexBuffer_) {
        pVertexBuffer_->Release();
        pVertexBuffer_ = nullptr;
    }
}

void SpriteD3D::setUVCoords(float minU, float maxU, float minV, float maxV) {
    setUVCoords(0 , minU, minV);
    setUVCoords(1 , maxU, minV);
    setUVCoords(2 , maxU, maxV);
    setUVCoords(3 , minU, maxV);
}

void SpriteD3D::setUVCoords(int index, float u, float v) {
    vertices_[index].u = u;
    vertices_[index].v = v;
}

void SpriteD3D::render() {
    assert(Platform::getInstancePtr());
    WindowsPlatform* pWin(static_cast<WindowsPlatform*>(Platform::getInstancePtr()));
    assert(pWin);

    TextureD3D *pTexture = static_cast<TextureD3D*>( pTexture_ );

    pWin->getDevice()->SetTexture(0, *pTexture->getTexture());

    pWin->getDevice()->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
    pWin->getDevice()->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
    pWin->getDevice()->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
    pWin->getDevice()->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

    pWin->getDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

    pWin->getDevice()->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);
    pWin->getDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

    pWin->getDevice()->SetStreamSource(0, pVertexBuffer_, 0, sizeof(SPRITE_VERTEX));
    pWin->getDevice()->SetFVF(FVF_SPRITE_VERTEX);
    pWin->getDevice()->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

    pWin->getDevice()->SetTexture(0, nullptr);
}

void SpriteD3D::applySettings() {
    // top left
    vertices_[0].position = D3DXVECTOR3(0.0f,height_,0.0f);
    // top right
    vertices_[1].position = D3DXVECTOR3(width_,height_,0.0f);
    // bottom right
    vertices_[2].position = D3DXVECTOR3(width_,0.0f,0.0f);
    // bottom left
    vertices_[3].position = D3DXVECTOR3(0.0f,0.0f,0.0f);

    D3DXVECTOR3 normal(0,0,-1);

    // TODO: use normal
    /*
    vertices_[0].normal = normal;
    vertices_[1].normal = normal;
    vertices_[2].normal = normal;
    vertices_[3].normal = normal;
    */

    D3DXVECTOR3 offset(0, 0, 0);

    switch (align_) {
        case SpriteAlign::BOTTOM_LEFT:
            // no offset needed
            createVertexBuffer();
            return;
        case SpriteAlign::TOP_LEFT:
            offset = vertices_[0].position;
            break;
        case SpriteAlign::TOP_RIGHT:
            offset = vertices_[1].position;
            break;
        case SpriteAlign::BOTTOM_RIGHT:
            offset = vertices_[2].position;
            break;
        case SpriteAlign::CENTER:
            offset = D3DXVECTOR3(width_/2.0f, height_/2.0f, 0);
            break;
        case SpriteAlign::CENTER_LEFT:
            offset = D3DXVECTOR3(0, height_/2.0f, 0);
            break;
        case SpriteAlign::CENTER_TOP:
            offset = D3DXVECTOR3(width_/2.0f, height_, 0);
            break;
        case SpriteAlign::CENTER_RIGHT:
            offset = D3DXVECTOR3(width_, height_/2.0f, 0);
            break;
        case SpriteAlign::CENTER_BOTTOM:
            offset = D3DXVECTOR3(width_/2.0f, 0, 0);
            break;
        default:
            return;
    }

    vertices_[0].position -= offset;
    vertices_[1].position -= offset;
    vertices_[2].position -= offset;
    vertices_[3].position -= offset;

    createVertexBuffer();
}

void SpriteD3D::createVertexBuffer() {

    const int numVertices(6);
    const int bufferSize(numVertices * sizeof(SPRITE_VERTEX));

    assert(Platform::getInstancePtr());
    WindowsPlatform* pWin(static_cast<WindowsPlatform*>(Platform::getInstancePtr()));
    assert(pWin);

    assert(!FAILED(pWin->getDevice()->CreateVertexBuffer(bufferSize, 0, FVF_SPRITE_VERTEX, D3DPOOL_DEFAULT, &pVertexBuffer_, nullptr)));

    SPRITE_VERTEX *pVertices( nullptr);

    assert(!FAILED(pVertexBuffer_->Lock(0, 0, (void**)&pVertices, 0)));

    pVertices[0] = vertices_[3];
    pVertices[1] = vertices_[0];
    pVertices[2] = vertices_[1];

    pVertices[3] = vertices_[3];
    pVertices[4] = vertices_[1];
    pVertices[5] = vertices_[2];

    pVertexBuffer_->Unlock();
}

