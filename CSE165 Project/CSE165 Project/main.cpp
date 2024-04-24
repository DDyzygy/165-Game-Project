#include <SDL.h>
#include <iostream>


//=============================================================
// SDL Documentation
// https://wiki.libsdl.org/SDL2/FrontPage
//=============================================================


void render_loop()
{
	SDL_SetRenderDrawColor(renderer, 14, );

	while()
}


void SDLINIT(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		std::cout << "Video Initialized Successfully" << std::endl;
	}
	else
	{
		std::cout << SDL_GetError() << std::endl;
	}
	
	if (SDL_Init(SDL_INIT_AUDIO) == 0)
	{
		std::cout << "Audio Initialized Successfully" << std::endl;
	}
	else
	{
		std::cout << SDL_GetError() << std::endl;
	}
}

void init(void)
{

}

//=============================================================
// Main
//=============================================================

int main(int argc, char** argv)
{
	SDLINIT();
	
	SDL_Window *SDL_GameWindow = SDL_CreateWindow("Game Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL | SDL_WINDOW_MOUSE_GRABBED | SDL_WINDOW_KEYBOARD_GRABBED);
	SDL_Renderer *renderer = SDL_CreateRenderer(SDL_GameWindow, -1, 0); // (Window, -1 is the first rendering driver to support flags, 0 or flags | together)
	//Need to create loop to keep everything going
	SDL_WaitEvent();


	render_loop();

	return 0;
}