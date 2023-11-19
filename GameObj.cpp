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

    std::cout << velocityX << "\n";
    xpos = xpos + velocityX;
    ypos = ypos + velocityY;

    if (ypos > 500) {
        ypos = 500;
    }

    destR.x = xpos;
    destR.y = ypos;

    Gravity();

    std::cout << xpos << ", " << ypos << "\n";
}

Player::Player(const char* filename) : GameObject(filename) {}

void Player::Jump() {
    if (ypos == 500) {
        velocityY = -10;
    }
}

void Player::MoveRight() {
    velocityX = 5;
}

void Player::MoveLeft() {
    velocityX = -5;
}
