#pragma once
#include "images.h"

class actor
{


protected:

	//images* texture;
	int hitPoints;
	int speed;

public:
	bool shooting;
	images* texture;

	actor();
	actor(SDL_Renderer*);
	virtual ~actor();

	void checkState();


};

