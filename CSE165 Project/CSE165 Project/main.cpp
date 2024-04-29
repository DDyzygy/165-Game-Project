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
		player* player1 = new player(r.getRenderer());

		scene* level1 = new scene(r.getRenderer());
		scene* level2 = new scene(r.getRenderer(), 2);
		scene* level3 = new scene(r.getRenderer(), 2, 3);

		scenes.push_back(level1);
		scenes.push_back(level2);
		scenes.push_back(level3);

		textures.emplace_back(new images("images/spacebackgrounddouble.jpg", r.getRenderer(), 800, 1600, 400, 800, 0));//0
		textures.emplace_back(new images("images/spacebackgrounddouble.jpg", r.getRenderer(), 800, 1620, 400, -800, 0));
		textures.emplace_back(new images("images/PointsText.png", r.getRenderer(), 70, 70, 700, 40, 1));
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 50, 40, 1));//3
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 75, 40, 1));
		textures.emplace_back(new images("images/OneHitPoint.png", r.getRenderer(), 60, 60, 100, 40, 1));
		textures.emplace_back(new images("images/NoHitPoint.png", r.getRenderer(), 60, 60, 50, 40, 1));
		textures.emplace_back(new images("images/NoHitPoint.png", r.getRenderer(), 60, 60, 75, 40, 1));
		textures.emplace_back(new images("images/NoHitPoint.png", r.getRenderer(), 60, 60, 100, 40, 1));//8
		textures.emplace_back(new images("images/0.png", r.getRenderer(), 70, 70, 750, 40, 1));//9 -- 0.png keep size and y value, just move default x
		textures.emplace_back(new images("images/1.png", r.getRenderer(), 70, 70, 750, 40, 1));//10
		textures.emplace_back(new images("images/2.png", r.getRenderer(), 70, 70, 750, 40, 1));//11
		textures.emplace_back(new images("images/3.png", r.getRenderer(), 70, 70, 750, 40, 1));//12
		textures.emplace_back(new images("images/4.png", r.getRenderer(), 70, 70, 750, 40, 1));//13
		textures.emplace_back(new images("images/5.png", r.getRenderer(), 70, 70, 750, 40, 1));//14
		textures.emplace_back(new images("images/6.png", r.getRenderer(), 70, 70, 750, 40, 1));//15
		textures.emplace_back(new images("images/7.png", r.getRenderer(), 70, 70, 750, 40, 1));//16
		textures.emplace_back(new images("images/8.png", r.getRenderer(), 70, 70, 750, 40, 1));//17
		textures.emplace_back(new images("images/9.png", r.getRenderer(), 70, 70, 750, 40, 1));//18
		textures.emplace_back(new images("images/StartButton.png", r.getRenderer(), 400, 180, 400, 400, 1));//19
		textures.emplace_back(new images("images/GAMEOVER.png", r.getRenderer(), 240, 36, 400, 400, 1));//20
		textures.emplace_back(new images("images/VictoryScreen.png", r.getRenderer(), 200, 66, 400, 400, 1));//21


		//Need to create loop to keep everything going
		r.render_loop(user, player1, scenes, textures);
		
		//r.render_loop(user, ship, background);

	}

	SDLSHUTDOWN(); // destroys subsystems on exit so no leaks or something
	return 0;
}