#include <iostream>

#include "graphics.hh"

Graphics::Graphics(sf::RenderWindow &window) : window(window) { }

void render(Graphics &graphics) {
	graphics.window.clear();

	for (auto &drawable : graphics.objects) {
		graphics.window.draw(*drawable);
	}

	graphics.window.display();
}

void drawInto(std::unique_ptr<sf::Drawable> drawable, Graphics &graphics) {
	graphics.objects.push_back(std::move(drawable));
}

void clearGraphics(Graphics &graphics) {
	graphics.objects.clear();
}
