/***************************************************************************************
*	Title: Renderer.h
*	Author: Brandao, Anderson
*	Date: 2014
*
*	Based on original by Bruce Sutherland available at http://www.apress.com/9781430258308 (2014)
*
***************************************************************************************/

#ifndef RENDERER_H_
#define RENDERER_H_

#include "../Kernel/Task.h"
#include "../Wrapper.h"
#include "../Utilities/Singleton.h"

namespace Framework {

    class Renderer : public wRenderer, public Singleton<Renderer> {
        private:
        public:
            explicit Renderer(const unsigned int priority);
            virtual ~Renderer();
    };
}

#endif // RENDERER_H_
