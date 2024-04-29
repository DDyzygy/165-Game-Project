#include "renderer.h"
#include <SDL.h>

renderer::renderer()
{
	windowWidth = 800;
	windowHeight = 800;
	windowflags = SDL_WINDOW_OPENGL;
	rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

	// NOTE: 400, 400 is the center of the window
	// 0, 0 is the top left 
	// the larger Y is, the further down it goes
	// the larger X is, the further right it goes
}

renderer::~renderer()
{
	SDL_DestroyWindow(SDL_GameWindow);
}

SDL_Renderer* renderer::getRenderer()
{
	return rndrer;
}

SDL_Window* renderer::getWindow()
{
	return SDL_GameWindow;
}


void renderer::render_start()
{
	SDL_GameWindow = SDL_CreateWindow("Game Name", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, windowflags);
	rndrer = SDL_CreateRenderer(SDL_GameWindow, -1, rendererFlags); // (Window, -1 is the first rendering driver to support flags, 0 or flags | together)
}

void renderer::backgroundMove(std::vector<images*> background, int speed) {
	for (int i = 0; i < 2; i++) {
		if (background[i]->posY >= 1600) 
		{
			background[i]->posY = -1200;
		}
		background[i]->posY += speed;
	}
}

void renderer::shooting(std::vector<scene*> &scenes, player* &playerShip, std::vector<bullet*> &bullets) {

	if (playerShip->shooting == true && playerShip->getTime() >= playerShip->getCooldown()) {
		bullets.emplace_back(new bullet(playerShip, "images/bullet.png", rndrer, 6, -1));
		playerShip->resetTimer();
		playerShip->shooting = false;
	}
	for (int i = 0; i < scenes[0]->actorList.size(); i++) {

		if (scenes[0]->actorList[i]->getTime() >= scenes[0]->actorList[i]->getCooldown()) {
			bullets.emplace_back(new bullet(scenes[0]->actorList[i], "images/EnemyBullet.png", rndrer, 6, 1));
			scenes[0]->actorList[i]->resetTimer();
			scenes[0]->actorList[i]->shooting = false;
		}

		if (SDL_HasIntersection(&(playerShip->texture->area), &(scenes[0]->actorList[i]->texture->area))) { //checks if the area of the bullet is intersecting with any ships and if they are on the same side (no friendly fire!)
			std::cout << "nuts" << std::endl;
		}


	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->movement();
	}

	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->hit(playerShip, -1)) {
			auto temp = bullets.begin() + i;
			delete* temp;
			bullets.erase(temp);
			//lower players health here
			playerShip->updateHitPoints();
			
			continue;
		}

		if (bullets[i]->texture->posY > 800 || bullets[i]->texture->posY < 0) {
			auto temp = bullets.begin() + i;
			delete* temp;
			bullets.erase(temp);
			continue;
		}


		for (int j = 0; j < scenes[0]->actorList.size(); j++) { // REMEMBER TO ChANGE SCENES[0] TO whatever we use later
			if (bullets[i]->hit(scenes[0]->actorList[j], 1)) {
				auto temp = bullets.begin() + i;
				delete* temp;
				bullets.erase(temp); 
				//lower actor j's health here
				scenes[0]->actorList[j]->updateHitPoints();
				if (!scenes[0]->actorList[j]->checkState())
				{
					scenes[0]->actorList.erase(scenes[0]->actorList.begin() + j);
				}
				break;
			}
		}
	}
}


bool renderer::buttonPress(images* button) {
	
	SDL_Point mouse;

	//SDL_PumpEvents();  // make sure we have the latest mouse state.

	SDL_GetMouseState(&mouse.x, &mouse.y);

	const SDL_Point *currentPos = &mouse;
	const SDL_Rect *buttonRect = &button->area;

	if (SDL_PointInRect(currentPos, buttonRect)) {

		return true;
	}

	return false;
	
	
}


void renderer::render_loop(keyboardFunc action, player* playerShip, std::vector<scene*> scenes, std::vector<images*> textures)
{

	std::vector<bullet*> bullets;

	int currentScene = 1;

	while (1)
	{	

		SDL_SetRenderDrawColor(rndrer, 28, 9, 41, 212); // Set window background color
		SDL_RenderClear(rndrer);
		//background.show();
		//second.show();

		switch (currentScene) {
			case 1:
				backgroundMove(textures, 1);
				
				for (int i = 0; i < 2; i++)
				{
					textures[i]->show();
				}
				textures[5]->show();
				action.input(playerShip);

				if (buttonPress(textures[5])) {
					std::cout << "balls" << std::endl;
					currentScene = 2;
				}

				break;

			case 2:
				backgroundMove(textures, 3);

				for (int i = 0; i < 5; i++)
				{
					textures[i]->show();
				}

				shooting(scenes, playerShip, bullets);

				for (int j = 0; j < scenes[0]->actorList.size(); j++)
				{
					if (!scenes[0]->actorList[j]->getShown())
					{
						scenes[0]->actorList[j]->texture->show();
						scenes[0]->actorList[j]->setShown();
					}
					else
					{
						// use this with movement later so unshown enemies will stay in their spawn positions
						scenes[0]->actorList[j]->texture->show();
						scenes[0]->actorList[j]->shoot();
						scenes[0]->actorList[j]->movement();
					}

				}

				for (int i = 0; i < bullets.size(); i++) {
					bullets[i]->texture->show();
				}

				playerShip->texture->show();

				action.input(playerShip);


				break;

		}



		
		//======================================
		// Replace this with keyboardFunc somehow 
		//maybe load a scene class into the render loop?

		//======================================
		SDL_RenderPresent(rndrer);
		SDL_Delay(12);
	}
}