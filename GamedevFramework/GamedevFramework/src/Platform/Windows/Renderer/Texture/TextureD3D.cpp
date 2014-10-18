/***************************************************************************************
*	Title: TextureD3D.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "TextureD3D.h"
#include "../../../../Framework/Platform/Platform.h"

TextureD3D::TextureD3D() : iTexture() {

}

TextureD3D::~TextureD3D() {
    if (texture_) {
        texture_->Release();
        texture_ = nullptr;
    }
}

void TextureD3D::load(const string &path, const string &filename) {
    assert(Platform::getInstancePtr());
    WindowsPlatform* pWin(static_cast<WindowsPlatform*>(Platform::getInstancePtr()));
    assert(pWin);
    assert(!FAILED(D3DXCreateTextureFromFile(pWin->getDevice(), (path+filename).c_str(), &texture_)));
}

