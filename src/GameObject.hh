#include <memory>
#include <SFML/Graphics.hpp>

class GameObject {
	public:
		GameObject(sf::Drawable const &drawable);
		virtual ~GameObject() = 0;

		int getID() const;
		sf::Drawable getDrawable() const;

		virtual void update() = 0;
		virtual bool shouldDelete() const = 0;

	private:
		int id;
		std::unique_ptr<sf::Drawable> drawable;

		static int currentID;
};
