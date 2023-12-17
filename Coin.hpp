#pragma once

#include "GameObj.hpp"
#include "Player.hpp"

class Coin: public GameObject {
    private:
    static int coinCounter;  

    public:
    Coin(int x, int y, SDL_Texture* c_tex);
    static void ResetCoinCounter();
    static int GetCoinCounter();
    void increaseCoinCounter();
};