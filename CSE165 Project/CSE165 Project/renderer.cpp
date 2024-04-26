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

void renderer::render_loop(keyboardFunc action, images background, std::vector<images> textures)
{
	while (1)
	{
		SDL_SetRenderDrawColor(rndrer, 28, 9, 41, 212); // Set window background color
		SDL_RenderClear(rndrer);
		//background.show();
		
		for (int i = 0; i < 2; i++)
		{
			SDL_UpdateWindowSurface(SDL_GameWindow);
			textures[i].show();
			//std::cout << "texture drawn: " << i << std::endl;
			//std::cout << textures[i].posX << std::endl;
		}
		//SDL_UpdateWindowSurface(SDL_GameWindow);
		
		//======================================
		// Replace this with keyboardFunc somehow 
		
		action.input();

		//======================================
		SDL_RenderPresent(rndrer);
		SDL_Delay(12);
	}
}