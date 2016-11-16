#include "world.hh"
#include "gameobjects.hh"

World::World() {
	this->objects.push_back(makePlayer(Position(50, 50)));
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
