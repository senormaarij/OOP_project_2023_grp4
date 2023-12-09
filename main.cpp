#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "loadtexture.hpp"
#include "GameObj.hpp"
#include <vector>
#include "RenderWIndow.hpp"



int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl; 

	if (Mix_Init(0) == -1)
		std::cout << "SDL_Mixer HAS FAILED. Error: " << SDL_GetError() << std::endl;

	srand(time(0));


    /*------------------WINDOW & RENDERER---------------*/
	RenderWindow window("Elements", 600, 800);
	SDL_Renderer* renderer = window.getRenderer();

   
    /*--------------LOAD TEXTURE-----------------*/
    SDL_Texture* p_fire_tex = loadtexture::LoadTexture("");
    SDL_Texture* p_air_tex = loadtexture::LoadTexture("");
    SDL_Texture* p_water_tex = loadtexture::LoadTexture("");
    SDL_Texture* game_bg = loadtexture::LoadTexture("");
    SDL_Texture* mainscreen = loadtexture::LoadTexture("");
    SDL_Texture* losescreen = loadtexture::LoadTexture("");
    SDL_Texture* winscreen = loadtexture::LoadTexture("");
    SDL_Texture* fireball = loadtexture::LoadTexture("");
    SDL_Texture* coin = loadtexture::LoadTexture("");
    SDL_Texture* platform  = loadtexture::LoadTexture(""); 
    SDL_Texture* wall = loadtexture::LoadTexture("");
    SDL_Texture* water_platform = loadtexture::LoadTexture("");
    SDL_Texture* death_platform = loadtexture::LoadTexture("");
    SDL_Texture* button = loadtexture::LoadTexture("");

    /*-------------INITIALIZE PLAYER & LEVEL VECTORS-------------------*/

    Player player(100,100,p_fire_tex); //player constructor
    std::vector<GameObject> platforms = {};


    /*-------------------INITIALIZING OTHER GAME VALUES--------------------*/
    
    /*-------Game States---------*/
    bool isWaiting = false ;
    bool isInMenu = true ;// main menu screen is default screen   
    bool isRestart = false;
    bool isInGame = false;
    bool isWin = false;
    bool isLose = false;
    

    bool gamerun = true; //To run the game 
 

    Screen background(mainscreen);

    SDL_Event event; //to poll events 

    const Uint8* keyboard = SDL_GetKeyboardState(NULL); //Keyboard inputs 


    /*------GAME LOOP------*/

    while(gamerun){

        if (SDL_PollEvent(&event) && (event.type == SDL_QUIT)){
            gamerun = false;
        }


        
        if(isInMenu){
            window.clear();
            window.render(background);
            window.display();
        
        if(keyboard[SDL_SCANCODE_SPACE]){
            isInMenu = false;
            isInGame = true;}
        } 




        else if(isInGame){
            if(!isWaiting){
                window.clear();
                window.render(background);
                window.display();
                isWaiting = true;
            }
            else{
            /*                              HANDLE PLAYER CONTROLS                                     */
				if(keyboard[SDL_SCANCODE_UP]){
                    player.Jump();
				}
				if(keyboard[SDL_SCANCODE_LEFT]){
					player.MoveLeft();
				}
				if(keyboard[SDL_SCANCODE_LEFT]){
					player.MoveRight();
				}


            }
            /*-----------------RENDERING ALL THINGS------------------*/
            window.clear();
			window.render(background);

            for(Entity& plat : platforms){
                window.render(plat);
            }
            for(MovingEntity* ent : movingEntities){
                window.render(*ent);
            }
            window.display();


            



		
		}
	}

	window.cleanUp(); // DELETE EVERYTHING ON SCREEN

	

	// FREE ALL MEMORY   TO-DO
	platforms.clear();
  

	SDL_Quit(); 

    return 0; 
}

