#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObj.hpp"



class RenderWindow {
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	void cleanUp();
	void clear();
	void render(GameObject& p_gobject);
	void display();

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};