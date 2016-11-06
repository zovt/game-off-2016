#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.hh"
#include "Graphics.hh"

class World {
	public:
		World(int screenX, int screenY);

		void update();
		void drawInto(Graphics &graphics);

	private:
		std::vector<GameObject> objects;
		int screenX;
		int screenY;
};
