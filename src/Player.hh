#include <SFML/Graphics.hpp>
#include "GameObject.hh"

class Player : private sf::RectangleShape, public GameObject {
	public:
		Player(int x, int y);

		void update() override;
		bool shouldDelete() const override;

	protected:
		const sf::Drawable* asDrawable() const override;
};
