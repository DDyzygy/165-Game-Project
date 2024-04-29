#include "actor.h"
#include <cstdlib>
#include <time.h>

actor::actor() // This won't do anything, just here for enemy and player classes
{}

actor::actor(SDL_Renderer* r)
{

	texture = new images("images/SpaceRock.png", r, 100, 100, 500, 450,1);
	speed = 0;
	shooting = false;
	shown = false;
}

actor::~actor()
{

}

int actor::getPoints()
{
	return points;
}

bool actor::checkState() // return true if alive, false if dead
{

	if (hitPoints <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void actor::updateHitPoints()
{
	hitPoints -= 1;
}

void actor::setHitPoints()
{
	hitPoints = 0;
}

void actor::movement(int randomizer)
{
	srand(time(0) * randomizer);
	//srand(time(0));
	texture->posY += speed;
	if (texture->posX >= 20)
	{
		texture->posX -= rand() * (randomizer + 1) % 3 + 1;
	}
	if (texture->posX <= 780) 
	{
		texture->posX += rand() * (randomizer + 1) % 3 + 1;
	}
}

void actor::shoot()
{
	srand(time(0));
	shooting = rand() % 1;
}

void actor::setShown()
{
	shown = true;
}

bool actor::getShown()
{
	return shown;
}

float actor::getTime() {
	return currentCooldown.getTime();
}

float actor::getCooldown() {
	return cooldown;
}


void actor::resetTimer() {
	currentCooldown.resetTimer();
}