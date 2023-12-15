#pragma once

#include <SDL.h>
#include <vector>
#include <cmath>
#include "vector.cpp"


class GameObject {
private:
    Vector2D pos;
    SDL_Rect rect;
    SDL_Texture* objtex;

public:
    GameObject(int x, int y, SDL_Texture* o_tex);
    void changeTex(SDL_Texture* o_tex);
    SDL_Rect getRect();
    SDL_Texture* getTex();
    Vector2D getpos();
    void setpos(int x, int y);
    virtual ~GameObject();
};


class MovingObject: public GameObject {
private:
    Vector2D speed;
protected:
    bool isJumping = false; 

public:
    MovingObject(int x, int y, SDL_Texture* m_tex);
    bool Collision(GameObject& platform);
    Vector2D getSpeed();
    void setSpeed(float m_x, float m_y);
    void Gravity(std::vector<GameObject*> objects);

};


class Player: public MovingObject {
    public:
    Player(int x, int y, SDL_Texture* p_tex);
    void MoveRight(std::vector<GameObject*> objects);
    void MoveLeft( std::vector<GameObject*> objects);
    void Jump(std::vector<GameObject*> objects);
    

};



class MovingPlatform: public MovingObject {
    public:
    MovingPlatform(int x, int y, SDL_Texture* p_tex);
    void Moving();
   
};

class Coin: public GameObject {
    public:
    Coin(int x, int y, SDL_Texture* c_tex);
    bool Collision(Player* player);
};

class Door: public GameObject{
    public:
    bool Collision(Player* player);
};

class Button: public GameObject{
    bool Collision(Player* player);

};


class Box: public MovingObject{
    bool Collision(Player* player);

};





