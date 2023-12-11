
#include "GameObj.hpp"

GameObject::GameObject(int x, int y, SDL_Texture* o_tex) {
    pos.x = x;
    pos.y = y;
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





void Player::MoveLeft(std::vector<GameObject*> objects){
    for( int i = 0; i < 8; i++){
        setpos(getpos().x - 1, getpos().y);
        for (int i = 0; i < objects.size(); i++) {
            if (Collision(*(objects[i]))) {

                setpos(getpos().x + 1, getpos().y);
                break;
            }
        }
    }
}

void Player::MoveRight(std::vector<GameObject*> objects){
    for( int i = 0; i < 8; i++){
        setpos(getpos().x + 1, getpos().y);
        for (int i = 0; i < objects.size(); i++) {
            if (Collision(*(objects[i]))) {
                setpos(getpos().x - 1, getpos().y);
                break;
            }
        }
    }
}

void Player::Jump(std::vector<GameObject*> objects){
    if(!isJumping){
        setSpeed(0,-13.0f);
        isJumping = true;
    }
}


void Player::Gravity(std::vector<GameObject*> objects){
   if (getpos().y < 500) {
        setSpeed(getSpeed().x, getSpeed().y + 0.6f) ; // gravity force
        float originalY = getpos().y; // original position

        setpos(getpos().x, getpos().y + getSpeed().y); // Move player

        bool collided = false;
        for (int i = 0; i < objects.size(); i++) {
            if (Collision(*objects[i])) {
                collided = true;
                if (getSpeed().y > 0) {
                    setpos(getpos().x, objects[i]->getpos().y - getRect().h);
                    isJumping = false;
                    setSpeed(getSpeed().x,0.0f);
                } else if (getSpeed().y  < 0) {  
                    setpos(getpos().x,objects[i]->getpos().y  + objects[i]->getRect().h); 
                    setSpeed(getSpeed().x,0.0f);
                }
                break;
            }
        }

        if (!collided) {
            isJumping = true;
        }
    } else {
        isJumping = false;
        setSpeed(getSpeed().x,0.0f) ;
        setpos(getpos().x, 500);
    }
}

bool Player::Collision(GameObject& platform){	
     return (getpos().y + getRect().h > platform.getpos().y &&
                getpos().y < platform.getpos().y + platform.getRect().h &&
                getpos().x + getRect().w > platform.getpos().x &&
                getpos().x < platform.getpos().x + platform.getRect().w);
    
}













