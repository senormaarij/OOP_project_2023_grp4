#pragma once

#include "game.hpp"
#include "loadtexture.hpp"
#include <vector>
#include "vector.cpp"


class GameObject {
public:
    Vector2D pos;
    SDL_Rect rect;
    SDL_Texture* objtex;

public:
    GameObject(int x, int y, SDL_Texture* o_tex);
    SDL_Rect getRect();
    SDL_Texture* getTex();
    Vector2D getpos();
    virtual ~GameObject();
};

class MovingObject: public GameObject {
private:
    Vector2D speed; 
    bool move = true;
public:

    MovingObject(int x, int y, SDL_Texture* o_tex);
    bool Collision();

};

class Player: public MovingObject {
    public:
    void Jump();
    void MoveRight();
    void MoveLeft();
    void Shoot();
    void Gravity();


};

class FireBall: public MovingObject {
    void P_Collide();
};

class Platform: public GameObject{
    void moveUp();
    void moveDown();
    void Oscillate();
};

class Coin: public GameObject{
    void P_Collide();
};

class Button: public GameObject{

};







