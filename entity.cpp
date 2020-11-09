#include "entity.h"

entity::entity(){
    
}

//Parameter constructor that takes the file location of the spritesheet
//to be used for the entity, and also calls the sprite constructor
entity::entity(char const *path, int x, int y, int w, int h, SDL_Renderer* ren) : spr{path}{
    xPos = x;
    yPos = y;
    xRight = x + (spr.img->w / spr.res / 2) + (w / 2);
    xLeft = x + (spr.img->w / spr.res / 2) - (w / 2);
    yBot = y + (spr.img->h / spr.res / 2) + (h / 2);
    yTop = y + (spr.img->h / spr.res / 2) - (h / 2);
    //Create texture from sprite surface, and create the rect to render onto
	txtr = SDL_CreateTextureFromSurface(ren, spr.img);
}

//Destructor
entity::~entity(){
 	SDL_DestroyTexture(txtr);
}

//Will be used later for attack animations and interactions
void entity::attack(){

}

//Update entity position when moved
void entity::move(int dir){
    switch (dir){
        case 0:
            yPos -= 4;
            yTop -= 4;
            yBot -= 4;
            break;
        case 1:
            face = true;
            xPos -= 4;
            xLeft -= 4;
            xRight -= 4;
            break;
        case 2:
            yPos += 4;
            yTop += 4;
            yBot += 4;
            break;
        case 3:
            face = false;
            xLeft += 4;
            xPos += 4;
            xRight += 4;
            break;
        default:
            std::cout << "invalid direction!" << std::endl;
            break;
    }
}

//Get current direction being faced by the entity (left or right) without accessing directly
bool entity::getFace(){
    return face;
}

void entity::setFace(bool f){
    face = f;
}

//Set the sprite to the default
void entity::sprDefault(){
    spr.rect.x = 0;
    spr.rect.y = 0;
}

void entity::draw(SDL_Renderer* ren){

	SDL_Rect dstRect = {getXPos(), getYPos(), spr.rect.w, spr.rect.h};
	//render
	SDL_RenderCopy(ren, txtr, &spr.rect, &dstRect);

}

int entity::getXPos(){
    return xPos;
}

int entity::getYPos(){
    return yPos;
}

int entity::getXRight(){
    return xRight;
}

int entity::getYBot(){
    return yBot;
}

int entity::getXLeft(){
    return xLeft;
}

int entity::getYTop(){
    return yTop;
}