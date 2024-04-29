#pragma once
#include "images.h"
#include "Timer.h"

class actor
{


protected:

	//images* texture;
	int hitPoints;
	int points;
	double speed;
	bool shown;
	Timer currentCooldown;
	double cooldown;

public:
	bool shooting;
	images* texture;

	actor();
	actor(SDL_Renderer*);
	virtual ~actor();

	int getPoints();
	bool checkState();
	void updateHitPoints();
	void setHitPoints();
	void movement(int randomizer);
	void shoot();
	void setShown();
	bool getShown();
	float getTime();
	float getCooldown();
	void resetTimer();

};

