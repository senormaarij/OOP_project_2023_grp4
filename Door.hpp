#pragma once

#include "GameObj.hpp"
#include "Player.hpp"

class Door: public GameObject{
    public:
    bool Collision(Player* player);
};
