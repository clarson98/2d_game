#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"

class entity{
    public:
        //entity();
        entity(char const *path, int x, int y);
        ~entity();

        int getX();
        int getY();

        sprite spr;
        int xPos;
        int yPos;

        void attack();
        void move(int);
};

#endif