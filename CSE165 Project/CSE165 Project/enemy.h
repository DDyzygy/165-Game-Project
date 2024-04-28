#pragma once
#include "actor.h"

class enemy : public actor
{

public:

	enemy(SDL_Renderer*, int x, int y); // Handles minor enemy
	enemy(SDL_Renderer*, int x, int y, int ignorethis); // Not sure if there is any other way of doing it, but this will handle major enemy
	~enemy();

};

