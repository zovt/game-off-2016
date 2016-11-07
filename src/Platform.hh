#include <SFML/Graphics.hpp>
#include "GameObject.hh"

class Platform : public GameObject, public sf::RectangleShape {
	public:
		Platform(int x, int y, int width);

		void update() override;
		bool shouldDelete() const override;

	protected:
		const sf::Drawable* asDrawable() const override;
};
