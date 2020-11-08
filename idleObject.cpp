#include "idleObject.h"

idleObject::idleObject(const char* path, int x, int y) : entity{path, x, y} {

}

idleObject::idleObject(char const *path, int x, int y, char const *partPath, int part_x, int part_y, int w, int h, int type) : entity{path, x, y} {
    e = new emitter(partPath, part_x, part_y, w, h, type);
}

idleObject::~idleObject(){
	delete[] e;
}

void idleObject::draw(SDL_Renderer* ren){
    //Create texture from sprite surface, and create the rect to render onto
	SDL_Texture* txtr = SDL_CreateTextureFromSurface(ren, spr.img);
	SDL_Rect dstRect = {getX(), getY(), spr.rect.w, spr.rect.h};
	//render
    e->draw(ren);
	SDL_RenderCopy(ren, txtr, &spr.rect, &dstRect);
	SDL_DestroyTexture(txtr);

}