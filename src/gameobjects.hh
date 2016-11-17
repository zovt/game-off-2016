#pragma once
#include <SFML/Graphics.hpp>

struct Position {
	Position(const float x, const float y);

	float x;
	float y;
};

struct Box {
	Box(const float width, const float height);

	float width;
	float height;
};

struct GameObject;

struct Collider {
	Collider(Position &position, Box &box);

	Position &position;
	Box &box;
};

enum GameObjectType {
	PLAYER,
	PLATFORM,
	AXE,
	AXE_SPAWNER
};

struct GameObject {
	GameObject(Position position, Box size, GameObjectType type);

	int id;
	GameObjectType type;
	Position position;
	Box size;
	Collider collider;
};

struct Player : GameObject {
	Player(const Position &position);

	int health = 3;
};

struct AxeSpawner : GameObject {
	AxeSpawner(const Position &position, int spawnTick);

	int tick = 0;
	int spawnTick;
};

struct Axe : GameObject {
	Axe(const Position &position);
};

GameObject makePlatform(const Position &position);

sf::Vector2f boxToVec2f(const Box &box);
sf::Vector2f positionToVec2f(const Position &position);

Position centerInside(const Box &outer, const Box &inner);

bool checkCollision(const Collider &col1, const Collider &col2);

std::string gotString(GameObjectType got);

void moveToPosition(GameObject &gameObject, const Position position);
void moveTo(GameObject &gameObject, const float x, const float y);
void moveD(GameObject &gameObject, const float xOffset, const float yOffset);

std::unique_ptr<sf::Drawable> drawPlayer(const GameObject &player);
std::unique_ptr<sf::Drawable> drawPlatform(const GameObject &platform);

void updatePlayer(Player &player);
