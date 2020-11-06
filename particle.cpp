#include "particle.h"

particle::particle(){
    x = 0;
    y = 0;
    vx = 0.0;
    vy = 0.0;
    lifetime = 0;
}

particle::particle(int x, int y, double vx, double vy, int lifetime) : x(x), y(y), vx(vx), vy(vy), lifetime(lifetime) {

}

void particle::update(){
    x += vx;
    y += vy;
    lifetime--;
}

void particle::draw(SDL_Renderer* ren){
    
}