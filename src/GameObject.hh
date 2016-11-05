#include <memory>
#include <SFML/Graphics.hpp>

class GameObject : public sf::Transformable, public sf::Drawable {
	public:
		GameObject(std::unique_ptr<sf::Drawable> drawable);
		virtual ~GameObject() = 0;

		int getID() const;
		sf::Drawable* getDrawable() const;

		virtual void update() = 0;
		virtual bool shouldDelete() const = 0;

	protected:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		int id;
		std::unique_ptr<sf::Drawable> drawable;

		static int currentID;
};
