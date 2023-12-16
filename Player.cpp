#include "Player.hpp"



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