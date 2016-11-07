#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.hh"
#include "Object2D.hh"
#include "Graphics.hh"

class World : public sf::Drawable {
	public:
		World(int screenX, int screenY);

		void update();
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		std::vector<std::unique_ptr<GameObject>> objects;
		int screenX;
		int screenY;
};
