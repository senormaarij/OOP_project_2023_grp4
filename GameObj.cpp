#include "GameObj.hpp"
#include "loadtexture.hpp"
#include "Game.hpp"  // Assuming Game::Renderer is defined here

GameObject::GameObject(const char* filename) {


    objtex = loadtexture::LoadTexture(filename);
    xpos = 0;
    ypos = 300;
    velocityX = 0;
    velocityY = 0;

}

int Objects::counter = 0;


GameObject::GameObject(const char* filename, int& x, int& y)
{
    objtex = loadtexture::LoadTexture(filename);
    xpos = x;
    ypos = y;
    Objects::counter++;
} 

GameObject::~GameObject() {
    SDL_DestroyTexture(objtex);
}

void GameObject::Render() {
    SDL_RenderCopy(Game::Renderer, objtex, &srcR, &destR);
}

void GameObject::Gravity() {
    const float gravity = 0.5;  // Adjust this value as needed
    if (ypos < 500) {
        velocityY += gravity;
    }
}

void GameObject::Stop() {
    velocityX = 0;
}

void GameObject::Update() {
    srcR.w = 64;
    srcR.h = 64;
    srcR.x = 0;
    srcR.y = 0;
    destR.w = srcR.w / 2;
    destR.h = srcR.h / 2;

    //std::cout << velocityX << "\n";
    xpos = xpos + velocityX;
    ypos = ypos + velocityY;

    if (ypos > 500) {
        ypos = 500;
    }

    if (xpos < 0)
    {
        xpos = 0;
    }

    destR.x = xpos;
    destR.y = ypos;

    Gravity();
    
    
    //std::cout << xpos << ", " << ypos << "\n";
}

void Player::Update(const std::vector<GameObject*>& objects) {
    srcR.w = 64;
    srcR.h = 64;
    srcR.x = 0;
    srcR.y = 0;
    destR.w = srcR.w;
    destR.h = srcR.h;

    xpos = xpos + velocityX;
    ypos = ypos + velocityY;

    // Ensure the player stays within the game window
    if (ypos > 500) {
        ypos = 500;
        // Reset vertical velocity when the player is on the ground
        velocityY = 0;
    }

    if (xpos < 0) {
        xpos = 0;
    }

    if (xpos >= 800 - 64) {
        xpos = 800 - 64;
    }

    destR.x = xpos;
    destR.y = ypos;

    Gravity();
    CollisionY(objects);
}

void Objects::Update()
{
    srcR.w = 64;
    srcR.h = 64;
    srcR.x = 0;
    srcR.y = 0;
    destR.w = srcR.w / 2;
    destR.h = srcR.h / 2;

    //std::cout << velocityX << "\n";
    xpos = xpos;
    ypos = ypos;

    if (ypos > 500) {
        ypos = 500;
    }

    destR.x = xpos;
    destR.y = ypos;
}





Player::Player(const char* filename) : GameObject(filename) {}




void Player::Jump() 
{
    if (ypos >= 500 || ypos <= 1000) {
        velocityY = -10;
    }
}

void Player::MoveRight() {
    velocityX = 5;
}

void Player::MoveLeft() {
    velocityX = -5;
}

Objects::Objects(const char* filename,int x, int y) : GameObject(filename,x, y){};

void Player::CollisionY(const std::vector<GameObject*>& objects) 
{
    for (GameObject* obj : objects) {
        Collision(obj);
    }
}

void Player::Collision(GameObject *g) {
    // Check for intersection in both x and y dimensions
    if (destR.x < g->destR.x + g->destR.w &&
        destR.x + destR.w > g->destR.x &&
        destR.y < g->destR.y + g->destR.h &&
        destR.y + destR.h > g->destR.y)
    {
        // Calculate the overlap in both dimensions
        int xOverlap = std::min(destR.x + destR.w, g->destR.x + g->destR.w) - std::max(destR.x, g->destR.x);
        int yOverlap = std::min(destR.y + destR.h, g->destR.y + g->destR.h) - std::max(destR.y, g->destR.y);

        // Adjust player position based on the smaller overlap
        if (xOverlap < yOverlap) {
            // Adjust horizontal position
            if (destR.x + destR.w / 2 < g->destR.x + g->destR.w / 2) {
                // Player is colliding from the left, adjust position to the left of the object
                xpos = g->destR.x - destR.w;
            } else {
                // Player is colliding from the right, adjust position to the right of the object
                xpos = g->destR.x + g->destR.w;
            }

            // Stop horizontal movement
            velocityX = 0;
        } else {
            // Adjust vertical position
            if (destR.y + destR.h / 2 < g->destR.y + g->destR.h / 2) {
                // Player is colliding from the top, adjust position above the object
                //ypos = g->destR.y - destR.h;
            } else {
                // Player is colliding from the bottom, adjust position below the object
                ypos = g->destR.y + g->destR.h;
            }

            // Stop vertical movement
            velocityY = 0;
        }
    }
}






