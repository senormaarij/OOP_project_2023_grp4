#ifndef GAME_H
#define GAME_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>



class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    SDL_Window* Window = NULL;
    
    bool run = true;
    

public:
    int count = 0;

    void init(const char* title,int x, int y);
    bool isRunning();
    void update();
    void events();
    void render();
    void close();

    static SDL_Renderer* Renderer;
    
};

#endif // GAME_H

