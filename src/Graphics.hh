#include <SFML/Graphics.hpp>
#include <memory>
#include <set>

class Graphics {
	public:
		Graphics(std::shared_ptr<sf::RenderWindow> const window);

		void add(std::shared_ptr<sf::Drawable> const drawable);

		void render();

	private:
		std::set<std::shared_ptr<const sf::Drawable>> scene;
		std::shared_ptr<sf::RenderWindow> const window;
};
