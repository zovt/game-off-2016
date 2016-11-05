#include "GameObject.hh"

GameObject::GameObject(std::unique_ptr<sf::Drawable> drawable) {
	this->id = GameObject::currentID;
	this->drawable = std::unique_ptr<sf::Drawable>(std::move(drawable));

	GameObject::currentID++;
}

int GameObject::getID() const {
	return this->id;
}

sf::Drawable* GameObject::getDrawable() const {
	return this->drawable.get();
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(*this->drawable, states);
}

int GameObject::currentID = 0;
