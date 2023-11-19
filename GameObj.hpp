#include "game.hpp"
#include "loadtexture.hpp"

class GameObject {
protected:
    int xpos;
    int ypos;
    float velocityY;
    float velocityX;
    SDL_Rect srcR, destR;
    SDL_Texture* objtex;

public:
    GameObject(const char* filename);
    virtual ~GameObject();

    virtual void Update();
    void Render();
    void Gravity();
    void Stop();
};

class Player : public GameObject {
public:
    Player(const char* filename);

    void Jump();
    void MoveRight();
    void MoveLeft();
};
