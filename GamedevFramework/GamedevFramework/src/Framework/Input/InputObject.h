/***************************************************************************************
*	Title: InputObject.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef INPUT_OBJECT_H_
#define INPUT_OBJECT_H_

namespace Framework {

    class InputObject {
        private:
        public:
            InputObject() {}
            virtual ~InputObject() {}

            virtual void update() = 0;
    };

}

#endif // INPUT_OBJECT_H_
