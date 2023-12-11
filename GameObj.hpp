#pragma once

#include <SDL.h>
#include <vector>
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
//

class MovingObject: public GameObject {
private:
    Vector2D speed; 

public:
    MovingObject(int x, int y, SDL_Texture* m_tex);
    Vector2D getSpeed();
    void setSpeed(float m_x, float m_y);

};


class Player: public MovingObject {
    private:
    bool isJumping = false;

    public:
    Player(int x, int y, SDL_Texture* p_tex);
    bool Collision(GameObject& platform);
    void MoveRight(std::vector<GameObject*> objects);
    void MoveLeft( std::vector<GameObject*> objects);
    void Jump(std::vector<GameObject*> objects);
    void Gravity(std::vector<GameObject*> objects);
    





};




