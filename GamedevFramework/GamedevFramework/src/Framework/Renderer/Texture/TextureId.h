/***************************************************************************************
*	Title: TextureId.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef TEXTURE_ID_H_
#define TEXTURE_ID_H_
#include <string>

namespace Framework {

    typedef unsigned int TextureId;

    typedef struct {
        TextureId id;
        std::string name;
    } TextureIdAndName;

    namespace tex {
        //static const TextureIdAndName TEXTURE_NAME	= { id, name };
        static const TextureIdAndName SAMPLE		= { 0, "sample.png" };
    }
}

#endif // TEXTURE_ID_H_
