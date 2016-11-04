#include "GameObject.hh"

GameObject::GameObject(sf::Drawable const &drawable) {
	this->id = GameObject::currentID;
	this->drawable = drawable;

	GameObject::currentID++;
}

int GameObject::getID() const {
	return this->id;
}

std::shared_ptr<sf::Drawable> GameObject::getDrawable() const {
	return this->drawable;
}

int GameObject::currentID = 0;
