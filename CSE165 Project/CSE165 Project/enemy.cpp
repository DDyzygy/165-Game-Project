#include "enemy.h"

/*
	reference to what actors private variables are
	images* texture;
	int hitPoints;
	int speed;
*/


enemy::enemy(SDL_Renderer* r, int x, int y, double _cooldown)
{

	texture = new images("images/MinorEnemy.png", r, 90, 68, x, y, 1); // use vector[i].texture->show(); probably. would do random positions but can't account for other ships spawning in same spot and then overlapping, which would cause problems
	cooldown = _cooldown;
	hitPoints = 3;
	speed = 1;
	points = 10;
}

enemy::enemy(SDL_Renderer* r, int x, int y, double _cooldown, int ignorethis)
{
	texture = new images("images/MajorEnemy.png", r, 96, 84, x, y, 1);
	cooldown = _cooldown;
	hitPoints = 6;
	speed = 1;
	points = 20;
}

void enemy::isShooting() {
	if (currentCooldown.getTime() >= cooldown) {
		shooting = true;
	}
}

enemy::~enemy()
{
	SDL_DestroyTexture(texture->texture);
}
