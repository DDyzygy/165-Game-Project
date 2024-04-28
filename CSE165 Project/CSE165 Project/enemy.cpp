#include "enemy.h"

/*
	reference to what actors private variables are
	images* texture;
	int hitPoints;
	int speed;
*/


enemy::enemy(SDL_Renderer* r, int x, int y)
{

	texture = new images("images/MinorEnemy.png", r, 90, 68, x, y, 1); // use vector[i].texture->show(); probably. would do random positions but can't account for other ships spawning in same spot and then overlapping, which would cause problems
	hitPoints = 3;
	speed = 1;

}

enemy::enemy(SDL_Renderer* r, int x, int y, int ignorethis)
{
	texture = new images("images/MajorEnemy.png", r, 96, 84, x, y, 1);
	hitPoints = 6;
	speed = 1;

}

enemy::~enemy()
{
	SDL_DestroyTexture(texture->texture);
}
