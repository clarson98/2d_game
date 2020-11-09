/* Player class. In the future, will contain all data and functions unique to the player
 * Currently holds a few animations
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class player : public entity{

    public:
        player();
        ~player();

        void setState(int s);
        int getState();
        void act();
        void draw(SDL_Renderer* ren);

        enum state_t {WALKING_DOWN, WALKING_UP, WALKING_SIDE, FLAP, IDLE, COLLIDED};

    private:
        state_t state;
        Uint32 lastUpdate; 
};

#endif