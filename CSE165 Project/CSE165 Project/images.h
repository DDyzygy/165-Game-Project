#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class images
{
public:

	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect area;
	int sizeX, sizeY, posX, posY, layer;

	images(std::string _jpg, SDL_Renderer* _renderer, int _sizeX, int _sizeY, int _posX, int _posY, int layer);

	void show();

	~images();

};