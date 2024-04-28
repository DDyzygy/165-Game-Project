#include "keyboardFunc.h"
#include <SDL.h>
#include <iostream>

void keyboardFunc::input(player* ship) // Change images* to player* and then handle it with player.images.posX/Y
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:

			if (SDLK_w == event.key.keysym.sym && ship->texture->posY > 100)
			{
				std::cout << "pressing w" << std::endl; // move forwards
				ship->texture->posY -= ship->getSpeed();

			}
			if (SDLK_a == event.key.keysym.sym && ship->texture->posX > 40)
			{
				std::cout << "pressing a" << std::endl; // move left
				ship->texture->posX -= ship->getSpeed();
			}
			if (SDLK_s == event.key.keysym.sym && ship->texture->posY < 740)
			{
				std::cout << "pressing s" << std::endl; // move back
				ship->texture->posY += ship->getSpeed();
			}
			if (SDLK_d == event.key.keysym.sym && ship->texture->posX < 760)
			{
				std::cout << "pressing d" << std::endl; // move right
				ship->texture->posX += ship->getSpeed();

			}
			if (SDLK_SPACE == event.key.keysym.sym) 
			{
				ship->shooting = true;
				std::cout << "pressing spacebar" << std::endl; // shoot
			}
			if (SDLK_ESCAPE == event.key.keysym.sym)
			{
				exit(0); // esc to exit game
			}
			break;

		case SDL_KEYUP:
			if (SDLK_w == event.key.keysym.sym )
			{
				std::cout << "released w" << std::endl; // stop moving forwards
			}
			if (SDLK_a == event.key.keysym.sym)
			{
				std::cout << "released a" << std::endl; // stop moving left
			}
			if (SDLK_s == event.key.keysym.sym)
			{
				std::cout << "released s" << std::endl; // stop moving back
			}
			if (SDLK_SPACE == event.key.keysym.sym)
			{
				std::cout << "released spacebar" << std::endl; // stop shoot
			}
			break;

		case SDL_QUIT:
			exit(0);
			break;

		default:
			break;
		}
	}
}