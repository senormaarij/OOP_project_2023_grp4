#include "game.hpp"
#include "loadtexture.hpp"
#include <vector>

class GameObject {
public:
    int xpos;
    int ypos;
    float velocityY;
    float velocityX;
    SDL_Rect srcR, destR;
    SDL_Texture* objtex;

public:
    GameObject(const char* filename);
    GameObject(const char* filename,int& x, int& y);
    virtual ~GameObject();

    virtual void Update();
    void Render();
    void Gravity();
    void Stop();
    //void HandleCollision(GameObject *g);
};

class Player : public GameObject {
private:
    bool move = true;
public:

    Player(const char* filename);

    void Jump();
    void MoveRight();
    void MoveLeft();
    void Update(const std::vector<GameObject*>& objects);
    void Collision(GameObject *g);
    void CollisionY(const std::vector<GameObject*>& objects);
    void CollisionY(GameObject *g);
    //bool CollisionX(GameObject *g);


};

class Objects : public GameObject
{
    public:
        static int counter;
        Objects(const char* filename,int x, int y);
        void Update();
};