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

void renderer::shooting(std::vector<scene*> &scenes, player* &playerShip, std::vector<bullet*> &bullets, int currentLevel) { //maybe pass in level currently on

	if (playerShip->shooting == true && playerShip->getTime() >= playerShip->getCooldown()) {
		bullets.emplace_back(new bullet(playerShip, "images/PlayerBullet.png", rndrer, 6, -1));
		playerShip->resetTimer();
		playerShip->shooting = false;
	}
	for (int i = 0; i < scenes[currentLevel]->actorList.size(); i++) {

		if (scenes[currentLevel]->actorList[i]->getTime() >= scenes[currentLevel]->actorList[i]->getCooldown()) {
			bullets.emplace_back(new bullet(scenes[currentLevel]->actorList[i], "images/EnemyBullet.png", rndrer, 3, 1));
			scenes[currentLevel]->actorList[i]->resetTimer();
			scenes[currentLevel]->actorList[i]->shooting = false;
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


		for (int j = 0; j < scenes[currentLevel]->actorList.size(); j++) { // REMEMBER TO CHANGE scenes[0] TO whatever we use later
			if (bullets[i]->hit(scenes[currentLevel]->actorList[j], 1)) {
				auto temp = bullets.begin() + i;
				delete* temp;
				bullets.erase(temp); 
				//lower actor j's health here
				scenes[currentLevel]->actorList[j]->updateHitPoints();
				if (!scenes[currentLevel]->actorList[j]->checkState())
				{
					scenes[currentLevel]->actorList.erase(scenes[currentLevel]->actorList.begin() + j);
					//playerShip->setPoints(scenes[currentLevel]->actorList[j]->getPoints());
				}
				break;
			}
		}
	}
}

void renderer::updatePoints(player*& playerShip, std::vector<images*> textures)
{
	//block of if statements because i am so good at coding
	// create 10
	if (playerShip->getPoints() == 0)
	{
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 1)
	{
		textures[10]->show();
		textures[9]->posX = 760;
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 2)
	{
		textures[11]->show();
		textures[9]->posX = 760;
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 3)
	{
		textures[12]->show();
		
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 4)
	{
		textures[13]->show();
		
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 5)
	{
		textures[14]->show();
		
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 6)
	{
		textures[15]->show();
		
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 7)
	{
		textures[16]->show();
		
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 8)
	{
		textures[17]->show();
		
		textures[9]->show();
	}
	else if (playerShip->getPoints() / 10 == 9)
	{
		textures[18]->show();
		
		textures[9]->show();
	}
	//textures[10]->show();

	//textures[9]->show();

}

bool renderer::buttonPress(images* button) {

	SDL_Point mouse;

	//SDL_PumpEvents();  // make sure we have the latest mouse state.

	SDL_GetMouseState(&mouse.x, &mouse.y);

	const SDL_Point* currentPos = &mouse;
	const SDL_Rect* buttonRect = &button->area;

	if (SDL_PointInRect(currentPos, buttonRect)) {

		return true;
	}

	return false;


}


void renderer::render_loop(keyboardFunc action, player* playerShip, std::vector<scene*> scenes, std::vector<images*> textures)
{

	std::vector<bullet*> bullets;
	
	Timer test;
	Timer levelTime;
	int currentState = 1;
	int currentLevel = 0; //Level starts at 1, index 0;

	while (1)
	{	

		SDL_SetRenderDrawColor(rndrer, 28, 9, 41, 212); // Set window background color
		SDL_RenderClear(rndrer);
		//background.show();

		switch (currentState) {
			case 1:
				for (int i = 0; i < 2; i++) // up to 2 loads background textures
				{
					textures[i]->show();
				}
				textures[19]->show();
				backgroundMove(textures, 1);
				if (buttonPress(textures[19])) {
					currentState = 2;
				}

				break;

			case 2:
				backgroundMove(textures, 3);

				shooting(scenes, playerShip, bullets, currentLevel);

				for (int i = 0; i < 3; i++) // up to 3 loads background textures + the points text
				{
					textures[i]->show();
				}

				if (playerShip->getHealth() == 3)
				{
					textures[3]->show();
					textures[4]->show();
					textures[5]->show();
				}
				else if (playerShip->getHealth() == 2)
				{
					textures[3]->show();
					textures[4]->show();
					textures[8]->show();
				}
				else if (playerShip->getHealth() == 1)
				{
					textures[3]->show();
					textures[7]->show();
					textures[8]->show();
				}
				else if (playerShip->getHealth() > 1)
				{
					textures[6]->show();
					textures[7]->show();
					textures[8]->show();
				}

				//updatePoints(playerShip, textures);

				//std::cout << test.getTime() << std::endl;
				std::cout << playerShip->getPoints() << std::endl;

				if (levelTime.getTime() >= 24 && currentLevel < 2) // change time later to account for enemy spawns being delayed
				{
					currentLevel += 1;
					levelTime.resetTimer();
				}

				if (test.getTime() >= 5) {
					test.resetTimer();
				}






				playerShip->texture->show();
				//Determines what enemies show
				for (int j = 0; j < scenes[currentLevel]->actorList.size(); j++)
				{
					double random = rand() * (j + 1) % 10;
					if (!scenes[currentLevel]->actorList[j]->getShown())
					{
						if (levelTime.getTime() >= 1 && j >= 0 && j <= 2)
						{
							scenes[currentLevel]->actorList[j]->texture->show();
							scenes[currentLevel]->actorList[j]->setShown();
						}
						else if (levelTime.getTime() >= 10 && j >= 3 && j <= 5)
						{
							scenes[currentLevel]->actorList[j]->texture->show();
							scenes[currentLevel]->actorList[j]->setShown();
						}
						//scenes[currentLevel]->actorList[j]->texture->show();
						//scenes[currentLevel]->actorList[j]->setShown();
					}
					else
					{
						// use this with movement later so unshown enemies will stay in their spawn positions
						scenes[currentLevel]->actorList[j]->texture->show();
						scenes[currentLevel]->actorList[j]->shoot();
						scenes[currentLevel]->actorList[j]->movement(random);
						//scenes[currentLevel]->actorList[j]->movement();

					}

				}

				for (int i = 0; i < bullets.size(); i++) {
					bullets[i]->texture->show();
				}
				if (playerShip->getHealth() <= 0) {
					currentState = 3;
				}

				updatePoints(playerShip, textures);


				break;

			case 3:
				for (int i = 0; i < 2; i++) // up to 2 loads background textures
				{
					textures[i]->show();
				}
				textures[20]->show();
				backgroundMove(textures, 1);

				break;

		}

		
		//======================================
		// Replace this with keyboardFunc somehow 
		//maybe load a scene class into the render loop?
		action.input(playerShip);

		//======================================
		SDL_RenderPresent(rndrer);
		SDL_Delay(12);
	}
}