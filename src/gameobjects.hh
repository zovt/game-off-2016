#pragma once
#include <SFML/Graphics.hpp>

struct Position {
	Position(const float x, const float y);

	float x;
	float y;
};

sf::Vector2f positionToVec2f(const Position &position);

struct Box {
	Box(const float width, const float height);

	float width;
	float height;
};

sf::Vector2f boxToVec2f(const Box &box);

struct Collider {
	Collider(Position &position, Box &box);

	Position &position;
	Box &box;
};

struct GameObject {
	typedef const std::unique_ptr<sf::Drawable> (*DrawMethod)(const Position &position, const Box &size);
	typedef void (*UpdateMethod)(GameObject &obj);
	GameObject(Position position, Box size, DrawMethod draw, UpdateMethod update);

	int id;
	Position position;
	Box size;
	Collider collider;
	DrawMethod draw;
	UpdateMethod update;
};

void moveTo(GameObject &gameObject, const float x, const float y);
void moveD(GameObject &gameObject, const float xOffset, const float yOffset);


GameObject makePlayer(const Position &position);
GameObject makePlatform(const Position &position);
