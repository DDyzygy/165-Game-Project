#pragma once
#include "actor.h"

class enemy : public actor
{

public:

	enemy(SDL_Renderer*, int x, int y, double _cooldown); // Handles minor enemy
	enemy(SDL_Renderer*, int x, int y, double _cooldown, int ignorethis); // Not sure if there is any other way of doing it, but this will handle major enemy, could have just did 2 other classes from this
	void isShooting();
	~enemy();

};

