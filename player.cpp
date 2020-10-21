#include "player.h" 

// Default constructor for player, uses player sprite and set position to top left of window
player::player() : entity{"Player.png", 0, 0} {
    setState(4);
}

// Destructor
player::~player(){
    
}

// Sets what the player is currently doing
void player::setState(int s){
    state = static_cast<state_t> (s);
}

// Update position and sprite based on state variable
void player::act(){
    // Move the sprite
    switch(state){
        case WALKING_DOWN:
            yPos += 4;
            break;
        case WALKING_SIDE:
            if(getFace()){
                xPos -= 4;
            }
            else{
                xPos += 4;
            }
            break;
        case WALKING_UP:
            yPos -= 4;
            break;
        default:
            break;
    }
    // If there is no input, change the sprite to default
    if(state == static_cast<state_t> (4)){
        sprDefault();
    }
    // Otherwise, animate the sprite based on the state
    else{
        spr.anim(state);
    }
}