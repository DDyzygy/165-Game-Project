#include "player.h"

player::player(SDL_Renderer* r)
{

	texture = new images("images/PlayerShip1.png", r, 100, 100, 400, 650, 1);
	hitPoints = 3;
	speed = 8;


}

player::~player()
{

}

int player::getSpeed()
{
	return speed;
}