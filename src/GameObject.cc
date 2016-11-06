#include "GameObject.hh"

GameObject::GameObject(sf::Drawable &drawable)
	: drawable(drawable) {
	this->id = GameObject::currentID;
	this->drawable = drawable;

	GameObject::currentID++;
}

int GameObject::getID() const {
	return this->id;
}

const sf::Drawable& GameObject::getDrawable() const {
	return this->drawable;
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(this->drawable, states);
}

void GameObject::update() {
	return;
}

bool GameObject::shouldDelete() const {
	return false;
}

int GameObject::currentID = 0;
