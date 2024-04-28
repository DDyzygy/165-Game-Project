#pragma once
#include <SDL.h>
#include <vector>
#include <algorithm>
#include "keyboardFunc.h"
#include "scene.h"
#include "images.h"
#include "bullet.h"
#include "player.h"

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

	void render_loop(keyboardFunc, player*, std::vector<scene*>, std::vector<images*> );

	void shooting(std::vector<scene*> &scenes, player* &playerShip, std::vector<bullet*> &bullets);

	void backgroundMove(std::vector<images*> background, int speed);

	void render_start();

};

