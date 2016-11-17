#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

#include "gameobjects.hh"

Position::Position(const float x, const float y) : x(x), y(y) { }

sf::Vector2f positionToVec2f(const Position &position) {
	return sf::Vector2f(position.x, position.y);
}

Box::Box(const float width, const float height) : width(width), height(height) { }

sf::Vector2f boxToVec2f(const Box &box) {
	return sf::Vector2f(box.width, box.height);
}

Collider::Collider(Position &position, Box &box) 
	: position(position), box(box) { }

void updateDefault(GameObject &obj) {
	return;
}

bool shouldDeleteDefault(GameObject &obj) {
	return false;
}

std::unique_ptr<sf::Drawable> drawDefault(const GameObject &obj) {
	return std::make_unique<sf::RectangleShape>(sf::Vector2f(0, 0));
}

int currentID = 0;
GameObject::GameObject(Position position, Box size)
	: id(currentID), position(position), size(size), collider(position, size) { 
		currentID += 1;
		this->draw = &drawDefault;
		this->update = &updateDefault;
		this->shouldDelete = &shouldDeleteDefault;
	}


void moveTo(GameObject &gameObject, const float x, const float y) {
	gameObject.position.x = x;
	gameObject.position.y = y;
}

void moveD(GameObject &gameObject, const float xOffset, const float yOffset) {
	gameObject.position.x += xOffset;
	gameObject.position.y += yOffset;
}

const std::unique_ptr<sf::Drawable> drawPlayer(const Position &position, const Box &size) {
	auto rect = std::make_unique<sf::RectangleShape>(boxToVec2f(size));
	rect->setPosition(positionToVec2f(position));
	rect->setFillColor(sf::Color::Green);
	return rect;
}

void updatePlayer(GameObject &player) {
	moveD(player, 0.0001, 0.0001);
}

GameObject makePlayer(const Position &position) {
	GameObject player(position, Box(24, 24));
	player.update = updatePlayer;
	player.draw = drawPlayer;
}

GameObject 
