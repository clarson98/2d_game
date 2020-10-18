#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"

class entity{
    public:
        entity();
        entity(char const *path, SDL_Renderer* rndr);
        ~entity();

        sprite spr;
};

#endif