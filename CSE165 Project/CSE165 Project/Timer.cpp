#include "Timer.h"

Timer::Timer() {
	timeStart = SDL_GetTicks(); //sets the current time at creation (never zero)
}

void Timer::Count() {
	timeCurrent = SDL_GetTicks(); //adds to the updated time
}

float Timer::getTime() {
	return (timeCurrent - timeStart) / 1000; //gets the time elapsed by subtracting current time by starting time (divides by 1000 to turn to milliseconds to seconds)
}

void Timer::resetTimer() {
	timeStart = SDL_GetTicks(); //resets timer by setting the tick to the current time making the time elapsed reset at zero
}

Timer::~Timer() {

}