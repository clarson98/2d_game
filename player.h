#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class player : public entity{

    public:
        //player();
        player();
        ~player();

        void walkSide();
        void idle();
        void walkUp();
        void walkDown();

};

#endif