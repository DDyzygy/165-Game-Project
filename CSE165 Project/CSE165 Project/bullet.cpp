#include "bullet.h"


bullet::bullet(actor* ship, SDL_Renderer* r, int _speed, int _side) {
	speed = _speed;
	side = _side;
	texture = new images("images/bullet.png", r, 10, 30, ship->texture->posX, ship->texture->posY + side*ship->texture->sizeY, 1);

}

void bullet::hit(actor* ship, int _side) {



	if (SDL_HasIntersection(&(ship->texture->area), &(texture->area)) && side != _side) {
		std::cout << "hit" << std::endl;
	}
}

void bullet::movement() {
	texture->posY += speed * side;
}

bullet::~bullet() {

}

