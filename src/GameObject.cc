#include "GameObject.hh"

GameObject::GameObject() : id(GameObject::currentID) {
		GameObject::currentID++;
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(*this->asDrawable(), states);
}

int GameObject::currentID = 0;
