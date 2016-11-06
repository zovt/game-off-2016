#include "World.hh"
#include "Player.hh"

World::World(int screenX, int screenY) {
	this->screenX = screenX;
	this->screenY = screenY;

	this->objects.push_back(std::make_unique<Player>());
}

void World::update() {
	std::vector<std::unique_ptr<GameObject>> newObjects;

	for (std::unique_ptr<GameObject> &obj : this->objects) {
		obj->update();

		if (!obj->shouldDelete()) {
			newObjects.push_back(std::move(obj));
		}
	}

	this->objects.swap(newObjects);
}

void World::drawInto(Graphics &graphics) {
	for (std::unique_ptr<GameObject> &obj : this->objects) {
		graphics.add(&obj->getDrawable());
	}
}
