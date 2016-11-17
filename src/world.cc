#include "world.hh"
#include "gameobjects.hh"

World::World(const Box &dimensions) : dimensions(dimensions) {
	GameObject platform = makePlatform(Position(0, 0));
	moveToPosition(platform, centerInside(dimensions, platform.size));
	this->objects.push_back(platform);

	GameObject player = makePlayer(Position(0, 0));
	moveToPosition(player, centerInside(dimensions, player.size));
	moveTo(player, player.position.x,
			player.position.y - platform.size.height / 2 - player.size.height / 2);
	this->objects.push_back(player);
}

void drawWorld(const World &world, Graphics &graphics) {
	for (const GameObject &obj : world.objects) {
		drawInto(obj, graphics);
	}
}

void updateWorld(World &world) {
	for (GameObject &obj : world.objects) {
		for (GameObject &other : world.objects) {
			if (&other == &obj) {
				continue;
			}

			if (checkCollision(obj.collider, other.collider)) {
				obj.collider.handler(obj, other);
			}
		}
	}

	for (GameObject &obj : world.objects) {
		obj.update(obj);
	}
}
