#include "Player.hh"

Player::Player(int x, int y) : 
	sf::RectangleShape(sf::Vector2f(20, 20)), GameObject() {
		this->setPosition(x, y);
	}

void Player::update() {
}

bool Player::shouldDelete() const {
	return false;
}

const sf::Drawable* Player::asDrawable() const {
	return (sf::RectangleShape*)(this);
}
