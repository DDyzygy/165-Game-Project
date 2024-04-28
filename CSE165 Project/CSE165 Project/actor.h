#pragma once
#include "images.h"

class actor
{


protected:

	//images* texture;
	int hitPoints;
	double speed;
	bool shown;

public:
	bool shooting;
	images* texture;

	actor();
	actor(SDL_Renderer*);
	virtual ~actor();

	bool checkState();
	void updateHitPoints();
	void movement();
	void shoot();
	void setShown();
	bool getShown();
	

};

