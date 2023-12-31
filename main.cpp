

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
#include "Player.hpp"
#include "Coin.hpp"
#include "Door.hpp"


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
    SDL_Texture* p_fire_tex = window.LoadTexture("assets/FireChar.png");
    // SDL_Texture* p_air_tex = window.LoadTexture("");
    SDL_Texture* p_water_tex = window.LoadTexture("assets/WaterChar.png");
    SDL_Texture* game_bg = window.LoadTexture("assets/bg.png");
    SDL_Texture* mainscreen = window.LoadTexture("assets/main_screen.png");
    SDL_Texture* border = window.LoadTexture("assets/borders.png");
    // SDL_Texture* losescreen = window.LoadTexture("");
    // SDL_Texture* winscreen = window.LoadTexture("");
    // SDL_Texture* fireball = window.LoadTexture("");
    SDL_Texture* coin = window.LoadTexture("assets/s_jewel.png");
    SDL_Texture* platform  = window.LoadTexture("assets/platform.png"); 
    SDL_Texture* ground = window.LoadTexture("assets/ground.png");
    //SDL_Texture* osc_platform = window.LoadTexture("");
    SDL_Texture* water_platform = window.LoadTexture("assets/water_plat.png");
    SDL_Texture* fire_platform = window.LoadTexture("assets/fire_plat.png");
    // SDL_Texture* death_platform = window.LoadTexture("");
    // SDL_Texture* button = window.LoadTexture("");
    SDL_Texture*  s_platform = window.LoadTexture("assets/platform_small.png");
    SDL_Texture*  box = window.LoadTexture("assets/box.png");

    /*-------------INITIALIZE PLAYER & LEVEL VECTORS-------------------*/
    Player player2(50,500,p_water_tex); //player constructor
    Player player1(100,500,p_fire_tex); //player constructor


    std::vector<GameObject*> platforms ; //vector of platforms
    std::vector<Coin*> coins ; //vector of coins
    std::vector<Door*> doors ; //vector of doors
    std::vector<GameObject*> firePlatform; //vector of firePlatforms
    std::vector<GameObject*> waterPlatform; //vector of waterPlatforms





  
    GameObject* plat_1 = new GameObject(0,600,ground);
    GameObject* plat_2 = new GameObject(0,400,s_platform);
    GameObject* plat_3 = new GameObject(200,400,s_platform);
    GameObject* plat_4 = new GameObject(400,400,s_platform);
    GameObject* plat_5 = new GameObject(400,275,s_platform);
    GameObject* plat_6 = new GameObject(600,275,s_platform);
    GameObject* plat_7 = new GameObject(200,150,s_platform);
    GameObject* plat_8 = new GameObject(400,150,s_platform);
    GameObject* plat_9 = new GameObject(0,150,s_platform);
    GameObject* plat_10 = new GameObject(200,275,s_platform);
    




    GameObject* wall1 = new GameObject(0,500,border);
    GameObject* wall2 = new GameObject(800,500,border);

   
    platforms.push_back(plat_1);
    platforms.push_back(plat_2);
    platforms.push_back(plat_3);
    platforms.push_back(plat_4);
    platforms.push_back(plat_5);
    platforms.push_back(plat_6);
    platforms.push_back(plat_7);
    platforms.push_back(plat_8);
    platforms.push_back(plat_9);
    platforms.push_back(plat_10);



    platforms.push_back(wall1);
    platforms.push_back(wall2);






    Coin* c1 = new Coin(100,450,coin);
    Coin* c2 = new Coin(250,450,coin);
    coins.push_back(c1);
    coins.push_back(c2);




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
					player1.MoveLeft(platforms);
				}
				if(keyboard[SDL_SCANCODE_RIGHT]){
					player1.MoveRight(platforms);
				}
                if(keyboard[SDL_SCANCODE_UP]){
                    player1.Jump(platforms);
                }
                if(keyboard[SDL_SCANCODE_A]){
                    player2.MoveLeft(platforms);
                }
                if(keyboard[SDL_SCANCODE_D]){
                    player2.MoveRight(platforms);
                }
                if(keyboard[SDL_SCANCODE_W]){
                    player2.Jump(platforms);
                }

            }

            /*---------------GAME UPDATES---------------*/
            player1.Gravity(platforms);
            player2.Gravity(platforms);

          

            /*------------COIN HANDLING---------------*/
             for (int i = 0; i < coins.size(); i++) {
                
                if(coins[i]->Collision(&player1) || coins[i]->Collision(&player2)){
                    coins.erase(coins.begin() + i);
                    coins[i]->increaseCoinCounter();
                    std::cout<<coins[i]->GetCoinCounter();
                }
            }


            /*------------DOOR HANDLING---------------*/
            // for(auto& door: doors){
            //     door->Collision(&player1);
            //     door->Collision(&player2);
            // }

            /*------------PLATFORM HANDLING---------------*/




            /*------------PLAYER HANDLING---------------*/
            
    
            



            /*-----------------RENDERING ALL THINGS------------------*/
            window.clear();
            window.render(background);
            for (int i = 0; i < platforms.size(); i++) {
                window.render(*platforms[i]);
            }
            for (int i = 0; i < firePlatform.size(); i++) {
                window.render(*firePlatform[i]);
            }
            for (int i = 0; i < waterPlatform.size(); i++) {
                window.render(*waterPlatform[i]);
            }


            for(auto& coin: coins){
                window.render(*coin);
            }



            window.render(player1);
            window.render(player2);



            window.display();
		}
	}

	window.cleanUp(); // DELETE EVERYTHING ON SCREEN

	

	// FREE ALL MEMORY   TO-DO
	//platforms.clear();
  

	SDL_Quit(); 

    return 0; 
}

