#include "game.hpp"

int main(int argc, char *argv[]){
    Game game;
    game.init("Test", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
    while(game.isRunning()){
        game.events();
        game.update();
        game.render();
        SDL_Delay(30);
	}
    game.close();

    return 0;
}