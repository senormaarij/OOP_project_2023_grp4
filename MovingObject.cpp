#include "MovingObject.hpp"
MovingObject::MovingObject(int x, int y, SDL_Texture* m_tex):GameObject(x,y,m_tex){} 

void MovingObject::setSpeed(float m_x, float m_y){speed.x = m_x; speed.y = m_y;}

Vector2D MovingObject::getSpeed(){return speed;}


void MovingObject::Gravity(std::vector<GameObject*> objects){
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

bool MovingObject::Collision(GameObject& platform){	
     return (getpos().y + getRect().h > platform.getpos().y &&
                getpos().y < platform.getpos().y + platform.getRect().h &&
                getpos().x + getRect().w > platform.getpos().x &&
                getpos().x < platform.getpos().x + platform.getRect().w);
    
}