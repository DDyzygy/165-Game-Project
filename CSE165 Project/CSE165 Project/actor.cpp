#include "actor.h"

actor::actor() // This won't do anything, just here for enemy and player classes
{}

actor::actor(SDL_Renderer* r)
{

	texture = new images("images/SpaceRock.png", r, 100, 100, 500, 450,1);
	speed = 0;

}

actor::~actor()
{

}