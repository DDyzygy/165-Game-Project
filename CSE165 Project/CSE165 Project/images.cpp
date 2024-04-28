#include "images.h"
#include <vector>

	
images::images(std::string _jpg, SDL_Renderer* _renderer, int _sizeX, int _sizeY, int _posX, int _posY, int _layer) {
	renderer = _renderer;
	sizeX = _sizeX;
	sizeY = _sizeY;
	posX = _posX;
	posY = _posY;
	layer = _layer;
	area = { posX - sizeX / 2, posY - sizeY / 2, sizeX, sizeY };

	SDL_Surface* jpg = IMG_Load(_jpg.c_str());

	if (!jpg)
	{
		std::cout << "Image Failed: " << std::endl;

	}

	texture = SDL_CreateTextureFromSurface(renderer, jpg);
	
	if (!texture)
	{
		std::cout << "Texture failed: " << std::endl;

	}

	SDL_FreeSurface(jpg);
}

void images::show(){
	area = { posX - sizeX / 2, posY - sizeY / 2, sizeX, sizeY };
	SDL_RenderCopy(renderer, texture, NULL, &area);
}

images::~images() {
	SDL_DestroyTexture(texture);
}



