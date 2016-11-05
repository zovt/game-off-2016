#include <SFML/Graphics.hpp>
#include <memory>
#include <set>

class Graphics {
	public:
		Graphics(std::unique_ptr<sf::RenderWindow> const window);

		void add(sf::Drawable * const drawable);

		void render();

	private:
		std::set<const sf::Drawable*> scene;
		const std::unique_ptr<sf::RenderWindow> window;
};
