#include <SFML/Graphics.hpp>
#include <iostream>

#include "gameobjects.hh"

Position::Position(const float x, const float y) : x(x), y(y) { }

sf::Vector2f positionToVec2f(const Position &position) {
	return sf::Vector2f(position.x, position.y);
}

Box::Box(const float width, const float height) : width(width), height(height) { }

Position centerInside(const Box &outer, const Box &inner) {
	return Position(outer.width / 2 - inner.width / 2,
			outer.height / 2 - inner.height / 2);
}

sf::Vector2f boxToVec2f(const Box &box) {
	return sf::Vector2f(box.width, box.height);
}

void defaultCollisionHandler(const GameObject &collided, const GameObject &other) { 
	std::cout << "GameObject " << collided.id << " of type '" 
		<< gotString(collided.type) << "' collided with GameObject " << other.id 
		<< " of type '" << gotString(other.type) << "'" << std::endl;
}

Collider::Collider(Position &position, Box &box) 
	: position(position), box(box), handler(defaultCollisionHandler) { }

bool checkCollision(const Collider &col1, const Collider &col2) {
	std::cout << "Col1" << std::endl;
	std::cout << col1.position.x << "," << col1.position.y << std::endl;
	std::cout << col1.box.width << "," << col1.box.height << std::endl;

	std::cout << "Col2" << std::endl;
	std::cout << col2.position.x << "," << col2.position.y << std::endl;
	std::cout << col2.box.width << "," << col2.box.height << std::endl;
	if (col1.position.y + col1.box.height < col2.position.y
			|| col1.position.x + col1.box.width < col2.position.x
			|| col2.position.y + col2.box.height < col1.position.y
			|| col2.position.x + col2.box.width < col1.position.x) {
		return false;
	}

	return true;
}

const std::string gotStrings[] = { "Player", "Platform", "Axe", "Axe Spawner" };
std::string gotString(GameObjectType got) {
	return gotStrings[got];
}


void updateDefault(GameObject &obj) {
	return;
}

bool shouldDeleteDefault(const GameObject &obj) {
	return false;
}

std::unique_ptr<sf::Drawable> drawDefault(const GameObject &obj) {
	return std::make_unique<sf::RectangleShape>(sf::Vector2f(0, 0));
}

int currentID = 0;
GameObject::GameObject(Position position, Box size, GameObjectType type)
	: id(currentID), type(type), position(position), size(size),
	collider(position, size) { 
		currentID += 1;
		this->draw = &drawDefault;
		this->update = &updateDefault;
		this->shouldDelete = &shouldDeleteDefault;
	}

void moveToPosition(GameObject &gameObject, const Position position) {
	gameObject.position = position;
	gameObject.collider.position = position;
}

void moveTo(GameObject &gameObject, const float x, const float y) {
	gameObject.position.x = x;
	gameObject.position.y = y;
	gameObject.collider.position.x = x;
	gameObject.collider.position.y = y;
}

void moveD(GameObject &gameObject, const float xOffset, const float yOffset) {
	gameObject.position.x += xOffset;
	gameObject.position.y += yOffset;
	gameObject.collider.position.x += xOffset;
	gameObject.collider.position.y += yOffset;
}

std::unique_ptr<sf::Drawable> drawPlayer(const GameObject &obj) {
	auto rect = std::make_unique<sf::RectangleShape>(boxToVec2f(obj.size));
	rect->setPosition(positionToVec2f(obj.position));
	rect->setFillColor(sf::Color::Green);
	return rect;
}

void updatePlayer(GameObject &player) {
}

const Box PLAYER_SIZE(24, 24);
GameObject makePlayer(const Position &position) {
	GameObject player(position, PLAYER_SIZE, GameObjectType::PLAYER);
	player.update = updatePlayer;
	player.draw = drawPlayer;
	return player;
}

std::unique_ptr<sf::Drawable> drawPlatform(const GameObject &obj) {
	return drawPlayer(obj);
}

GameObject makePlatform(const Position &position) {
	GameObject platform(position, Box(300, 10), GameObjectType::PLATFORM);
	platform.draw = drawPlatform;
	return platform;
}
