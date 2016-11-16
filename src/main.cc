#include <SFML/Graphics.hpp>
#include <iostream>

#include "graphics.hh"
#include "world.hh"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Axcend");
	Graphics graphics(window);
	World world;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		clearGraphics(graphics);
		updateWorld(world);
		drawWorld(world, graphics);
		render(graphics);
	}

	return 0;
}
