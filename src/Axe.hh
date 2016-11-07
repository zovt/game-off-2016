#include <SFML/Graphics.hpp>
#include "GameObject.hh"

class Axe : public GameObject, public sf::CircleShape {
	public:
		Axe(int x, int y);

		void update() override;
		bool shouldDelete() const override;

	protected:
		const sf::Drawable* asDrawable() const override;
};
