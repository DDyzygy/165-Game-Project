#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
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
		std::vector<images*> textures;
		r.render_start();
		images* ship = new images("images/PlayerShip1.png", r.getRenderer(), 100, 100, 500, 450);
		images* background = new images("images/spacebackground.jpg", r.getRenderer(), 1600, 900, 800, 450);

		//Need to create loop to keep everything going
		textures.push_back(ship);
		textures.push_back(background);


		r.render_loop(user, textures);
		
		//r.render_loop(user, ship, background);

	}

	SDLSHUTDOWN(); // destroys subsystems on exit so no leaks or something
	return 0;
}