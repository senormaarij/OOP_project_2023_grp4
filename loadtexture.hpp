#include "game.hpp"

#ifndef LOADTEXTURE_HPP
#define LOADTEXTURE_HPP

class loadtexture{
    public:
    static SDL_Texture* LoadTexture(const char* fileName);
};

#endif // LOADTEXTURE_HPP