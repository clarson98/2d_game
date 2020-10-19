#include "gameEngine.h"

gameEngine::gameEngine(){
	my_SDL_init();
	player p;
}

gameEngine::~gameEngine(){

  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
}

void gameEngine::gameLoop(){

	//Create rectangle to render onto




	//Vars for flipping and speed limiting

	//Vars for flipping and speed limiting




	while(!gameOver){
		if(SDL_PollEvent(&input)){
			handleUI(input);
		}
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
	SDL_RenderClear(my_renderer);
	//Perform flip if needed
	//SDL_Surface* img = IMG_Load("Player.png");
	//p.spr.move(p.getX(), p.getY());
	
	SDL_Texture* txtr = SDL_CreateTextureFromSurface(my_renderer, p.spr.img);
	SDL_Rect dstRect = {p.getX(), p.getY(), p.spr.rect.w, p.spr.rect.h};
	SDL_RenderCopy(my_renderer, txtr, &p.spr.rect, &dstRect);
	
	SDL_RenderPresent(my_renderer);

}

void gameEngine::updateMechanics(){

}

void gameEngine::handleUI(SDL_Event input){
	switch(input.type){
		// X'd out of program, close
		case SDL_QUIT:
			gameOver = true;
			break;
		//Handle key presses
		case SDL_KEYDOWN:
			switch (input.key.keysym.sym) {
				//Escape key hit, exit game
				case SDLK_ESCAPE:
					gameOver = true;
					break;
				//W key hit, move up
				case SDLK_w:
					p.move(0);
					break;
				//A key hit, move left
				case SDLK_a:
					p.move(1);
					break;
				//S key hit, move down
				case SDLK_s:
					p.move(2);
					break;
				//D key hit, move right
				case SDLK_d:
					p.move(3);
					break;
				//Space bar hit, attack
				case SDLK_SPACE:
					p.attack();
					break;
			}
	}
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