#ifndef PARTICLE_H
#define PARTICLE_H

#include "entity.h"

class particle{
    public:
        particle();
        particle(int, int, double, double, int);
        ~particle();

        void update();
        void draw(SDL_Renderer* ren);

    private:
        int x, y;
        double vx, vy;
        int lifetime;


};







#endif