#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "renderer.h"
#include "images.h"

//=============================================================
// SDL Documentation
// https://wiki.libsdl.org/SDL2/FrontPage
//=============================================================


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

	if (SDL_Init(SDL_INIT_TIMER) == 0)
	{
		std::cout << "Timer Initialized Successfully" << std::endl;
	}
	else
	{
		std::cout << SDL_GetError() << std::endl;
	}

}

void SDLSHUTDOWN(void)
{
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	SDL_QuitSubSystem(SDL_INIT_TIMER);
	SDL_Quit();
}

void init(void)
{

}

//=============================================================
// Main
//=============================================================

int main(int argc, char** argv)
{	

	SDLINIT(); // Initializes SDL subsystems

	{
		renderer r;
		keyboardFunc user; // maybe rename class
		r.render_start();

		//Need to create loop to keep everything going
		r.render_loop(user);
	}

	SDLSHUTDOWN(); // destroys subsystems on exit so no leaks or something
	return 0;
}