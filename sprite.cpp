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
    rect.w = img->w / (img->w / res);
    rect.h = img->h / (img->h / res);
}

//Sprite destructor. Frees memory of surface
sprite::~sprite()
{
    SDL_FreeSurface(img);
}

void sprite::anim(int s){
    rect.x = s * 256;
    if(rect.y < 768){
        rect.y += 256;
    }
    else{
        rect.y = 0;
    }
}
