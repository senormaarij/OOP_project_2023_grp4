#include "Coin.hpp"


Coin::Coin(int x, int y, SDL_Texture* c_tex):GameObject(x,y,c_tex){}

int Coin::coinCounter = 0;

void Coin::increaseCoinCounter() {
    coinCounter++;
}

int Coin::GetCoinCounter() {
    return coinCounter;
}

void Coin::ResetCoinCounter() {
    coinCounter = 0;
}



