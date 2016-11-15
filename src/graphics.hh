#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "gameobjects.hh"

struct Graphics {
	Graphics(sf::RenderWindow &window);

	sf::RenderWindow &window;
	std::vector<GameObject> objects;
};

void render(Graphics &graphics);
void drawInto(const GameObject &object, Graphics &graphics);
void clearGraphics(Graphics &graphics);
