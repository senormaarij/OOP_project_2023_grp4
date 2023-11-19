#include "loadtexture.hpp"

SDL_Texture* loadtexture::LoadTexture(const char* filename){
    SDL_Surface* playsurface = IMG_Load(filename);//creates a surface from an image
    SDL_Texture* texture  = SDL_CreateTextureFromSurface(Game::Renderer, playsurface); //creates a texture from a surface
    SDL_FreeSurface(playsurface);//frees the surface or playsurface becomes NULL
    return texture;
}