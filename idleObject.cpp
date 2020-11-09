#include "idleObject.h"

idleObject::idleObject(const char* path, int x, int y, int w, int h, SDL_Renderer* ren) : entity{path, x, y, w, h, ren} {

}

idleObject::idleObject(char const *path, int x, int y, int w2, int h2, char const *partPath, int part_x, int part_y, int w, int h, int type, SDL_Renderer* ren) : entity{path, x, y, w2, h2, ren} {
    e = new emitter(partPath, part_x, part_y, w, h, type);
}

idleObject::~idleObject(){
	//delete[] e;
}

void idleObject::draw(SDL_Renderer* ren){
    //Create texture from sprite surface, and create the rect to render onto

	SDL_Rect dstRect = {getXPos(), getYPos(), spr.rect.w, spr.rect.h};
	//render
    e->draw(ren);
	SDL_RenderCopy(ren, txtr, &spr.rect, &dstRect);

}