#include "enemy.h"

/*
	reference to what actors private variables are
	images* texture;
	int hitPoints;
	int speed;
*/


enemy::enemy(SDL_Renderer* r, int i)
{

	texture = new images("images/MinorEnemy.png", r, 100, 100, 300, 300,1); // use vector[i].texture->show(); probably. would do random positions but can't account for other ships spawning in same spot and then overlapping, which would cause problems
	hitPoints = 3;
	speed = 4;

}

enemy::enemy(SDL_Renderer* r, int i, int j)
{
	texture = new images("images/MajorEnemy.png", r, 100, 100, 300, 300,1);
	hitPoints = 6;
	speed = 6;

}

enemy::~enemy()
{

}
