#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable {
	public:
		GameObject();
		virtual ~GameObject() {}

		virtual void update() = 0;
		virtual bool shouldDelete() const = 0;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		const int id;

	protected:
		virtual const sf::Drawable* asDrawable() const = 0;

	private:
		static int currentID;
};
