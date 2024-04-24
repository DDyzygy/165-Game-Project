#pragma once
#include <iostream>

class actor
{
	int hitPoints = 2;
	float moveSpeed = .2f;
	float attackDelay;
	float actorSize = 0.2f; // This will determine the size of the triangles that make up the square we will texture, default will be .3

public:

	actor();
	//Function to generate spawn positions and draw actor
	void drawActor();

};

