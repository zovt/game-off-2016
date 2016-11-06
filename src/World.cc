#include "World.hh"

World::World(int screenX, int screenY) {
	this->screenX = screenX;
	this->screenY = screenY;
}

void World::update() {
	std::vector<GameObject> newObjects;

	for (GameObject obj : this->objects) {
		obj.update();

		if (!obj.shouldDelete()) {
			newObjects.push_back(obj);
		}
	}

	this->objects.swap(newObjects);
}

void World::drawInto(Graphics &graphics) {
	for (GameObject &obj : this->objects) {
		graphics.add(std::make_unique<sf::Drawable>(obj.getDrawable()));
	}
}
