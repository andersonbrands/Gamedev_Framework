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

        virtual void setTransform(const Matrix4& matrix);
        virtual void setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation);
        virtual void setupViewMatrix(const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector = Vector3(0.0f, 0.1f, 0.0f) );

        virtual void setupFovLHPerspectiveProjectionMatrix(float verticalFieldOfView, float aspectRatio, float zNear, float zFar);
        virtual void setupLHPerspectiveProjectionMatrix(float w, float h, float zNear, float zFar);
        virtual void setupLHOrthogonalProjectionMatrix(float w, float h, float zNear, float zFar);

        virtual void drawLine(const Vector3& from, const Vector3& to, const ColorARGB& color = ColorARGB(1.0f, 1.0f, 1.0f, 1.0f));
        virtual void drawAABB(const Vector3& min, const Vector3& max, const ColorARGB& color);

        virtual void update();
        virtual bool start();

        virtual void onSuspend();
        virtual void onResume();
        virtual void stop();
};


#endif // DIRECTX_RENDERER_H_
