#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <set>

class Graphics {
	public:
		Graphics(sf::RenderWindow &window);

		void add(const sf::Drawable * const drawable);

		void render();

	private:
		std::set<const sf::Drawable*> scene;
		sf::RenderWindow &window;
};
