#ifndef GAME_H
#define GAME_H


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "scoreManager.hpp"



class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    SDL_Window* Window = NULL;
    
    bool run = true;


    

public:

    enum GameState {
        START_SCREEN,
        GAME_SCREEN,
        END_SCREEN,
        // Add more states as needed
        };

    static GameState gameState;

    int count = 0;

    void init(const char* title,int x, int y);
    bool isRunning();
    void update();
    void events();
    void render();
    void close();

    static SDL_Renderer* Renderer;

    ScoreManager scoreManager;
    
};


#endif // GAME_H

