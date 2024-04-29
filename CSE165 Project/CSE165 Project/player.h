#pragma once
#include "actor.h"
class player : public actor
{
	Timer shootCooldown;

public:

	player(SDL_Renderer*);
	virtual ~player();

	void setPoints(int amount);
	
	int getSpeed();
	int getHealth();

};

