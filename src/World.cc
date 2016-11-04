#include "World.hh"

void World::init() {

}

void World::update() {
	std::vector<std::unique_ptr<GameObject>> newObjects;

	for (auto idx = this->objects.begin(); idx != this->objects.end(); idx++) {
		std::unique_ptr<GameObject> &obj = *idx;
		obj->update();

		if (!obj->shouldDelete()) {
			newObjects.push_back(std::move(obj));
		}
	}

	this->objects.swap(newObjects);
}

void World::drawInto(std::shared_ptr<Graphics> graphics) {
	for (std::unique_ptr<GameObject> &obj : this->objects) {
		graphics->add(obj->getDrawable());
	}
}
