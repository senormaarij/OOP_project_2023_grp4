

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "GameObj.hpp"
#include <vector>
#include "RenderWindow.hpp"


float getCurrentTime(){
    return SDL_GetTicks()/1000.0f;
}



int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl; //flag to check SDL initialized

	srand(time(0));


    /*------------------WINDOW & RENDERER---------------*/
	RenderWindow window("Elements", 800, 600);
	SDL_Renderer* renderer = window.getRenderer();

   
    /*--------------LOAD TEXTURE-----------------*/
    SDL_Texture* p_fire_tex = window.LoadTexture("assets/fire.png");
    // SDL_Texture* p_air_tex = window.LoadTexture("");
    SDL_Texture* p_water_tex = window.LoadTexture("assets/water.png");
    SDL_Texture* game_bg = window.LoadTexture("assets/bg.png");
    SDL_Texture* mainscreen = window.LoadTexture("assets/main_screen.png");
    // SDL_Texture* losescreen = window.LoadTexture("");
    // SDL_Texture* winscreen = window.LoadTexture("");
    // SDL_Texture* fireball = window.LoadTexture("");
    // SDL_Texture* coin = window.LoadTexture("");
    SDL_Texture* platform  = window.LoadTexture("assets/platform.png"); 
    SDL_Texture* wall = window.LoadTexture("assets/wall.png");
    // SDL_Texture* water_platform = window.LoadTexture("");
    // SDL_Texture* death_platform = window.LoadTexture("");
    // SDL_Texture* button = window.LoadTexture("");

    /*-------------INITIALIZE PLAYER & LEVEL VECTORS-------------------*/

    Player player(100,100,p_fire_tex); //player constructor
    std::vector<GameObject*> platforms ; //vector of platforms

  
    GameObject* plat_1 = new GameObject(0,600,wall);
   
    platforms.push_back(plat_1);
    

    






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

    float currentTime = getCurrentTime();
    float lastJumpTime;

    /*------GAME LOOP------*/

    while(gamerun){
        currentTime = getCurrentTime();
        if (SDL_PollEvent(&event) && (event.type == SDL_QUIT)){
            gamerun = false;
        }

        if(isInMenu){
            window.clear();
            window.render(background);
            window.display();
        
        if(keyboard[SDL_SCANCODE_SPACE]){
            isInMenu = false;
            isInGame = true;
            background.switch_screen(game_bg);
            }
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
				
				if(keyboard[SDL_SCANCODE_LEFT]){
					player.MoveLeft(platforms);
				}
				if(keyboard[SDL_SCANCODE_RIGHT]){
					player.MoveRight(platforms);
				}
                if(keyboard[SDL_SCANCODE_UP]){
                    player.Jump(platforms);
                
                }

            }
            player.Gravity(platforms);


            /*-----------------RENDERING ALL THINGS------------------*/
            window.clear();
            window.render(background);
            for (int i = 0; i < platforms.size(); i++) {
                window.render(*platforms[i]);
            }



            window.render(player);



            window.display();
		
		}
	}

	window.cleanUp(); // DELETE EVERYTHING ON SCREEN

	

	// FREE ALL MEMORY   TO-DO
	//platforms.clear();
  

	SDL_Quit(); 

    return 0; 
}

