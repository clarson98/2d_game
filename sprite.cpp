#include "sprite.h"

//Default constructor, initializes null values
sprite::sprite(){
    img = NULL;
    rect = {0, 0, 0, 0};
}

//Load the spritesheet and divide it into equal parts for each sprite
sprite::sprite(char const *path){

    img = IMG_Load(path);

    rect.x = 0;
    rect.y = 0;
    rect.w = img->w / 4;
    rect.h = img->h / 4;
}

//Sprite destructor. Frees memory of surface
sprite::~sprite()
{
    SDL_FreeSurface(img);
}


