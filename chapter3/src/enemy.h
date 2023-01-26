#ifndef ENEMY_H
#define ENEMY_H

#include "SDLgameObject.h"

class Enemy : public SDLGameObject{
    public:
        Enemy(const LoaderParams *pParams);

        void update();
};

#endif
