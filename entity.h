/* Entity parent class. All movable characters will be children of this class.
 * Contains functions and data that all entities will have in common
 */ 

#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"

class entity{
    public:
        entity();
        entity(char const *path, int x, int y, int w, int h, SDL_Renderer*);
        ~entity();



        sprite spr;

        void attack();
        void move(int);
        bool getFace();
        void setFace(bool f);
        void sprDefault();

        void virtual draw(SDL_Renderer* ren);
        int getXPos();
        int getYPos();
        int getXRight();
        int getYBot();
        int getXLeft();
        int getYTop();

    protected:
        SDL_Texture* txtr;
        int xPos;
        int yPos;
        int xLeft;
        int yTop;
        int xRight;
        int yBot;
    private:
        bool face = false;
};

#endif