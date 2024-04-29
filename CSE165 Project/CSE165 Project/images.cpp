#include "images.h"
#include <vector>

	
images::images(std::string _jpg, SDL_Renderer* _renderer, int _sizeX, int _sizeY, int _posX, int _posY, int _layer) {
	renderer = _renderer;
	sizeX = _sizeX;
	sizeY = _sizeY;
	posX = _posX;
	posY = _posY;
	layer = _layer;
	area = { posX - sizeX / 2, posY - sizeY / 2, sizeX, sizeY }; //sets the area of the rectangle based on size and position

	SDL_Surface* jpg = IMG_Load(_jpg.c_str()); //uses the name of the image to get a SDL_Surface of said image

	if (!jpg)
	{
		std::cout << "Image Failed: " << std::endl;

	}

	texture = SDL_CreateTextureFromSurface(renderer, jpg); //uses the SDL_Surface and the renderer to create an SDL_texture of the image
	
	if (!texture)
	{
		std::cout << "Texture failed: " << std::endl;

	}

	SDL_FreeSurface(jpg); //destroys the unneeded image after it has been rendered to the texture
}

images::images(images& i)
{
	renderer = i.renderer;
	sizeX = i.sizeX;
	sizeY = i.sizeY;
	posX = i.posX;
	posY = i.posY;
	layer = i.layer;
	area = i.area;
}

void images::show(){
	area = { posX - sizeX / 2, posY - sizeY / 2, sizeX, sizeY }; //updates area of rectangle based on current size and position
	SDL_RenderCopy(renderer, texture, NULL, &area); //renders the area of the rectangle with the current texture in it
}

images::~images() {
	SDL_DestroyTexture(texture); //removes the texture on deletion
}



