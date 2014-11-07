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

}

#endif // TEXTURE_ID_H_
