#include "entity.h"

entity::entity() : spr{"", NULL} {

}

entity::entity(char const *path, SDL_Renderer* rndr) : spr{path, rndr}{
    

}

entity::~entity(){

}
