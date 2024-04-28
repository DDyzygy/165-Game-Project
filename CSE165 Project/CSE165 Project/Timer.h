#pragma once
#include <SDL.h>



class Timer
{
	float timeStart;
	float timeCurrent;

public:
	Timer();

	float getTime();

	void Count();

	void resetTimer();

	~Timer();

};
