#include "gameEngine.h"

// Default constructor for game engine
gameEngine::gameEngine(){
	//Initialize SDL
	my_SDL_init();
	//Create player
	player p;
	//Set timer
	timer = SDL_GetTicks();
}

//Destructor. Destroys SDL things
gameEngine::~gameEngine(){

  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
}

// Primary game loop
void gameEngine::gameLoop(){

	while(!gameOver){
		//Update timer
		timer = SDL_GetTicks();
		//Handle user input
		if(SDL_PollEvent(&input)){
			handleUI(input);
		}
		//If no input, reset sprite to default
		else{
			p.setState(4);
		}
		//Update mechanics
		updateMechanics();
		//Display everything
		render();

	}
}

// Initializes renderer and window
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

// Displays everything in the window
void gameEngine::render(){
	//Clear the renderer
	SDL_RenderClear(my_renderer);
	
	//Create texture from sprite surface, and create the rect to render onto
	SDL_Texture* txtr = SDL_CreateTextureFromSurface(my_renderer, p.spr.img);
	SDL_Rect dstRect = {p.getX(), p.getY(), p.spr.rect.w, p.spr.rect.h};
	//If facing left, flip the render
	if(p.getFace()){
		SDL_RenderCopyEx(my_renderer, txtr, &p.spr.rect, &dstRect, 0, 0, SDL_FLIP_HORIZONTAL);
	}
	//Otherwise, render normally
	else{
		SDL_RenderCopy(my_renderer, txtr, &p.spr.rect, &dstRect);
	}
	// Limit speed
	Uint32 duration = SDL_GetTicks() - timer;
	
	if (duration < 1000.0 / 60.0) {
		timer = SDL_GetTicks();
		SDL_Delay(1000 / 60 - duration);
	}
	SDL_RenderPresent(my_renderer);

}

//Currently, just moves the player and calls animation based on state
void gameEngine::updateMechanics(){
	p.act();
}

//Handle keyboard input from user
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
				//Walking state
				//W key hit, move up
				case SDLK_w:
					p.setState(1);
					break;
				//A key hit, move left
				case SDLK_a:
					p.setState(2);
					p.setFace(true);
					break;
				//S key hit, move down
				case SDLK_s:
					p.setState(0);
					break;
				//D key hit, move right
				case SDLK_d:
					p.setState(2);
					p.setFace(false);
					break;
				//Space bar hit, fly animation
				case SDLK_SPACE:
					p.setState(3);
					break;
			}
			break;
		case SDL_KEYUP:
			switch(input.key.keysym.sym){				//W key hit, move up
				case SDLK_w:
					if(p.getState() == 1){
						p.setState(4);
					}
					break;
				//A key hit, move left
				case SDLK_a:
					if(p.getState() == 2 && p.getFace() == true){
						p.setState(4);
						p.setFace(true);
					}
					break;
				//S key hit, move down
				case SDLK_s:
					if(p.getState() == 0){
						p.setState(4);
					}
					break;
				//D key hit, move right
				case SDLK_d:
					if(p.getState() == 2 && p.getFace() == false){
						p.setState(4);
						p.setFace(false);
					}
					break;
				//Space bar hit, fly animation
				case SDLK_SPACE:
					if(p.getState() == 3){
						p.setState(4);
					}
					break;
			}
			break;
		
	}
}
