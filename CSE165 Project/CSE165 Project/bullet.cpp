#include "bullet.h"


bullet::bullet(actor* ship, SDL_Renderer* r, int _speed, int _side) {
	speed = _speed;
	side = _side;
	texture = new images("images/PlayerBullet.png", r, 14, 31, ship->texture->posX, ship->texture->posY + side*ship->texture->sizeY - 50*side, 3); //sets the bullets starting point in front of ship firing

}

bullet::bullet(actor* eship, SDL_Renderer* r, int _speed, int _side, int ignore) {
	speed = _speed;
	side = _side;
	texture = new images("images/EnemyBullet.png", r, 14, 31, eship->texture->posX, eship->texture->posY + side * eship->texture->sizeY - 50 * side, 3); //sets the bullets starting point in front of ship firing

}

bool bullet::hit(actor* ship, int _side) {

	if (SDL_HasIntersection(&(ship->texture->area), &(texture->area)) && side != _side) { //checks if the area of the bullet is intersecting with any ships and if they are on the same side (no friendly fire!)
		std::cout << "balls" << std::endl;
		return true;
	}
	return false;
}

void bullet::movement() {
	texture->posY += speed * side; //moves the bullet depending on what side it is on and how fast you want it to move
}

bullet::~bullet() {

}

