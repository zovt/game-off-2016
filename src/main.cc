#include <SFML/Graphics.hpp>
#include <memory>

#include "World.hh"
#include "Engine.hh"

int main() {
	Engine engine;
	World world(800, 600);

	while (engine.isRunning()) {
		sf::Event event;
		while (engine.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				engine.close();
				continue;
			}
		}

		world.drawInto(engine.graphics());
		engine.graphics().render();
	}

	return 0;
}

