#include "Coin.hpp"


Coin::Coin(int x, int y, SDL_Texture* c_tex):GameObject(x,y,c_tex){}

bool Coin::Collision(Player* player){
    return (getpos().y + getRect().h > player->getpos().y &&
            getpos().y < player->getpos().y + player->getRect().h &&
            getpos().x + getRect().w > player->getpos().x &&
            getpos().x < player->getpos().x + player->getRect().w);
}


