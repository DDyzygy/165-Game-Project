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

void actor::movement()
{
	srand(time(0));
	texture->posY += speed;
	texture->posX += rand() % 3 + 1;
	texture->posX -= rand() % 3 + 1;
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