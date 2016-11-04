#include <SFML/Graphics.hpp>
#include <memory>

#include "GameObject.hh"
#include "Engine.hh"

int main() {
	Engine engine;

	auto shape = std::make_shared<sf::CircleShape>(100.f);
	shape->setFillColor(sf::Color::Green);
	
	while (engine.isRunning()) {
		sf::Event event;
		while (engine.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				engine.close();
				continue;
			}
		}

		engine.graphics()->add(shape);
		engine.graphics()->render();
	}

	return 0;
}

