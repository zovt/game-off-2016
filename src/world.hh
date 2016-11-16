#pragma once
#include <vector>

#include "graphics.hh"
#include "gameobjects.hh"

struct World {
	World();

	std::vector<GameObject> objects;
};

void drawWorld(const World &world, Graphics &graphics);
void updateWorld(World &world);
