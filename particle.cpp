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

        rect.x = 0;
        rect.y = 0;
        rect.w = img->w;
        rect.h = img->h;
    }
}

particle::~particle(){

}

void particle::update(){
    x += vx;
    y += vy;
    lifetime--;
    if(type == 0){
        vy += 0.05;
    }
}

void particle::draw(SDL_Renderer* ren){
    //std::cout << " test" << std::endl;
    //Create texture from sprite surface, and create the rect to render onto
	SDL_Texture* txtr = SDL_CreateTextureFromSurface(ren, img);
	SDL_Rect dstRect = {(int) x, (int) y, w, h};
	//render
	SDL_RenderCopy(ren, txtr, &rect, &dstRect);
    SDL_DestroyTexture(txtr);
}

int particle::getLife(){
    return lifetime;
}