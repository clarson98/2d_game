#include "emitter.h"

emitter::emitter(){

}

emitter::emitter(const char *partPath, int part_x, int part_y, int w, int h, int type){
    this->type = type;
    srand(SDL_GetTicks());
    // Torch effects
    if(type == 0){
        MAX_PARTS = 5;
        posX = part_x;
        posY = part_y;
        width = w;
        height = h;
    }

}

void emitter::draw(SDL_Renderer* ren){
    update();
    for(auto itr = particles.begin(); itr < particles.end(); itr++){
        itr->draw(ren);
    }
}

void emitter::update(){
    if(rand() % 30 == 0 && particles.size() < MAX_PARTS){
        particle p(rand() % 9 + (-4), posY, rand() % 9 + (-4), rand() % 4, rand() % 60 + 30, 4, 4, type);
        particles.push_back(p);
    }
    for(int i = 0; i < particles.size(); i++){
        particles[i].update();
        if(particles[i].getLife() == 0){
            //particles.erase(particles.begin() + i);
            //delete particles.at(i);
        }
    }
}