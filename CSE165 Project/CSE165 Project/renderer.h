#pragma once
#include <SDL.h>
#include <vector>
#include "keyboardFunc.h"
#include "images.h"

class renderer
{
	
	SDL_Renderer* rndrer;
	SDL_Window* SDL_GameWindow;

	//Window properties
	int windowWidth;
	int windowHeight;
	Uint32 windowflags;
	
	Uint32 rendererFlags;

public:

	renderer();
	~renderer();

	SDL_Renderer* getRenderer();

	SDL_Window* getWindow();

	void render_loop(keyboardFunc, images, std::vector<images>);
	
	void render_start();

};

