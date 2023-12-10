
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

void Player::MoveLeft(std::vector<GameObject> objects){
    for (int i = 0; i < 5; i++){
        setpos(getpos().x - 1, getpos().y);
        if (Collision(objects)){
            setpos(getpos().x + 1, getpos().y);
            break;
        }
    }
}

void Player::MoveRight(std::vector<GameObject> objects){
    for (int i = 0; i < 5; i++){
        setpos(getpos().x + 1, getpos().y);
        if (Collision(objects)){
            setpos(getpos().x - 1, getpos().y);
            break;
        }
    }
}

void Player::Jump(std::vector<GameObject> objects){
        for (int i = 0; i < 70; i++){
        setpos(getpos().x, getpos().y - 1);
            if (Collision(objects)){
                setpos(getpos().x, getpos().y + 1);
                break;
            }    
        }
}

void Player::Gravity(std::vector<GameObject> objects){
    for (int i = 0; i < 5; i++){
        setpos(getpos().x, getpos().y + 1);
        if (Collision(objects)){
            setpos(getpos().x, getpos().y - 1);
            
            break;
        }
    }
    
}

bool Player::Collision(std::vector<GameObject>& objects){	
	int gWidth, gHeight;
	bool collisionDetected = false;

	int pWidth  = getRect().w; // Get size of player.
	int pHeight = getRect().h;

	for (GameObject& ground : objects){
		gWidth  = ground.getRect().w; // Get size of ground block.
		gHeight = ground.getRect().h;

		collisionDetected = (( (getpos().y + pHeight) >  (ground.getpos().y)            )    // Player is within ground-height range.
						&&   ( (getpos().y)           <  (ground.getpos().y + gHeight)  )
						&&   ( (getpos().x + pWidth)  >  (ground.getpos().x)            )    // Player is within ground-width range.
						&&   ( (getpos().x)           <  (ground.getpos().x + gWidth)   ) );

		if (collisionDetected)
			break;
	}

	collisionDetected = (    ( (getpos().y + pHeight) >  600   )    // Player is outside screen Height range.
						||   ( (getpos().x + pWidth)  >  800  )    // Player is outside screen Width range.
						||   ( (getpos().x)           <  0    ))
						|| collisionDetected ;
	
	return collisionDetected;	
}


bool Player::canJump(std::vector<GameObject> platforms)
{	
	int gWidth;
	bool canJump = false;

	int pWidth  = getRect().w; // Get size of player.
	int pHeight = getRect().h;

	for (GameObject& ground : platforms){
		gWidth  = ground.getRect().w; // Get size of ground block.

		canJump = ((    getpos().y + pHeight  ==  ground.getpos().y              )    // Player is standing on platform.
			      &&   (getpos().x + pWidth   >=  ground.getpos().x + 5          )    // Player is within platform-width range.
		     	  &&   (getpos().x  <=  ground.getpos().x + gWidth - 5 ) );

		if (canJump)
			break;
	}
	return canJump;	
}













