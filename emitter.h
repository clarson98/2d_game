#ifndef EMITTER_H
#define EMITTER_H

#include "particle.h"
#include <vector>
#include <random>

class emitter{
    public:
        emitter();
        emitter(const char *partPath, int part_x, int part_y, int w, int h, int type);
        ~emitter();
        void update();
        void draw(SDL_Renderer* ren);

    private:
        std::vector<particle>  particles;
        int posX, posY, type, width, height;
        unsigned int MAX_PARTS;

};

#endif