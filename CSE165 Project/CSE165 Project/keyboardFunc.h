#pragma once
#include "images.h"
#include "player.h"

class keyboardFunc
{

	void input(player*);

public:

	bool w;
	bool a;
	bool s;
	bool d;
	bool space;
	bool click;

	keyboardFunc();
	~keyboardFunc();
	friend class renderer;

};

