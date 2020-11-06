#ifndef PARTICLE_H
#define PARTICLE_H

#include "entity.h"

class particle{
    public:
        particle();
        particle(int, int, double, double, int, int, int, int);
        ~particle();

        void update();
        void draw(SDL_Renderer* ren);

    private:
        int x, y;
        double vx, vy;
        int lifetime;
        int w, h;
        int type;

        SDL_Surface *img;
        SDL_Rect rect;


};







#endif