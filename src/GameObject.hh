#include <memory>
#include <SFML/Graphics.hpp>

class GameObject {
	public:
		GameObject(std::shared_ptr<sf::Drawable> drawable);
		virtual ~GameObject() = 0;

		int getID() const;
		std::shared_ptr<sf::Drawable> getDrawable() const;

		virtual void update() = 0;
		virtual bool shouldDelete() const = 0;

	private:
		int id;
		std::shared_ptr<sf::Drawable> drawable;

		static int currentID;
};
