#ifndef IDLEOBJECT_H
#define IDLEOBJECT_H

#include "entity.h"
#include "emitter.h"

class idleObject : public entity{

    public:
        idleObject(char const *path, int x, int y, SDL_Renderer* ren);
        idleObject(char const *path, int x, int y, char const *partPath, int part_x, int part_y, int w, int h, int type, SDL_Renderer* ren);
        ~idleObject();
        void draw(SDL_Renderer* ren);

    private:
        Uint32 lastUpdate; 
        emitter* e;

};

#endif