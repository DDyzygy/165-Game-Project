#pragma once
#include "actor.h"

class enemy : public actor
{

public:

	enemy(SDL_Renderer*, int i); // Handles minor enemy
	enemy(SDL_Renderer*, int i, int j); // Not sure if there is any other way of doing it, but this will handle major enemy
	~enemy();



};

