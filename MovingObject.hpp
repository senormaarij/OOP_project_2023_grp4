#pragma once 

#include "GameObj.hpp"

class MovingObject: public GameObject {
private:
    Vector2D speed;
protected:
    bool isJumping = false; 

public:
    MovingObject(int x, int y, SDL_Texture* m_tex);
    Vector2D getSpeed();
    void setSpeed(float m_x, float m_y);
    void Gravity(std::vector<GameObject*> objects);

};