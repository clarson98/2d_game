#include "player.h" 

// Default constructor
player::player(){
    
}

// Parameter constructor
player::player(SDL_Renderer* rndr) : entity{"Player.png", rndr, 0, 0} {

}

// Destructor
player::~player(){
    
}

