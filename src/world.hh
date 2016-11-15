#pragma once
#include <vector>

#include "gameobjects.hh"

struct World {
	World();

	std::vector<GameObject> objects;
};

void drawWorld(const World &world, Graphics &graphics);
