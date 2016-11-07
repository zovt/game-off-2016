#include "World.hh"
#include "Player.hh"

World::World(int screenX, int screenY) {
	this->screenX = screenX;
	this->screenY = screenY;

	this->objects.push_back(std::make_unique<Player>());
}

void World::update() {
	std::vector<std::unique_ptr<GameObject<void>>> newObjects;

	for (std::unique_ptr<GameObject<void>> &obj : this->objects) {
		obj->update();

		if (!obj->shouldDelete()) {
			newObjects.push_back(std::move(obj));
		}
	}

	this->objects.swap(newObjects);
}

void World::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	for (const std::unique_ptr<GameObject<sf::Drawable>> &obj : this->objects) {
		target.draw(obj->getDrawable(), states);
	}
}
