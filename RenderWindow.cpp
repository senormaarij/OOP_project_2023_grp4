#include "RenderWindow.hpp"


SDL_Window* RenderWindow::getWindow(){return window;}

SDL_Renderer* RenderWindow::getRenderer(){return renderer;}


RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN); // window created 

	if (window == NULL){
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl; //flag to check window created 
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //renderer created
}

void RenderWindow::cleanUp(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void RenderWindow::clear(){
	SDL_RenderClear(renderer);
}

void RenderWindow::render(GameObject& g_object){
	SDL_Rect src;
	src.x = g_object.getRect().x;
	src.y = g_object.getRect().y;
	src.w = g_object.getRect().w;
	src.h = g_object.getRect().h;

	SDL_Rect dst;
	dst.x = g_object.getpos().x;
	dst.y = g_object.getpos().y;
	dst.w = g_object.getRect().w;
	dst.h = g_object.getRect().h;

	SDL_RenderCopy(renderer, g_object.getTex(), &src, &dst);
}


SDL_Texture* RenderWindow::LoadTexture(const char* filename){ 
 	SDL_Surface* playsurface = IMG_Load(filename);//creates a surface from an image
    SDL_Texture* texture  = SDL_CreateTextureFromSurface(renderer, playsurface); //creates a texture from a surface
    SDL_FreeSurface(playsurface);//frees the surface or playsurface becomes NULL
    return texture;
}

void RenderWindow::render(Screen& g_screen){
    SDL_RenderCopy(renderer,g_screen.getTex(), NULL, NULL);
}

void RenderWindow::display(){
	SDL_RenderPresent(renderer);
}