/***************************************************************************************
*	Title: iRenderer.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef I_RENDERER_H_
#define I_RENDERER_H_

#include "../Kernel/Task.h"

#include "../Math/Vector3.h"
#include "../Math/Matrix4.h"
#include "../Utilities/Color.h"

namespace Framework {

    class iRenderer : public Task {
        private:
        public:
            explicit iRenderer(const unsigned int priority): Task( priority ) {}
            virtual ~iRenderer() {}

            virtual void setTransform(const Matrix4& matrix) = 0;
            virtual void setTransform(const Vector3& pos, const Vector3& scale, const Vector3& rotation) = 0;
            virtual void setupViewMatrix(const Vector3& camPos, const Vector3& camTarget, const Vector3& upVector = Vector3(0.0f, 0.1f, 0.0f)) = 0;

            virtual void setupFovLHPerspectiveProjectionMatrix(float verticalFieldOfView, float aspectRatio, float zNear, float zFar) = 0;
            virtual void setupLHPerspectiveProjectionMatrix(float w, float h, float zNear, float zFar) = 0;
            virtual void setupLHOrthogonalProjectionMatrix(float w, float h, float zNear, float zFar) = 0;

            virtual void drawLine(const Vector3& from, const Vector3& to, const ColorARGB& color = ColorARGB(1.0f, 1.0f, 1.0f, 1.0f)) = 0;
            virtual void drawAABB(const Vector3& min, const Vector3& max, const ColorARGB& color) = 0;

            virtual bool start() = 0;
            virtual void onSuspend() = 0;
            virtual void update() = 0;
            virtual void onResume() = 0;
            virtual void stop() = 0;
    };
}

#endif // I_RENDERER_H_
