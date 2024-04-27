#include "renderer.h"
#include <SDL.h>

renderer::renderer()
{
	windowWidth = 800;
	windowHeight = 800;
	windowflags = SDL_WINDOW_OPENGL;
	rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

	// NOTE: 400, 400 is the center of the window
	// 0, 0 is the top left 
	// the larger Y is, the further down it goes
	// the larger X is, the further right it goes
}

renderer::~renderer()
{
	SDL_DestroyWindow(SDL_GameWindow);
}

SDL_Renderer* renderer::getRenderer()
{
	return rndrer;
}

SDL_Window* renderer::getWindow()
{
	return SDL_GameWindow;
}


void renderer::render_start()
{
	SDL_GameWindow = SDL_CreateWindow("Game Name", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, windowflags);
	rndrer = SDL_CreateRenderer(SDL_GameWindow, -1, rendererFlags); // (Window, -1 is the first rendering driver to support flags, 0 or flags | together)
}

void renderer::render_loop(keyboardFunc action, images* playerShip, std::vector<scene*> scenes, std::vector<images*> textures)
{
	while (1)
	{

		SDL_SetRenderDrawColor(rndrer, 28, 9, 41, 212); // Set window background color
		SDL_RenderClear(rndrer);
		//background.show();
		//second.show();
		
		for (int i = 0; i < 1; i++)
		{
			textures[i]->show();
		}

		playerShip->show();


		for (int j = 0; j < scenes[0]->actorList.size(); j++)
		{
			scenes[0]->actorList[j]->texture->show();
		}

		//SDL_UpdateWindowSurface(SDL_GameWindow);
		
		//======================================
		// Replace this with keyboardFunc somehow 
		//maybe load a scene class into the render loop?
		action.input(playerShip);

		//======================================
		SDL_RenderPresent(rndrer);
		SDL_Delay(12);
	}
}