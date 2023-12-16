#pragma once


#include "MovingObject.hpp"
#include "GameObj.hpp"

class Player: public MovingObject {
    public:
    Player(int x, int y, SDL_Texture* p_tex);
    void MoveRight(std::vector<GameObject*> objects);
    void MoveLeft( std::vector<GameObject*> objects);
    void Jump(std::vector<GameObject*> objects);
    

};
