#include <SFML/Graphics.hpp>
#include <memory>
#include <set>

class Graphics {
	public:
		Graphics(sf::RenderWindow const &window);

		void add(sf::Drawable * const drawable);

		void render();

	private:
		std::set<sf::Drawable const*> scene;
		sf::RenderWindow window;
};
