#include "bullet.h"


bullet::bullet(actor* ship, std::string bulletImage, SDL_Renderer* r, int _speed, int _side) {
	speed = _speed;
	side = _side;
	texture = new images(bulletImage, r, 14, 31, ship->texture->posX, ship->texture->posY + side*ship->texture->sizeY - 50*side, 3); //sets the bullets starting point in front of ship firing

}


bool bullet::hit(actor* ship, int _side) {

	if (SDL_HasIntersection(&(ship->texture->area), &(texture->area)) && side != _side) { //checks if the area of the bullet is intersecting with any ships and if they are on the same side (no friendly fire!)
		return true;
	}
	return false;
}

void bullet::movement() {
	texture->posY += speed * side; //moves the bullet depending on what side it is on and how fast you want it to move
}

bullet::~bullet() {

}

