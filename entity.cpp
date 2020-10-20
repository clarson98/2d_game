#include "entity.h"

/*entity::entity() : spr{""} {
    xPos = 0;
    yPos = 0;
}*/

entity::entity(char const *path, int x, int y) : spr{path}{
    
    xPos = x;
    yPos = y;
}

entity::~entity(){

}

void entity::attack(){

}

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

int entity::getX(){
    return xPos;
}

int entity::getY(){
    return yPos;
}

bool entity::getFace(){
    return face;
}