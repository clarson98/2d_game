#ifndef IDLEOBJECT_H
#define IDLEOBJECT_H

#include "entity.h"
#include "emitter.h"

class idleObject : public entity{

    public:
        idleObject(const char* path, int x, int y, int w, int h, SDL_Renderer* ren);
        idleObject(char const *path, int x, int y, int w2, int h2, char const *partPath, int part_x, int part_y, int w, int h, int type, SDL_Renderer* ren);
        ~idleObject();
        void draw(SDL_Renderer* ren);

    private:
        Uint32 lastUpdate; 
        emitter* e;

};

#endif