/* Game engine class. Runs the game with the main loop.
*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <string>

#include <SDL.h> 
#include <iostream>
#include <string>
#include <vector>

#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>
#include "entity.h"
#include "player.h"
#include "sprite.h"
#include "idleObject.h"
#include "particle.h"
#include "emitter.h"

using namespace std;

class gameEngine{

    public:
        gameEngine();
        ~gameEngine();

        void gameLoop();
        SDL_Renderer* my_renderer = NULL;


    private:
        void my_SDL_init();
		void render();
		void handleUI(SDL_Event);
		void updateMechanics();
        bool checkCollision(entity&, entity&);
        bool circleRectCol(entity&, entity&);

        //Screen dimension
        const int SCREEN_WIDTH = 1280;
        const int SCREEN_HEIGHT = 960;

        SDL_Window* my_window = NULL;

        SDL_Event input;

		player* p;
        vector<idleObject> objs;

        bool gameOver = false;
        Uint32 timer;







};
#endif