#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <string>

#include <SDL.h> 
#include <iostream>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>
#include "entity.h"
#include "player.h"
#include "sprite.h"

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

        //Screen dimension
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

        SDL_Window* my_window = NULL;

        SDL_Event input;

		player p;

        bool gameOver = false;
        Uint32 timer;







};
#endif