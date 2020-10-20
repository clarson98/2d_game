#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

class sprite
{
public:
    sprite();
    sprite(char const *path);
    ~sprite();

    void walk();
    void idle();

    SDL_Surface *img;
    SDL_Rect rect;
    //SDL_Texture* txtr;

private:

    
};


#endif