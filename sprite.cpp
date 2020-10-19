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
    rect.w = img->w;
    rect.h = img->h / 2;

    //rect.w = img->w / column;
    //rect.h = img->h / row;
}

sprite::~sprite()
{
    SDL_FreeSurface(img);
}

void sprite::walk()
{
    if(rect.y == 0){
        rect.y = 256;
    }
    else{
        rect.y = 0;
    }
    
}
