#pragma once

#include "GameObj.hpp"
#include "Player.hpp"

class Button: public GameObject{
    bool Collision(GameObject* GameObject) override;

};


