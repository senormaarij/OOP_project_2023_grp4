#include "game.hpp"
#include "loadtexture.hpp"
#include "GameObj.hpp"
#include <vector>

Mix_Music *music = nullptr;
Player* player;
GameObject *obj1;
GameObject *obj2;
GameObject *osc1;
//GameObject *fire;
std::vector<GameObject*> gameObjects;
std::vector<GameObject*> map;
int i = 0;
SDL_Renderer* Game::Renderer = nullptr;

enum GameState {
    START_SCREEN,
    GAME_SCREEN,
    // Add more states as needed
};

GameState currentState = START_SCREEN;

void Game::init(const char* title, int x, int y)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Init successful\n";
    }

    Window = SDL_CreateWindow(title, x, y, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);

    // Initialize SDL_mixer for audio
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }

    // Load the audio file
    music = Mix_LoadMUS("assets/Hitman(chosic.com).mp3");

    if (music == nullptr) {
        std::cout << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    } else {
        Mix_PlayMusic(music, -1); // Play the loaded music infinitely
    }

    player = new Player("assets/fire..png");
    obj1 = new Objects("assets/Sprite-0001.jpg", 600, 200);
    obj2 = new Objects("assets/platform.png", 400, 100);
    osc1 = new Oscillator("assets/oscillator.png", 400,500);
    //fire = new Fire("assets/Daco_5889570.png",600,500);

    gameObjects.push_back(obj1);
    gameObjects.push_back(obj2);
    gameObjects.push_back(osc1);
    //gameObjects.push_back(fire);
}

bool Game::isRunning()
{
    return run;
}

void Game::render()
{
    SDL_RenderClear(Renderer);

    // Render based on the current state
    if (currentState == START_SCREEN) {
		SDL_Texture* startScreen = loadtexture::LoadTexture("assets/gameStart.webp");
		SDL_RenderCopy(Renderer, startScreen, NULL, NULL);
        // Render starting screen elements here
    } else if (currentState == GAME_SCREEN) {
        player->Render();
        obj1->Render();
        obj2->Render();
        osc1->Render();
    }

    SDL_RenderPresent(Renderer);
}



void Game::update()
{
    // Update based on the current state
    if (currentState == GAME_SCREEN) {
        player->Update(gameObjects);
        obj1->Update();
        obj2->Update();
        osc1->Update();
    }

    std::cout << """""""""" << std::endl;
}

void Game::events()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            run = false;
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_RETURN:
                    // Transition to the game screen on pressing Enter
                    currentState = GAME_SCREEN;
                    break;
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    player->Stop();
                    break;
            }
            break;
    }

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentState == GAME_SCREEN) {
        if (currentKeyStates[SDL_SCANCODE_UP]) {
            player->Jump();
        } else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
            player->MoveLeft();
        } else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            player->MoveRight();
        }
    }
}

void Game::close()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    Window = NULL;
    Renderer = NULL;
    SDL_Quit();

}
