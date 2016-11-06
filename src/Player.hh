#include <SFML/Graphics.hpp>
#include "GameObject.hh"

class Player : public GameObject {
	public:
		Player();

		void update();
		bool shouldDelete() const;

	private:
};
