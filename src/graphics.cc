#include "graphics.hh"

Graphics::Graphics(sf::RenderWindow &window) : window(window) { }

void render(Graphics &graphics) {
	for (const GameObject &g : graphics.objects) {
		graphics.window.draw(g.draw(g));
	}
}

void drawInto(const GameObject &object, Graphics &graphics) {
	graphics.objects.push_back(object);
}
