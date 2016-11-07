#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

#include "Object2D.hh"

class GameObject {
	public:
		GameObject(std::unique_ptr<Object2D> object) :
			id(GameObject::currentID),
			object(std::move(object)) {
				GameObject::currentID++;
			}

		virtual ~GameObject() {}

		virtual void update() = 0;
		virtual bool shouldDelete() const = 0;

		sf::Drawable& getDrawable() {
			return *this->object;
		}

		sf::Transformable& getTransformable() {
			return *this->object;
		}

		const int id;

	protected:
		std::unique_ptr<Object2D> object;

	private:
		static int currentID;
};

int GameObject::currentID = 0;
