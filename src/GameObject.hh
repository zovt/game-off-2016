#include <memory>
#include <SFML/Graphics.hpp>

class GameObject : public sf::Transformable, public sf::Drawable {
	public:
		GameObject(sf::Drawable &drawable);

		int getID() const;
		const sf::Drawable& getDrawable() const;

		void update();
		bool shouldDelete() const;

	protected:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		int id;
		sf::Drawable &drawable;

		static int currentID;
};
