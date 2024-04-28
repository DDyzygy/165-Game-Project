#pragma once
#include "actor.h"
class player : public actor
{



public:

	player(SDL_Renderer*);
	virtual ~player();

	int getSpeed();

};

