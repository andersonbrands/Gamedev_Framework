/***************************************************************************************
*	Title: iTexture.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef I_TEXTURE_H_
#define I_TEXTURE_H_

#include <string>

using namespace std;

namespace Framework {

    class iTexture {
        private:
        public:
			iTexture() {}
			virtual ~iTexture() {}

            virtual void load(const string &path, const string &filename) = 0;
    };

}

#endif // I_TEXTURE_H_
