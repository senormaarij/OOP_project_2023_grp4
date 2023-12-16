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










