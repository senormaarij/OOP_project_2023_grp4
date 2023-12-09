
#include "GameObj.hpp"

GameObject::GameObject(int x, int y, SDL_Texture* o_tex) {
    pos = Vector2D(x,y);
    objtex = o_tex;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(o_tex, NULL, NULL, &rect.w, &rect.h); //automatically gets the width and height of texture and sets it on rect
    setpos(pos.x, (pos.y-rect.h)); //offset
}

SDL_Rect GameObject::getRect(){return rect;} //gets the rect

Vector2D GameObject::getpos(){return pos;} //gets the position

void GameObject::setpos(int x, int y){pos.x = x; pos.y = y;} //sets the position

void GameObject::changeTex(SDL_Texture* o_tex){objtex = o_tex;} //changes the texture


SDL_Texture* GameObject::getTex(){return objtex;} //gets the texture

GameObject::~GameObject() {
    SDL_DestroyTexture(objtex);
}

MovingObject::MovingObject(int x, int y, SDL_Texture* m_tex):GameObject(x,y,m_tex){}

void MovingObject::setSpeed(float m_x, float m_y){speed.x = m_x; speed.y = m_y;}

Vector2D MovingObject::getSpeed(){return speed;}

Player::Player(int x, int y, SDL_Texture* p_tex):MovingObject(x,y,p_tex){}

void Player::MoveLeft(){
    for (int i = 0; i < 10; i++){
        setpos(getpos().x - 1, getpos().y);
    }
}

void Player::MoveRight(){
    for (int i = 0; i < 10; i++){
        setpos(getpos().x + 1, getpos().y);
    }
}












