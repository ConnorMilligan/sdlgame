#ifndef PLAYER_H
#define PLAYER_H

#include "SDLgameObject.h"

class Player : public SDLGameObject{
    public:
        Player(const LoaderParams *pParams);
        
        virtual void update();
};

#endif
