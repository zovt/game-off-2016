#include "World.hh"
#include "Player.hh"
#include "Platform.hh"
#include "Axe.hh"

World::World(int screenX, int screenY) {
	this->screenX = screenX;
	this->screenY = screenY;
	
	this->objects.push_back(std::make_unique<Player>(screenX / 2, screenY / 2));
	this->objects.push_back(std::make_unique<Platform>((screenX / 2) - 250, (screenY / 2) + 20, 500));
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

void World::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	for (const std::unique_ptr<GameObject> &obj : this->objects) {
		target.draw(*obj, states);
	}
}
