#include "world.hh"
#include "gameobjects.hh"

World::World() {
	this->objects.push_back(makePlayer());
}

void drawWorld(const World &world, Graphics &graphics) {
	for (const GameObject &obj : world.objects) {
		drawInto(obj, graphics);
	}
}
