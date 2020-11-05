#ifndef PARTICLE_H
#define PARTICLE_H

#include "entity.h"

class particle{
    public:
        particle();
        particle(int, int, double, double, int);
        ~particle();

        void update();
        void draw();

    private:
        int x, y;
        double vx, vy;
        int lifetime;


};







#endif