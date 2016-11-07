#include "Platform.hh"

Platform::Platform(int x, int y, int width) :
	GameObject(), sf::RectangleShape(sf::Vector2f(width, 10)) {
	this->setPosition(x, y);
}

void Platform::update() {
}

bool Platform::shouldDelete() const {
	return false;
}

const sf::Drawable* Platform::asDrawable() const {
	return (sf::RectangleShape*)(this);
}
