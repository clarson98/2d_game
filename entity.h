#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"

class entity{
    public:
        entity();
        entity(char const *path, SDL_Renderer* rndr, int x, int y);
        ~entity();

        sprite spr;
        int xPos;
        int yPos;

        void attack();
        void move(int);
};

#endif