#include <SFML/Graphics.hpp>
#include <set>

class Graphics {
	public:
		Graphics(sf::RenderWindow * const window);

		void addToScene(sf::Drawable const *drawable);
		void removeFromScene(sf::Drawable const *drawable);

		void render() const;

	private:
		std::set<sf::Drawable const*> scene;
		sf::RenderWindow * const window;
};
