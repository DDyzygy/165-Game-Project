#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


//=============================================================
// SDL Documentation
// https://wiki.libsdl.org/SDL2/FrontPage
//=============================================================


void render_loop(SDL_Renderer *renderer)
{
	while (1)
	{
		SDL_SetRenderDrawColor(renderer, 14, 4, 60, 212); // Set window background color
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}	
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
	
	SDL_Window *SDL_GameWindow = SDL_CreateWindow("Game Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
	SDL_Renderer *renderer = SDL_CreateRenderer(SDL_GameWindow, -1, 0); // (Window, -1 is the first rendering driver to support flags, 0 or flags | together)
	//Need to create loop to keep everything going
	

	
	render_loop(renderer);

	return 0;
}