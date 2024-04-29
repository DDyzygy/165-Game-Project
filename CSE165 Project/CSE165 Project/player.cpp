#include "player.h"

player::player(SDL_Renderer* r)
{

	texture = new images("images/PlayerShip1.png", r, 100, 100, 400, 650, 1);
	hitPoints = 3;
	speed = 6;
	cooldown = 0.3;
	points = 0;

}

player::~player()
{

}

void player::setPoints(int amount)
{
	points += amount;
}

int player::getSpeed()
{
	return speed;
}

int player::getHealth()
{
	return hitPoints;
}