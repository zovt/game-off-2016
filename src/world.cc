#include "world.hh"
#include "gameobjects.hh"

World::World(const Box &dimensions) : dimensions(dimensions) {
	this->objects.push_back(makePlayer(Position(dimensions.width / 2,
					dimensions.height / 2)));
	this->objects.push_back(makePlatform(Position(dimensions.width / 2,
					dimensions.height / 2)));
}

void drawWorld(const World &world, Graphics &graphics) {
	for (const GameObject &obj : world.objects) {
		drawInto(obj, graphics);
	}
}

void updateWorld(World &world) {
	for (GameObject &obj : world.objects) {
		obj.update(obj);
	}
}
