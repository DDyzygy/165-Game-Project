#pragma once
#include <SDL.h>
#include "keyboardFunc.h"

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

	void render_loop(keyboardFunc);
	
	void render_start();

};

