#include "GameObject.hpp"

class Oscilator: public GameObject{
    public:
    Oscilator(int x, int y, SDL_Texture* o_tex):GameObject(x,y,o_tex){};
    void Oscillate();


    void Oscillate() {
    if (isJumping) {
        speed.setY(speed.getY() + 0.1);
    }
    else {
        speed.setY(speed.getY() - 0.1);
    }
    if (speed.getY() > 3) {
        isJumping = false;
    }
    if (speed.getY() < -3) {
        isJumping = true;
    }
    setSpeed(speed.getX(), speed.getY());
}
}

