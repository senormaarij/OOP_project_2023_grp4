# CS_project_2023_grp4


Elements
Elements is a 2D platformer game developed using the Simple DirectMedia Layer (SDL) library and SDL_mixer for audio in C++. The game features two elemental characters, Fire and Water, navigating through a series of platforms, collecting coins, and avoiding obstacles. The primary goal is to reach the end of the level by overcoming challenges.

Features
Player Characters: The game includes two playable characters, Fire and Water, each with unique textures and abilities.
Platforming: Players can move left and right, jump, and experience gravity effects while navigating the platforms.
Collision Detection: The game implements collision detection to ensure characters interact with platforms realistically.
Coins: Players can collect coins placed throughout the level, triggering a counter.
Game States: The game has various states, including a main menu, gameplay, win, and lose screens.
Object Rendering: SDL is used to render various game objects, such as platforms, borders, coins, and characters.
Audio: SDL_mixer is utilized for audio effects, enhancing the gaming experience.

Dependencies
SDL: Simple DirectMedia Layer library for graphics and input handling.
SDL_image: SDL extension for loading and handling image files.
SDL_mixer: SDL extension for handling audio.

Installation
Ensure you have SDL, SDL_image, and SDL_mixer libraries installed on your system.
Clone the repository.
Compile the code using a C++ compiler with SDL, SDL_image, and SDL_mixer flags. 

Copy code
g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_Mixer -o game.exe


How to Play:
Run the compiled executable.
Use the Spacebar to navigate from the main menu to the gameplay.
Control the Fire character using the arrow keys (left, right, up).
Control the Water character using the A, D, and W keys.
Collect coins by colliding with them.
Reach the end of the level while avoiding obstacles and enemies.
Experience audio effects such as background music and coin collection sounds.
