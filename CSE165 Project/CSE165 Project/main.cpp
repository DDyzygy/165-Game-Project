#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "renderer.h"

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
<<<<<<< Updated upstream

		//Need to create loop to keep everything going
		r.render_loop(user);
=======
		//images* ship = new images("images/PlayerShip1.png", r.getRenderer(), 100, 100, 400, 650,1);
		//images* background = new images("images/spacebackground.jpg", r.getRenderer(), 800, 800, 400, 400,1);
		player* player1 = new player(r.getRenderer());

		scene* level1 = new scene(r.getRenderer());
		scene* level2 = new scene(r.getRenderer());
		scene* level3 = new scene(r.getRenderer());
		scenes.push_back(level1);

		//Need to create loop to keep everything going
		textures.emplace_back(new images("images/spacebackgrounddouble.jpg", r.getRenderer(), 800, 1600, 400, 800, 0)); //0
		textures.emplace_back(new images("images/spacebackgrounddouble.jpg", r.getRenderer(), 800, 1600, 400, -800, 0));
		textures.emplace_back(new images("images/PointsText.png", r.getRenderer(), 60, 60, 700, 40, 1));
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 50, 40, 1)); //3
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 75, 40, 1));
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 100, 40, 1));
		textures.emplace_back(new images("images/NoHitPoint.png", r.getRenderer(), 60, 60, 50, 40, 1));
		textures.emplace_back(new images("images/NoHitPoint.png", r.getRenderer(), 60, 60, 75, 40, 1));
		textures.emplace_back(new images("images/NoHitPoint.png", r.getRenderer(), 60, 60, 100, 40, 1)); //8
		//textures.push_back(background);
		//textures.push_back(background);


		r.render_loop(user, player1, scenes, textures);
		
		//r.render_loop(user, ship, background);

>>>>>>> Stashed changes
	}

	SDLSHUTDOWN(); // destroys subsystems on exit so no leaks or something
	return 0;
}