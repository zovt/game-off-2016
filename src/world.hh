#pragma once
#include <vector>
#include <chrono>

#include "graphics.hh"
#include "gameobjects.hh"

struct World {
	World(const Box &dimensions);

	Player player;
	GameObject platform;
	std::vector<AxeSpawner> spawners;
	std::vector<Axe> axes;

	long tick = 0;
	const Box &dimensions;
};

void drawWorld(const World &world, Graphics &graphics);
void updateWorld(World &world);

static int UPDATES_PER_SECOND = 60;
static std::chrono::milliseconds MS_PER_UPDATE = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::seconds(1) / 60.0);
