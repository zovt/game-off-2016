#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class GameObject {
	public:
		GameObject(std::unique_ptr<sf::Drawable> drawable);
		virtual ~GameObject() {}

		virtual void update() = 0;
		virtual bool shouldDelete() const = 0;

		sf::Drawable& getDrawable();

		const int id;

	protected:
		std::unique_ptr<sf::Drawable> drawable;

	private:
		static int currentID;
};
