#include "player.h" 

player::player() : entity(){

}

// Default constructor for player, uses player sprite and set position to top left of window
player::player(SDL_Renderer* ren) : entity{"Player.png", 0, 0, 128, 144, ren} {
    setState(4);
    lastUpdate = SDL_GetTicks();
    rad = 64;
}

// Destructor
player::~player(){
    
}

// Sets what the player is currently doing
void player::setState(int s){
    state = static_cast<state_t> (s);
}

int player::getState(){
    return state;
}

// Update position and sprite based on state variable
void player::act(){
    // Move the sprite
    switch(state){
        case WALKING_DOWN:
            yPos += 4;
            yTop += 4;
            yBot += 4;
            break;
        case WALKING_SIDE:
            if(getFace()){
                xPos -= 4;
                xLeft -= 4;
                xRight -= 4;
            }
            else{
                xLeft += 4;
                xPos += 4;
                xRight += 4;
            }
            break;
        case WALKING_UP:
            yPos -= 4;
            yTop -= 4;
            yBot -= 4;
            break;
        default:
            break;
    }

    // If there is no input, change the sprite to default
    if(state != static_cast<state_t> (4) && SDL_GetTicks() - lastUpdate > 1000.0 / 30.0){
        spr.anim(state);
        lastUpdate = SDL_GetTicks();
    }
    else if(state == static_cast<state_t> (4) && SDL_GetTicks() - lastUpdate > 1000.0 / 2.0){
        spr.anim(state);
        lastUpdate = SDL_GetTicks();
    }

    
}


void player::draw(SDL_Renderer* ren){
    //Create texture from sprite surface, and create the rect to render onto

	SDL_Rect dstRect = {getXPos(), getYPos(), spr.rect.w, spr.rect.h};
	//If facing left, flip the render
	if(getFace()){
		SDL_RenderCopyEx(ren, txtr, &spr.rect, &dstRect, 0, 0, SDL_FLIP_HORIZONTAL);
	}
	//Otherwise, render normally
	else{
		SDL_RenderCopy(ren, txtr, &spr.rect, &dstRect);
	}

}