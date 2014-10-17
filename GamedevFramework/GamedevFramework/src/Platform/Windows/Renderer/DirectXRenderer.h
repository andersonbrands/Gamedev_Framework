/***************************************************************************************
*	Title: DirectXRenderer.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef DIRECTX_RENDERER_H_
#define DIRECTX_RENDERER_H_

#include "../../../Framework/Renderer/iRenderer.h"
#include "../WindowsPlatform.h"
#include <d3dx9.h>

using namespace Framework;

class DirectXRenderer : public iRenderer {

    private:
        typedef struct VertexDiffuse {
            float x;
            float y;
            float z;
            D3DCOLOR diffuse;
        };

        WindowsPlatform* pWin_;

    public:
        explicit DirectXRenderer(const unsigned int priority);
        virtual ~DirectXRenderer();

        virtual void DirectXRenderer::setTransform(const Matrix4& matrix);
        virtual void DirectXRenderer::setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation);
        virtual void DirectXRenderer::setupViewMatrices(const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector = Vector3(0.0f, 0.1f, 0.0f) );

        virtual void drawLine(const Vector3& from, const Vector3& to, const ColorARGB& color = ColorARGB(1.0f, 1.0f, 1.0f, 1.0f));
        virtual void drawAABB(const Vector3& min, const Vector3& max, const ColorARGB& color);

        virtual void update();
        virtual bool start();

        virtual void onSuspend();
        virtual void onResume();
        virtual void stop();
};


#endif // DIRECTX_RENDERER_H_
