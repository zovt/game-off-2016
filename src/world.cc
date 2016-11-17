#include "world.hh"
#include "gameobjects.hh"

#include <iostream>
#include <random>
#include <cmath>

World::World(const Box &dimensions) 
	: player(Player(Position(0, 0))),
	platform(makePlatform(Position(0,0))),
	dimensions(dimensions) {
		moveToPosition(platform, centerInside(dimensions, platform.size));

		moveToPosition(player, centerInside(dimensions, player.size));
		moveTo(player, player.position.x,
				player.position.y - platform.size.height / 2 - player.size.height / 2);
}

void drawWorld(const World &world, Graphics &graphics) {
	drawInto(drawPlayer(world.player), graphics);
	drawInto(drawPlatform(world.platform), graphics);
}

int prevTimeSeconds = -1;
void updateWorld(World &world) {

	int timeSeconds = world.tick / (1000 / MS_PER_UPDATE.count());
	if (timeSeconds % 5 == 0 && prevTimeSeconds != timeSeconds) {
		prevTimeSeconds = timeSeconds;
		std::mt19937_64 genX(world.tick);
		std::mt19937_64 genY(world.tick / 2);
		std::uniform_int_distribution<int> xSide(0, 1);
		std::uniform_int_distribution<int> ySide(0, 1);

		int xPos = xSide(genX) == 0 ? -24 : world.dimensions.width + 24;
		int yPos = ySide(genY) == 0 ? -24 : world.dimensions.height + 24;

		int spawnTick = 60000 / (timeSeconds + 1);
		std::cout << spawnTick;
		world.spawners.push_back(AxeSpawner(Position(xPos, yPos), spawnTick));
		std::cout << "Spawner spawned" << std::endl;
	}

	if (checkCollision(world.player.collider, world.platform.collider)) {
		// std::cout << "Player hitting platform" << std::endl;
	}

	for (auto axe : world.axes) {
		if (checkCollision(world.player.collider, axe.collider)) {
			world.player.health -= 1;
		}
	}

	updatePlayer(world.player);
	for (auto &spawner : world.spawners) {
		spawner.tick += 1;
		if (spawner.tick == spawner.spawnTick) {
			world.axes.push_back(Axe(spawner.position));
			spawner.tick = 0;
		}
	}

	world.tick += 1;
}
