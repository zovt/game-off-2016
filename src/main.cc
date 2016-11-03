#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.hh"
#include "Engine.hh"

int main() {
	Engine *engine = new Engine();
	engine->init();

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	engine->graphics()->addToScene(&shape);
	
	while (engine->isRunning()) {
		sf::Event event;
		while (engine->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				engine->close();
				continue;
			}
		}

		engine->graphics()->render();
	}

	return 0;
}

