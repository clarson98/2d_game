#ifndef EMITTER_H
#define EMITTER_H

#include "particle.h"
#include <vector>

class emitter{
    public:
        emitter();
        ~emitter();
        void update();
        void draw(SDL_Renderer* ren);

    private:

        std::vector<particle>  particles;

};

#endif