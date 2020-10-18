#include "gameEngine.h"

gameEngine::gameEngine(){
    my_SDL_init();
    player p = player(my_renderer);
}

gameEngine::~gameEngine(){

  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
}

void gameEngine::gameLoop(){

    //Create rectangle to render onto


    SDL_Rect dstRect = {10, 10, 256, 256};

    //Vars for flipping and speed limiting
    Uint32 start_time;
    Uint32 s;
    Uint32 duration;
    bool flip = 0;
    //Vars for flipping and speed limiting


    while(true){
        handleUI();
        updateMechanics();
        render();
        /*start_time = SDL_GetTicks() / 250;
        s = start_time % 2;
        //rect = {0, s * 256, 256, 256};

        SDL_RenderClear(my_renderer);
        //Perform flip if needed

        //SDL_RenderCopy(my_renderer, my_texture, &rect, &dstRect);
        
        SDL_RenderPresent(my_renderer);

        // Limit speed
        duration = SDL_GetTicks() - start_time;
        if (duration < 5) {
            SDL_Delay(5 - duration);
        }*/
        //p.spr.select(1, 1);
        //p.spr.draw_selected_sprite(temp, &rect);
    }
}

void gameEngine::my_SDL_init(){

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  my_window = SDL_CreateWindow("my_game", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);
  my_renderer = SDL_CreateRenderer(my_window,-1,0);

}

void gameEngine::render(){


}

void gameEngine::updateMechanics(){

}

void gameEngine::handleUI(){

}

/*
  


  SDL_Texture* my_texture = NULL;
  SDL_Surface* temp = IMG_Load("Circle_boi.png");

  my_texture = SDL_CreateTextureFromSurface(my_renderer, temp);

  SDL_FreeSurface(temp);

  //Create rectangle to render onto
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 120;
  rect.w = 226;
  rect.h = 169;
  
  //Vars for flipping and speed limiting
  Uint32 start_time;
  Uint32 duration;
  bool flip = 0;

*/