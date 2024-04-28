#include "keyboardFunc.h"
#include <SDL.h>
#include <iostream>


keyboardFunc::keyboardFunc()
{
	w = false;
	a = false;
	s = false;
	d = false;
	space = false;
}

keyboardFunc::~keyboardFunc()
{

}

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
				w = true;
				//std::cout << "pressing w" << std::endl; // move forwards
				//ship->texture->posY -= ship->getSpeed();

			}
			if (SDLK_a == event.key.keysym.sym && ship->texture->posX > 40)
			{
				a = true;
				//std::cout << "pressing a" << std::endl; // move left
				//ship->texture->posX -= ship->getSpeed();
			}

			if (SDLK_s == event.key.keysym.sym && ship->texture->posY < 740)
			{
				s = true;
				//std::cout << "pressing s" << std::endl; // move back
				//ship->texture->posY += ship->getSpeed();
			}
			if (SDLK_d == event.key.keysym.sym && ship->texture->posX < 760)
			{
				d = true;
				//std::cout << "pressing d" << std::endl; // move right
				//ship->texture->posX += ship->getSpeed();
			}
			if (SDLK_SPACE == event.key.keysym.sym)
			{
				space = true;

				//ship->shooting = true;
				//std::cout << "pressing spacebar" << std::endl; // shoot
			}
			if (SDLK_ESCAPE == event.key.keysym.sym)
			{
				exit(0); // esc to exit game
			}
			break;

		case SDL_KEYUP:
			if (SDLK_w == event.key.keysym.sym)
			{
				w = false;
				//std::cout << "released w" << std::endl; // stop moving forwards
			}
			if (SDLK_a == event.key.keysym.sym)
			{
				a = false;
				//std::cout << "released a" << std::endl; // stop moving left
			}
			if (SDLK_s == event.key.keysym.sym)
			{
				s = false;
				//std::cout << "released s" << std::endl; // stop moving back
			}
			if (SDLK_d == event.key.keysym.sym)
			{
				d = false;
				//std::cout << "released d" << std::endl; // stop moving right
			}
			if (SDLK_SPACE == event.key.keysym.sym)
			{
				space = false;
				//std::cout << "released spacebar" << std::endl; // stop shoot
			}
			break;
		
		case SDL_QUIT:
			exit(0);
			break;

		default:
			break;
		}

		if (w)
		{
			if (a || d)
			{
				ship->texture->posY -= ship->getSpeed()/1.5;
			}
			else
			{
				ship->texture->posY -= ship->getSpeed();
			}
			
		}
		if (a)
		{
			if (w || s)
			{
				ship->texture->posX -= ship->getSpeed()/1.5;
			}
			else
			{
				ship->texture->posX -= ship->getSpeed();
			}
			
		}
		if (s)
		{
			if (a || d)
			{
				ship->texture->posY += ship->getSpeed()/1.5;
			}
			else
			{
				ship->texture->posY += ship->getSpeed();
			}
			
		}
		if (d)
		{
			if (w || s)
			{
				ship->texture->posX += ship->getSpeed()/1.5;
			}
			else
			{
				ship->texture->posX += ship->getSpeed();
			}
			
		}
		if (space)
		{
			ship->shooting = true;
		}
		else
		{
			
		}
	}
}