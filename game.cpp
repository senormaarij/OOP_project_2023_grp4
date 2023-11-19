#include "game.hpp"
#include "loadtexture.hpp"
#include "GameObj.hpp"


Player* player;


SDL_Renderer* Game::Renderer = nullptr;


void Game::init(const char* title, int x, int y)
{
	if(SDL_Init(SDL_INIT_EVERYTHING)== 0){
		std::cout<< "Init successful\n";
	}

	Window = SDL_CreateWindow(title,x,y,SCREEN_WIDTH,SCREEN_HEIGHT,0);
	

	Renderer = SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(Renderer,255,255,255,255);

	
	player = new Player("assets/fire..png");
	

}

bool Game::isRunning(){
	return run;
}

void Game::render(){
	SDL_RenderClear(Renderer);
	player->Render();
	SDL_RenderPresent(Renderer);
}

void Game::update(){
	player->Update();
	std::cout << std::endl;

}

void Game::events(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			run = false;
			break;
		case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    player->Stop();
                    break;
            }
            break;
    }


	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_UP]) {
        player->Jump();
    }
    else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        player->MoveLeft();
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        player->MoveRight();
	}
}

void Game::close()
{
	SDL_DestroyRenderer( Renderer );
	SDL_DestroyWindow( Window );
	Window = NULL;
	Renderer = NULL;
	SDL_Quit();
}


