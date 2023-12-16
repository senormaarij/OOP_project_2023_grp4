#pragma once

#include "GameObj.hpp"
#include "Player.hpp"

class Coin: public GameObject {
    public:
    Coin(int x, int y, SDL_Texture* c_tex);
    bool Collision(Player* player);
};