#include "scene.h"


// Not a great way to handle this i think, but should be fine for a project

scene::scene()
{}

scene::scene(SDL_Renderer* r) // Scene 1/Level 1
{
	timeDelay = 2;

	enemy* e1 = new enemy(r, 300, -50, 2.5);
	enemy* e2 = new enemy(r, 400, -50, 2.5);
	enemy* e3 = new enemy(r, 500, -50, 2.5);
	enemy* e4 = new enemy(r, 250, -50, 2.5);
	enemy* e5 = new enemy(r, 450, -50, 2.5);
	enemy* e6 = new enemy(r, 300, -100, 2.5, 0);

	actorList.push_back(e1);
	actorList.push_back(e2);
	actorList.push_back(e3);
	actorList.push_back(e4);
	actorList.push_back(e5);
	actorList.push_back(e6);

}

scene::scene(SDL_Renderer* r, int i) // Scene 2/Level 2
{
	enemy* e1 = new enemy(r, 100, -50, 2.5);
	enemy* e2 = new enemy(r, 200, -50, 2.5);
	enemy* e3 = new enemy(r, 400, -50, 2.5);
	enemy* e4 = new enemy(r, 400, -100, 2.5, 0);
	enemy* e5 = new enemy(r, 500, -100, 2.5, 0);
	enemy* e6 = new enemy(r, 300, -100, 2.5, 0);

	actorList.push_back(e1);
	actorList.push_back(e2);
	actorList.push_back(e3);
	actorList.push_back(e4);
	actorList.push_back(e5);
	actorList.push_back(e6);

}

scene::scene(SDL_Renderer* r, int i, int j) // Scene 3/Level 3
{
	enemy* e1 = new enemy(r, 400, -50, 2.5);
	enemy* e2 = new enemy(r, 550, -150, 2.5, 0);
	enemy* e3 = new enemy(r, 250, -150, 2.5, 0);
	enemy* e4 = new enemy(r, 200, -100, 2.5, 0);
	enemy* e5 = new enemy(r, 400, -100, 2.5, 0);
	enemy* e6 = new enemy(r, 600, -100, 2.5, 0);

	actorList.push_back(e1);
	actorList.push_back(e2);
	actorList.push_back(e3);
	actorList.push_back(e4);
	actorList.push_back(e5);
	actorList.push_back(e6);

}
