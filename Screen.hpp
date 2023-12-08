#include "loadtexture.hpp"
#include "vector.cpp"

class Screen{
    SDL_Texture* s_tex;

    public:
    Screen(SDL_Texture* start_text);
    void switch_screen(SDL_Texture* s_tex);
    SDL_Texture* getTex();
};
