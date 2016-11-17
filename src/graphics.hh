#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "gameobjects.hh"

struct Graphics {
	Graphics(sf::RenderWindow &window);

	sf::RenderWindow &window;
	std::vector<std::unique_ptr<sf::Drawable>> objects;
};

void render(Graphics &graphics);
void drawInto(std::unique_ptr<sf::Drawable> drawable, Graphics &graphics);
void clearGraphics(Graphics &graphics);
