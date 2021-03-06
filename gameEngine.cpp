#include "gameEngine.h"

// Default constructor for game engine
gameEngine::gameEngine(){
	//Initialize SDL
	my_SDL_init();
	p = new player(my_renderer);
	idleObject* torch = new idleObject("Torch.png", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 32, 96, "Ember.png", SCREEN_WIDTH / 2 + 128, SCREEN_HEIGHT / 2 + 103, 4, 4, 0, my_renderer);
	objs.push_back(*torch);
	//entity* p2 = new player(my_renderer);
	//objs.push_back(*p2);

	//Set timer
	timer = SDL_GetTicks();
}

//Destructor. Destroys SDL things
gameEngine::~gameEngine(){
	//objs.clear();
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
		//If player is collided, they are locked in animation and can't input
		if(p->getState() == 5){
			SDL_FlushEvent(SDL_PollEvent(&input));
		}
		//Handle user input
		else if(SDL_PollEvent(&input)){
			handleUI(input);
		}
		//If no input, reset sprite to default
		else{
			p->setState(4);
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
	//Call draw functions
	for(auto i = objs.begin(); i < objs.end(); i++){
		i->draw(my_renderer);
	}
	p->draw(my_renderer);
	// Limit speed
	Uint32 duration = SDL_GetTicks() - timer;
	
	if (duration < 1000.0 / 60.0) {
		timer = SDL_GetTicks();
		SDL_Delay(1000 / 60 - duration);
	}
	SDL_RenderPresent(my_renderer);

}

// Updates objects, checks for collisions, calls sprite changes
void gameEngine::updateMechanics(){
	p->act();
	for(auto i = objs.begin(); i < objs.end(); i++){
		i->spr.anim(0);
	}
	for(auto i = objs.begin(); i < objs.end(); i++){
		bool x = checkCollision(*p, *i);
		if(x == true){
			p->setState(5);
			p->spr.rect.y = 0;
		}
	}
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
					p->setState(1);
					break;
				//A key hit, move left
				case SDLK_a:
					p->setState(2);
					p->setFace(true);
					break;
				//S key hit, move down
				case SDLK_s:
					p->setState(0);
					break;
				//D key hit, move right
				case SDLK_d:
					p->setState(2);
					p->setFace(false);
					break;
				//Space bar hit, fly animation
				case SDLK_SPACE:
					p->setState(3);
					break;
			}
			break;
		case SDL_KEYUP:
			switch(input.key.keysym.sym){				
				//W key released, stop moving up
				case SDLK_w:
					if(p->getState() == 1){
						p->setState(4);
					}
					break;
				//A key released, stop moving left
				case SDLK_a:
					if(p->getState() == 2 && p->getFace() == true){
						p->setState(4);
						p->setFace(true);
					}
					break;
				//S key released, stop moving down
				case SDLK_s:
					if(p->getState() == 0){
						p->setState(4);
					}
					break;
				//D key released, stop moving right
				case SDLK_d:
					if(p->getState() == 2 && p->getFace() == false){
						p->setState(4);
						p->setFace(false);
					}
					break;
				//Space bar released, stop fly animation
				case SDLK_SPACE:
					if(p->getState() == 3){
						p->setState(4);
					}
					break;
			}
			break;
		
	}
}

bool gameEngine::checkCollision(entity& left, entity& right){
	//Rectangular detection
	if(left.getRad() == 0 && right.getRad() == 0){
	//When left's left overlaps with right
		if((left.getXLeft() > right.getXLeft() && left.getXLeft() < right.getXRight())){
			if(left.getYTop() > right.getYTop() && left.getYTop() < right.getYBot()){
				return true;
			}
			else if(left.getYBot() > right.getYTop() && left.getYBot() < right.getYBot()){
				return true;
			}
			else if(left.getYTop() < right.getYTop() && left.getYBot() > right.getYBot()){
				return true;
			}
			else if(left.getYBot() < right.getYBot() && left.getYTop() > right.getYTop()){
				return true;
			}		
		}
		//When left's right overlaps with right
		if((left.getXRight() > right.getXLeft() && left.getXRight() < right.getXRight())){
			if(left.getYTop() > right.getYTop() && left.getYTop() < right.getYBot()){
				return true;
			}
			else if(left.getYBot() > right.getYTop() && left.getYBot() < right.getYBot()){
				return true;
			}
			else if(left.getYTop() < right.getYTop() && left.getYBot() > right.getYBot()){
				return true;
			}
			else if(left.getYBot() < right.getYBot() && left.getYTop() > right.getYTop()){
				return true;
			}	
		}
		//When left's left and right are outside of right's left and right (left has larger width)
		if((left.getXLeft() < right.getXLeft() && left.getXRight() > right.getXRight())){
			if(left.getYTop() > right.getYTop() && left.getYTop() < right.getYBot()){
				return true;
			}
			else if(left.getYBot() > right.getYTop() && left.getYBot() < right.getYBot()){
				return true;
			}
			else if(left.getYTop() < right.getYTop() && left.getYBot() > right.getYBot()){
				return true;
			}
			else if(left.getYBot() < right.getYBot() && left.getYTop() > right.getYTop()){
				return true;
			}	
		}
		//When left's left and right are inside of right's left and right (left has smaller width)
		if((left.getXLeft() > right.getXLeft() && left.getXRight() < right.getXRight())){
			if(left.getYTop() > right.getYTop() && left.getYTop() < right.getYBot()){
				return true;
			}
			else if(left.getYBot() > right.getYTop() && left.getYBot() < right.getYBot()){
				return true;
			}
			else if(left.getYTop() < right.getYTop() && left.getYBot() > right.getYBot()){
				return true;
			}
			else if(left.getYBot() < right.getYBot() && left.getYTop() > right.getYTop()){
				return true;
			}	
		}
	}
	//Both circular detection
	else if(left.getRad() != 0 && right.getRad() != 0){
		//Get center points of each circle
		double leftCX = (left.getXLeft() + left.getXRight()) / 2;
		double leftCY = (left.getYTop() + left.getYBot()) / 2;
		double rightCX = (right.getXLeft() + right.getXRight()) / 2;
		double rightCY = (right.getYTop() + right.getYBot()) / 2;
		//Calculate distance between the two centers
		double dx = leftCX - rightCX;
		double dy = leftCY - rightCY;
		double distance = sqrt(pow(dx, 2) + pow(dy, 2));
		//Check for overlap
		if(distance < left.getRad() + right.getRad()){
				return true;
		}
	}
	//Otherwise, circle-rectangle collision
	else if(left.getRad() != 0 || right.getRad() != 0){
		if(left.getRad() != 0){
			return circleRectCol(left, right);
		}
		else{
			return circleRectCol(right, left);
		}
	}

	return false;
}

bool gameEngine::circleRectCol(entity& circ, entity& rect){
	double testX = (circ.getXLeft() + circ.getXRight()) / 2;
	double testY = (circ.getYTop() + circ.getYBot()) / 2;

	//Determine which edge of the rectangle is closest to the circle
	if(testX < rect.getXLeft()){
		testX = rect.getXLeft();
	}
	else if(testX > rect.getXRight()){
		testX = rect.getXRight();
	}
	if(testY < rect.getYTop()){
		testY = rect.getYTop();
	}
	else if(testY > rect.getYBot()){
		testY = rect.getYBot();
	}

	//Determine distance from center of circle to edge
	double dx = ((circ.getXLeft() + circ.getXRight()) / 2) - testX;
	double dy = ((circ.getYTop() + circ.getYBot()) / 2) - testY;
	double dist = sqrt(pow(dx, 2) + pow(dy, 2));

	//If radius is less than distance, there is a collison
	if(dist < circ.getRad()){
		return true;
	}
	return false;
}