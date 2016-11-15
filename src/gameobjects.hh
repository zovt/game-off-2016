#pragma once
#include <SFML/Graphics.hpp>

#include "graphics.hh"

struct Position {
	Position(int x, int y);

	int x;
	int y;
};

struct Bounds {
	Bounds(int topLeft, int topRight);

	int topLeft;
	int bottomRight;
};

struct Collider {
	Collider(Position position, Bounds bounds);

	Position position;
	Bounds bounds;
};

struct GameObject {
	typedef sf::Drawable& (*DrawMethod)(const GameObject &object);

	GameObject(Position position, DrawMethod draw);

	Position position;
	Collider collider;
	DrawMethod draw;
};

void moveTo(GameObject &gameObject, const Position &position);


GameObject::DrawMethod drawPlayer();
GameObject makePlayer();
