#include "renderer.h"
#include <SDL.h>

renderer::renderer()
{
	windowWidth = 1600;
	windowHeight = 900;
	windowflags = SDL_WINDOW_OPENGL;
	rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
}

renderer::~renderer()
{
	SDL_DestroyWindow(SDL_GameWindow);
}

void renderer::render_start()
{
	SDL_GameWindow = SDL_CreateWindow("Game Name", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, windowflags);
	rndrer = SDL_CreateRenderer(SDL_GameWindow, -1, rendererFlags); // (Window, -1 is the first rendering driver to support flags, 0 or flags | together)
}

void renderer::render_loop(keyboardFunc action)
{
<<<<<<< Updated upstream
=======

	std::vector<bullet*> bullets;

	Timer test;

>>>>>>> Stashed changes
	while (1)
	{
		SDL_SetRenderDrawColor(rndrer, 28, 9, 41, 212); // Set window background color
		SDL_RenderClear(rndrer);
<<<<<<< Updated upstream

=======
		//background.show();
		backgroundMove(textures, 3);
		
		shooting(scenes, playerShip, bullets);

		for (int i = 0; i < 3; i++) // background draw
		{
			textures[i]->show();
		}
		if (playerShip->getHitPoints() == 3)
		{
			textures[3]->show();
			textures[4]->show();
			textures[5]->show();
		}
		else if (playerShip->getHitPoints() == 2)
		{
			textures[4]->show();
		}
		else if (playerShip->getHitPoints() == 1)
		{
			textures[3]->show();
		}

		
		test.Count();

		std::cout << test.getTime() << std::endl;

		if (test.getTime() >= 5) {
			test.resetTimer();
		}







		playerShip->texture->show();

		for (int j = 0; j < scenes[0]->actorList.size(); j++)
		{
			if (!scenes[0]->actorList[j]->getShown())
			{
				scenes[0]->actorList[j]->texture->show();
				scenes[0]->actorList[j]->setShown();
			}
			else
			{
				// use this with movement later so unshown enemies will stay in their spawn positions
				scenes[0]->actorList[j]->texture->show();
				scenes[0]->actorList[j]->shoot();
				scenes[0]->actorList[j]->movement();
			}
		
		}

		for (int i = 0; i < bullets.size(); i++) {
			bullets[i]->texture->show();
		}
		
>>>>>>> Stashed changes
		//======================================
		// Replace this with keyboardFunc somehow 
		
		action.input();

		//======================================
		SDL_RenderPresent(rndrer);
		SDL_Delay(12);
	}
}