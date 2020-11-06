/* Entity parent class. All movable characters will be children of this class.
 * Contains functions and data that all entities will have in common
 */ 

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


        void attack();
        void move(int);
        bool getFace();
        void setFace(bool f);
        void sprDefault();

        void virtual draw(SDL_Renderer* ren);

    protected:
        int xPos;
        int yPos;

    private:
        bool face = false;
};

#endif