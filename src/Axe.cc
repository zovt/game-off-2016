#include "Axe.hh"

Axe::Axe(int x, int y) :
	GameObject(), sf::CircleShape(10) {
	this->setPosition(x, y);
}

void Axe::update() {
}

bool Axe::shouldDelete() const {
	return false;
}

const sf::Drawable* Axe::asDrawable() const {
	return (sf::CircleShape*)(this);
}
