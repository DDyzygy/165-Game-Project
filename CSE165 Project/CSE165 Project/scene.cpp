#include "scene.h"


// Not a great way to handle this i think, but should be fine for a project

scene::scene()
{}

scene::scene(SDL_Renderer* r) // Scene 1/Level 1
{
	enemy* e1 = new enemy(r, 0);
	enemy* e2 = new enemy(r, 0);
	enemy* e3 = new enemy(r, 0);
	enemy* e4 = new enemy(r, 0);
	enemy* e5 = new enemy(r, 0);
	enemy* e6 = new enemy(r, 0, 1);

	actorList.push_back(e1);
	actorList.push_back(e2);
	actorList.push_back(e3);
	actorList.push_back(e4);
	actorList.push_back(e5);
	actorList.push_back(e6);

}

scene::scene(SDL_Renderer* r, int i) // Scene 2/Level 2
{



}

scene::scene(SDL_Renderer* r, int i, int j) // Scene 2/Level 2
{



}
