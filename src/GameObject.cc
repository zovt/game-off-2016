#include "GameObject.hh"
GameObject::GameObject(std::unique_ptr<sf::Drawable> drawable) :
	id(GameObject::currentID),
	drawable(std::move(drawable)) {
	GameObject::currentID++;
}

sf::Drawable& GameObject::getDrawable() {
	return *this->drawable;
}

int GameObject::currentID = 0;
