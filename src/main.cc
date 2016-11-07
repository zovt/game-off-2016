#include <SFML/Graphics.hpp>
#include <memory>

#include "World.hh"
#include "Engine.hh"
#include "Player.hh"

int main() {
	int width = 800;
	int height = 600;

	Engine engine(width, height);
	World world(width, height);

	engine.graphics().add(&world);

	while (engine.isRunning()) {
		sf::Event event;
		while (engine.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				engine.close();
				continue;
			}
		}

		world.update();
		engine.graphics().render();
	}

	return 0;
}

