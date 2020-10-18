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
    sprite(char const *path, SDL_Renderer *rndr);
    ~sprite();

    void select(int x, int y);
    void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position);
    

private:
    SDL_Surface *img;
    SDL_Rect rect;
    SDL_Texture* txtr;
    
};


#endif