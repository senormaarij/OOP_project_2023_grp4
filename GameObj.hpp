#pragma once

#include <SDL.h>
#include <vector>
#include "vector.cpp"


class GameObject {
private:
    Vector2D pos;
    SDL_Rect rect;
    SDL_Texture* objtex;

protected:
    char element; //f for fire, w for water

public:
    GameObject(int x, int y, SDL_Texture* o_tex);
    void changeTex(SDL_Texture* o_tex);

    SDL_Rect getRect();

    SDL_Texture* getTex();

    Vector2D getpos();

    void setpos(int x, int y);

    //virtual bool Collision();
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
    public:
    Player(int x, int y, SDL_Texture* p_tex);
    // bool Collision() override;
    // void Jump();
    //void switch_element();
    void MoveRight();
    void MoveLeft();
    // void Shoot();
    // void Gravity();
};




/* class FireBall: public MovingObject {
    void Button_Collide();
};
 */


/* class Platform: public GameObject{
    void moveUp();
    void moveDown();
    void Oscillate();
}; */

/* class Coin: public GameObject{
    bool Collision() override;
}; */

/* class Button: public GameObject{
    bool Collision() override;
};
 */






