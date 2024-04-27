#pragma once
#include <vector>
#include "enemy.h"

class scene
{

	//std::vector<actor*> actorList;
	int timeDelay;


public:

	std::vector<actor*> actorList;

	scene();
	scene(SDL_Renderer*);
	scene(SDL_Renderer*, int i);
	scene(SDL_Renderer*, int i, int j);
	~scene();


};

