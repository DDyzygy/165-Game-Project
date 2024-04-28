#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "renderer.h"
#include "images.h"
#include "scene.h"
#include "bullet.h"
#include "player.h"

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
		std::vector<scene*> scenes;
		r.render_start();
		//images* ship = new images("images/PlayerShip1.png", r.getRenderer(), 100, 100, 400, 650,1);
		images* background = new images("images/spacebackground.jpg", r.getRenderer(), 800, 800, 400, 400,1);
		player* player1 = new player(r.getRenderer());

		scene* level1 = new scene(r.getRenderer());

		scenes.push_back(level1);

		//Need to create loop to keep everything going
		textures.emplace_back(new images("images/spacebackgrounddouble.jpg", r.getRenderer(), 800, 1600, 400, 800, 0));
		textures.emplace_back(new images("images/spacebackgrounddouble.jpg", r.getRenderer(), 800, 1600, 400, -800, 0));
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 50, 40, 1));
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 75, 40, 1));
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 100, 40, 1));
		textures.push_back(background);
		//textures.push_back(background);


		r.render_loop(user, player1, scenes, textures);
		
		//r.render_loop(user, ship, background);

	}

	SDLSHUTDOWN(); // destroys subsystems on exit so no leaks or something
	return 0;
}