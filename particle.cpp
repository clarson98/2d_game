#include "particle.h"

particle::particle(){
    x = 0;
    y = 0;
    vx = 0.0;
    vy = 0.0;
    lifetime = 0;
    w = 0;
    h = 0;
}

particle::particle(int x, int y, double vx, double vy, int lifetime,  int w, int h, int type) : x(x), y(y), vx(vx), vy(vy), lifetime(lifetime), w(w), h(h), type(type) {
    if(type == 0){
        img = IMG_Load("Ember.png");

        rect.x = x;
        rect.y = y;
        rect.w = 4;
        rect.h = 4;
    }
}

void particle::update(){
    x += vx;
    y += vy;
    lifetime--;
}

void particle::draw(SDL_Renderer* ren){

}