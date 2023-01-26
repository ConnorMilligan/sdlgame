#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "loaderParams.h"

class GameObject {
    protected:
        GameObject(const LoaderParams *pParams) {}
        virtual ~GameObject() {}
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void clean() = 0;
};

#endif
