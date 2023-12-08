#include "GameObj.hpp"
#include "loadtexture.hpp"
#include "Game.hpp" 
#include <cmath>


GameObject::GameObject(int x, int y, SDL_Texture* o_tex) {
    objtex = o_tex;
    rect.x = 0;
    rect.y = 0;
}

SDL_Rect GameObject::getRect(){return rect;}

Vector2D GameObject::getpos(){return pos;}

SDL_Texture* GameObject::getTex(){return objtex;}

GameObject::~GameObject() {
    SDL_DestroyTexture(objtex);
}


