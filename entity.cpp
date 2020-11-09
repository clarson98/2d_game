#include "entity.h"

//Parameter constructor that takes the file location of the spritesheet
//to be used for the entity, and also calls the sprite constructor
entity::entity(char const *path, int x, int y) : spr{path}{
    xPos = x;
    yPos = y;
    xRight = x + 256;
    yBot = y + 256;
}

//Destructor
entity::~entity(){

}

//Will be used later for attack animations and interactions
void entity::attack(){

}

//Update entity position when moved
void entity::move(int dir){
    switch (dir){
        case 0:
            yPos -= 4;
            break;
        case 1:
            face = true;
            xPos -= 4;
            break;
        case 2:
            yPos += 4;
            break;
        case 3:
            face = false;
            xPos += 4;
            break;
        default:
            std::cout << "invalid direction!" << std::endl;
            break;
    }
}

//Get current x coordinate of entity without accessing directly
int entity::getX(){
    return xPos;
}

//Get current y coordinate of entity without accessing directly
int entity::getY(){
    return yPos;
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
    //Create texture from sprite surface, and create the rect to render onto
	SDL_Texture* txtr = SDL_CreateTextureFromSurface(ren, spr.img);
	SDL_Rect dstRect = {getX(), getY(), spr.rect.w, spr.rect.h};
	//render
	SDL_RenderCopy(ren, txtr, &spr.rect, &dstRect);
	SDL_DestroyTexture(txtr);
}