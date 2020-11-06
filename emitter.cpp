#include "emitter.h"

emitter::emitter(){

}

emitter::emitter(const char *partPath, int part_x, int part_y, int w, int h, int type){
    this->type = type;
    srand(SDL_GetTicks());
    // Torch effects
    if(type == 0){
        
    }

}

void emitter::draw(SDL_Renderer* ren){

}

void emitter::update(){
    
}