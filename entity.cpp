#include "entity.h"

//Parameter constructor that takes the file location of the spritesheet
//to be used for the entity, and also calls the sprite constructor
entity::entity(char const *path, int x, int y) : spr{path}{
    xPos = x;
    yPos = y;
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

//Set the sprite to the default
void entity::sprDefault(){
    spr.rect.x = 0;
    spr.rect.y = 0;
}