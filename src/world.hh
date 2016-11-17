#pragma once
#include <vector>

#include "graphics.hh"
#include "gameobjects.hh"

struct World {
	World(const Box &dimensions);

	std::vector<GameObject> objects;
	const Box &dimensions;
};

void drawWorld(const World &world, Graphics &graphics);
void updateWorld(World &world);
