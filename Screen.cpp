#include "Screen.hpp"


Screen::Screen(SDL_Texture* start_text){
    s_tex = start_text;
}

void Screen::switch_screen(SDL_Texture* ns_tex){
    s_tex = ns_tex;
}

SDL_Texture* Screen::getTex(){
    return s_tex;
}