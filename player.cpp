#include "player.h" 

// Default constructor
/*player::player(){
    
}
*/
// Parameter constructor
player::player() : entity{"Player.png", 0, 0} {

}

// Destructor
player::~player(){
    
}

void player::walk()
{
    spr.rect.x = 512;
    if(spr.rect.y < 768){
        spr.rect.y += 256;
    }
    else{
        spr.rect.y = 0;
    }
    
}

void player::idle(){
    spr.rect.x = 768;
    if(spr.rect.y < 768){
        spr.rect.y += 256;
    }
    else{
        spr.rect.y = 0;
    }
}

