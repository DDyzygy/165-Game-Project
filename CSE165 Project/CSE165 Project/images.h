#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class images
{
public:

	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int sizeX, sizeY, posX, posY;

	images(std::string _jpg, SDL_Renderer* _renderer, int _sizeX, int _sizeY, int _posX, int _posY);

	void show();

	~images();

};