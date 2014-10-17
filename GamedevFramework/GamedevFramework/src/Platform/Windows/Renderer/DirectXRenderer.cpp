/***************************************************************************************
*	Title: DirectXRenderer.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "DirectXRenderer.h"
#include "../../../Framework/EventManager/EventManager.h"
#include "../../../Framework/Platform/Platform.h"

DirectXRenderer::DirectXRenderer(const unsigned int priority) : iRenderer(priority), pWin_(nullptr) {
    registerEvent(ev::PRE_RENDER_EVENT);
    registerEvent(ev::RENDER_EVENT);
    registerEvent(ev::POST_RENDER_EVENT);

    assert(Platform::getInstancePtr());
    pWin_ = static_cast<WindowsPlatform*>(Platform::getInstancePtr());
    assert(pWin_);
}

DirectXRenderer::~DirectXRenderer() {
    unregisterEvent(ev::PRE_RENDER_EVENT);
    unregisterEvent(ev::RENDER_EVENT);
    unregisterEvent(ev::POST_RENDER_EVENT);
}


void DirectXRenderer::setTransform(const Matrix4& matrix) {
    D3DMATRIX worldMat;

    worldMat._11 = matrix.get(0);
    worldMat._12 = matrix.get(1);
    worldMat._13 = matrix.get(2);
    worldMat._14 = matrix.get(12);// X
    worldMat._21 = matrix.get(4);
    worldMat._22 = matrix.get(5);
    worldMat._23 = matrix.get(6);
    worldMat._24 = matrix.get(13);// Y
    worldMat._31 = matrix.get(8);
    worldMat._32 = matrix.get(9);
    worldMat._33 = matrix.get(10);
    worldMat._34 = matrix.get(14);// Z
    worldMat._41 = matrix.get(3);// x'
    worldMat._42 = matrix.get(7);// y'
    worldMat._43 = matrix.get(11);// z'
    worldMat._44 = matrix.get(15);


    pWin_->getDevice()->SetTransform(D3DTS_WORLD, &worldMat);
}


void DirectXRenderer::setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation ) {
    // Set up matrices to control transformations and transform
    D3DXMATRIX WorldMat, TranslateMat, ScaleMat, RotateMat;
    D3DXMatrixTranslation(&TranslateMat, pos.getX(), pos.getY(), pos.getZ());
    D3DXMatrixScaling(&ScaleMat,scale.getX(),scale.getY(),scale.getZ());
    D3DXMatrixIdentity(&WorldMat);
    if(rotation.getX() != 0) {
        D3DXMatrixRotationX(&RotateMat, rotation.getX());
        D3DXMatrixMultiply( &WorldMat, &WorldMat, &RotateMat);
    }
    if(rotation.getY() != 0) {
        D3DXMatrixRotationY(&RotateMat, rotation.getY());
        D3DXMatrixMultiply( &WorldMat, &WorldMat, &RotateMat);
    }
    if(rotation.getZ() != 0) {
        D3DXMatrixRotationZ(&RotateMat, rotation.getZ());
        D3DXMatrixMultiply( &WorldMat, &WorldMat, &RotateMat);
    }
    D3DXMatrixMultiply(&WorldMat, &WorldMat, &ScaleMat);
    D3DXMatrixMultiply( &WorldMat, &WorldMat, &TranslateMat);

    pWin_->getDevice()->SetTransform(D3DTS_WORLD, &WorldMat);
}

void DirectXRenderer::setupViewMatrices(const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector /*= Vector3(0.0f, 0.1f, 0.0f) */) {
    // Set up the view matrix.
    // This defines which way the 'camera' will look at, and which way is up.
    D3DXVECTOR3 vCamera(camPos.getX(), camPos.getY(), camPos.getZ());
    D3DXVECTOR3 vLookat(camTarget.getX(), camTarget.getY(), camTarget.getZ());
    D3DXVECTOR3 vUpVector(upVector.getX(), upVector.getY(), upVector.getZ());
    D3DXMATRIX matView;
    D3DXMatrixLookAtLH( &matView, &vCamera, &vLookat, &vUpVector);
    pWin_->getDevice()->SetTransform(D3DTS_VIEW, &matView);

    // Set up the projection matrix.
    // This transforms 2D geometry into a 3D space.
    float w = (float) pWin_->getBufferWidth();
    float h = (float) pWin_->getBufferHeight();
    D3DXMATRIX matProj;
    D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI/4, w/h, 1.0f, 400.0f);
    pWin_->getDevice()->SetTransform(D3DTS_PROJECTION, &matProj);
}


void DirectXRenderer::drawLine(const Vector3& from, const Vector3& to, const ColorARGB& color/* = ColorARGB(1.0f, 1.0f, 1.0f, 1.0f)*/) {
    const DWORD vertex_difuse(D3DFVF_XYZ | D3DFVF_DIFFUSE);

    VertexDiffuse line_vertices[2];

    int r(int(color.r*255)), g(int(color.g*255)), b(int(color.b*255));

    line_vertices[0].x = from.getX();
    line_vertices[0].y = from.getY();
    line_vertices[0].z = from.getZ();
    line_vertices[0].diffuse = D3DCOLOR_XRGB (r, g, b);

    line_vertices[1].x = to.getX();
    line_vertices[1].y = to.getY();
    line_vertices[1].z = to.getZ();
    line_vertices[1].diffuse = D3DCOLOR_XRGB (r, g, b);

    DWORD renderState = pWin_->getDevice()->GetRenderState(D3DRS_LIGHTING, &renderState);

    pWin_->getDevice()->SetRenderState(D3DRS_LIGHTING, FALSE);

    pWin_->getDevice()->SetFVF(vertex_difuse);
    pWin_->getDevice()->DrawPrimitiveUP(D3DPT_LINELIST, 2, line_vertices, sizeof(VertexDiffuse));

    pWin_->getDevice()->SetRenderState(D3DRS_LIGHTING, renderState);
}

void DirectXRenderer::drawAABB(const Vector3& min, const Vector3& max, const ColorARGB& color) {
    setTransform(Vector3(0), Vector3(1), Vector3(0));

    Vector3 st, en;

    st = Vector3(min.getX(), max.getY(), min.getZ());
    en = Vector3(min.getX(), max.getY(), max.getZ());
    drawLine(st, en, color);

    st = en;
    en = Vector3(max.getX(), max.getY(), max.getZ());
    drawLine(st, en, color);
    st = en;
    en = Vector3(max.getX(), max.getY(), min.getZ());
    drawLine(st, en, color);
    st = en;
    en = Vector3(min.getX(), max.getY(), min.getZ());
    drawLine(st, en, color);

    st = Vector3(min.getX(), min.getY(), min.getZ());
    en = Vector3(min.getX(), min.getY(), max.getZ());
    drawLine(st, en, color);
    st = en;
    en = Vector3(max.getX(), min.getY(), max.getZ());
    drawLine(st, en, color);
    st = en;
    en = Vector3(max.getX(), min.getY(), min.getZ());
    drawLine(st, en, color);
    st = en;
    en = Vector3(min.getX(), min.getY(), min.getZ());
    drawLine(st, en, color);

    st = Vector3(min.getX(), min.getY(), min.getZ());
    en = Vector3(min.getX(), max.getY(), min.getZ());
    drawLine(st, en, color);
    st = Vector3(max.getX(), min.getY(), min.getZ());
    en = Vector3(max.getX(), max.getY(), min.getZ());
    drawLine(st, en, color);
    st = Vector3(max.getX(), min.getY(), max.getZ());
    en = Vector3(max.getX(), max.getY(), max.getZ());
    drawLine(st, en, color);
    st = Vector3(min.getX(), min.getY(), max.getZ());
    en = Vector3(min.getX(), max.getY(), max.getZ());
    drawLine(st, en, color);
}

bool DirectXRenderer::start() {
    pWin_->getDevice()->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
    return true;
}

void DirectXRenderer::onSuspend() {
    setSuspended(true);
}

void DirectXRenderer::onResume() {
    setSuspended(false);
}
void DirectXRenderer::stop() {
    setCanKill(true);
}

void DirectXRenderer::update() {
    if (!isSuspended()) {
        sendEvent(ev::PRE_RENDER_EVENT);

        pWin_->getDevice() -> Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(50, 50, 50), 1.0f, 0);

        if (SUCCEEDED(pWin_->getDevice()->BeginScene())) {

            sendEvent(ev::RENDER_EVENT);

            pWin_->getDevice()->EndScene();
        }
        // Present the backbuffer to the display.
        pWin_->getDevice() -> Present(NULL, NULL, NULL, NULL);

        sendEvent(ev::POST_RENDER_EVENT);
    }
}