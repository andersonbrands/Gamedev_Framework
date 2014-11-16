/***************************************************************************************
*	Title: Renderable.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

class Renderable {
    private:
    public:
        Renderable();
        virtual ~Renderable();

        virtual void render() const = 0;
};

#endif // RENDERABLE_H_
