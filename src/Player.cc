#include "Player.hh"

Player::Player() : 
	GameObject(std::make_unique<sf::RectangleShape>(sf::Vector2f(20, 20))) { }

void Player::update() {

}

bool Player::shouldDelete() const {
	return false;
}
