#include "sprite.h"

sprite::sprite(){
    img = NULL;
    txtr = NULL;
    rect = {0, 0, 0, 0};
}

sprite::sprite(char const *path, SDL_Renderer *rndr){
    txtr = NULL;
    img = IMG_Load(path);

    txtr = SDL_CreateTextureFromSurface(rndr, img);

    SDL_FreeSurface(img);

    rect.x = 0;
    rect.y = 0;
    rect.w = 256;
    rect.h = 256;

    //rect.w = img->w / column;
    //rect.h = img->h / row;
}

sprite::~sprite()
{
    SDL_FreeSurface(img);
}

void sprite::select(int x, int y)
{
    rect.x = x * rect.w;
    rect.y = y * rect.h;
}

void sprite::draw_selected_sprite(SDL_Surface *surf, SDL_Rect *r)
{
    SDL_BlitSurface(img, &rect, surf, r);
}
