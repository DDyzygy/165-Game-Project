#include "keyboardFunc.h"
#include <SDL.h>
#include <iostream>
#include "images.h"

void keyboardFunc::input(images* player) // Change images* to player* and then handle it with player.images.posX/Y
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:

			if (SDLK_w == event.key.keysym.sym && player->posY > 100)
			{
				std::cout << "pressing w" << std::endl; // move forwards
				player->posY -= 8;

			}
			if (SDLK_a == event.key.keysym.sym && player->posX > 40)
			{
				std::cout << "pressing a" << std::endl; // move left
				player->posX -= 8;
			}
			if (SDLK_s == event.key.keysym.sym && player->posY < 740)
			{
				std::cout << "pressing s" << std::endl; // move back
				player->posY += 8;
			}
			if (SDLK_d == event.key.keysym.sym && player->posX < 760)
			{
				std::cout << "pressing d" << std::endl; // move right
				player->posX += 8;

			}
			if (SDLK_SPACE == event.key.keysym.sym) 
			{
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