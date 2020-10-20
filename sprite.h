/* Sprite class. Contains the actual spritesheet to draw from as well as the current part
 * of the spritesheet being rendered.
 * 
*/

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



    SDL_Surface *img;
    SDL_Rect rect;

private:

    
};


#endif