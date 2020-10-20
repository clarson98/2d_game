#include "player.h" 

// Default constructor for player, uses player sprite and set position to top left of window
player::player() : entity{"Player.png", 0, 0} {

}

// Destructor
player::~player(){
    
}

//Walk horizontally
void player::walkSide(){
    spr.rect.x = 512;
    if(spr.rect.y < 768){
        spr.rect.y += 256;
    }
    else{
        spr.rect.y = 0;
    }
}

//Flap wings animation
void player::idle(){
    spr.rect.x = 768;
    if(spr.rect.y < 768){
        spr.rect.y += 256;
    }
    else{
        spr.rect.y = 0;
    }
}

//Walk upwards
void player::walkUp(){
    spr.rect.x = 256;
    if(spr.rect.y < 768){
        spr.rect.y += 256;
    }
    else{
        spr.rect.y = 0;
    } 
}

//Walk downwards
void player::walkDown(){
    spr.rect.x = 0;
    if(spr.rect.y < 768){
        spr.rect.y += 256;
    }
    else{
        spr.rect.y = 0;
    }
}