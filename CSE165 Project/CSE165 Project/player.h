#pragma once
#include "actor.h"
class player : public actor
{
	Timer shootCooldown;


public:

	player(SDL_Renderer*);
	virtual ~player();

	int getSpeed();

};

