#include <iostream>

#include "graphics.hh"

Graphics::Graphics(sf::RenderWindow &window) : window(window) { }

void render(Graphics &graphics) {
	graphics.window.clear();

	for (GameObject &g : graphics.objects) {
		graphics.window.draw(*g.draw(g.position, g.size));
	}

	graphics.window.display();
}

void drawInto(const GameObject &object, Graphics &graphics) {
	graphics.objects.push_back(object);
}

void clearGraphics(Graphics &graphics) {
	graphics.objects.clear();
}
