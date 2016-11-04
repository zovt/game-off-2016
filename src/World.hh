#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.hh"
#include "Graphics.hh"

class World {
	public:
		void init();
		void update();
		void drawInto(std::shared_ptr<Graphics> graphics);

	private:
		std::vector<std::unique_ptr<GameObject>> objects;
};
