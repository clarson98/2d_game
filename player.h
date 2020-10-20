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

        void walkSide();
        void idle();
        void walkUp();
        void walkDown();
};

#endif