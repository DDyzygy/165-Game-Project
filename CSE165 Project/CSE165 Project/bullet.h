#pragma once
#include <SDL.h>
#include <vector>
#include <algorithm>
#include "scene.h"
#include "images.h"
#include "actor.h"



class bullet
{
public:

	images* texture;
	int side; //player = -1, enemy = 1
	int speed;

	bullet(actor* ship, SDL_Renderer* r, int _speed, int _side);

	void hit(actor* ship, int _side);

	void movement();

	~bullet();

};