#include <SFML/Graphics.hpp>
#include <iostream>

#include "gameobjects.hh"

Position::Position(const float x, const float y) : x(x), y(y) { }

Box::Box(const float width, const float height) : width(width), height(height) { }

Collider::Collider(Position &position, Box &box) : position(position), box(box) { }

int currentID = 0;
GameObject::GameObject(Position position, Box size, GameObjectType type)
	: id(currentID), type(type), position(position), size(size),
	collider(Collider(this->position, this->size)) { 
		currentID += 1;
	}

const Box PLAYER_SIZE(24, 24);
Player::Player(const Position &position) 
	: GameObject(position, PLAYER_SIZE, GameObjectType::PLAYER) { }

AxeSpawner::AxeSpawner(const Position &position, int spawnTick) 
	: GameObject(position, Box(0, 0), GameObjectType::AXE_SPAWNER),
	spawnTick(spawnTick) { }

const Box AXE_SIZE = PLAYER_SIZE;
Axe::Axe(const Position &position)
	: GameObject(position, AXE_SIZE, GameObjectType::AXE) { }

GameObject makePlatform(const Position &position) {
	GameObject platform(position, Box(300, 10), GameObjectType::PLATFORM);
	return platform;
}

Position centerInside(const Box &outer, const Box &inner) {
	return Position(outer.width / 2 - inner.width / 2,
			outer.height / 2 - inner.height / 2);
}

sf::Vector2f boxToVec2f(const Box &box) {
	return sf::Vector2f(box.width, box.height);
}

sf::Vector2f positionToVec2f(const Position &position) {
	return sf::Vector2f(position.x, position.y);
}

bool checkCollision(const Collider &col1, const Collider &col2) {
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

void moveToPosition(GameObject &gameObject, const Position position) {
	gameObject.position = position;
}

void moveTo(GameObject &gameObject, const float x, const float y) {
	gameObject.position.x = x;
	gameObject.position.y = y;
}

void moveD(GameObject &gameObject, const float xOffset, const float yOffset) {
	gameObject.position.x += xOffset;
	gameObject.position.y += yOffset;
}

std::unique_ptr<sf::Drawable> drawPlayer(const GameObject &player) {
	auto rect = std::make_unique<sf::RectangleShape>(boxToVec2f(player.size));
	rect->setPosition(positionToVec2f(player.position));
	rect->setFillColor(sf::Color::Green);
	return rect;
}

std::unique_ptr<sf::Drawable> drawPlatform(const GameObject &obj) {
	return drawPlayer(obj);
}

void updatePlayer(Player &player) {
}
