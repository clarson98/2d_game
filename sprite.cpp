#include "sprite.h"

sprite::sprite(){
    img = NULL;
    rect = {0, 0, 0, 0};
}

sprite::sprite(char const *path){

    img = IMG_Load(path);

    rect.x = 0;
    rect.y = 256;
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

void sprite::draw_selected_sprite(SDL_Renderer *rndr, SDL_Rect *r)
{
    SDL_RenderClear(rndr);
    //Perform flip if needed

    SDL_RenderCopy(rndr, NULL, &rect, r);
    
    SDL_RenderPresent(rndr);
}
