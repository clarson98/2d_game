#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class player : public entity{

    public:
        player();
        player(SDL_Renderer* rndr);
        ~player();



};

#endif