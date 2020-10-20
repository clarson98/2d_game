#include "sprite.h"

sprite::sprite(){
    img = NULL;
    rect = {0, 0, 0, 0};
}

//Possible to-do: return array of sprites??? Or make entity classes contain array of sprites?
sprite::sprite(char const *path){

    img = IMG_Load(path);

    rect.x = 0;
    rect.y = 0;
    rect.w = img->w / 2;
    rect.h = img->h / 4;

    //rect.w = img->w / column;
    //rect.h = img->h / row;
}

sprite::~sprite()
{
    SDL_FreeSurface(img);
}

void sprite::walk()
{
    rect.x = 0;
    if(rect.y < 768){
        rect.y += 256;
    }
    else{
        rect.y = 0;
    }
    
}

void sprite::idle(){
    rect.x = 256;
    if(rect.y < 768){
        rect.y += 256;
    }
    else{
        rect.y = 0;
    }
}
