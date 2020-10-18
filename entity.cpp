#include "entity.h"

entity::entity() : spr{"", NULL} {
    xPos = 0;
    yPos = 0;
}

entity::entity(char const *path, SDL_Renderer* rndr, int x, int y) : spr{path, rndr}{
    
    xPos = x;
    yPos = y;
}

entity::~entity(){

}

void entity::attack(){

}

void entity::move(int dir){

}