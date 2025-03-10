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

	bullet(actor* ship, std::string bulletImage, SDL_Renderer* r, int _speed, int _side);

	bool hit(actor* ship, int _side);

	void movement();

	~bullet();

};