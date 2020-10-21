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
        void act();

        enum state_t {WALKING_DOWN, WALKING_UP, WALKING_SIDE, FLAP, IDLE};

    private:
        state_t state;
};

#endif