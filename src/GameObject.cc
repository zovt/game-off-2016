#include "GameObject.hh"

GameObject::GameObject() {
	this->id = GameObject::currentID;
	GameObject::currentID++;
}

int GameObject::getID() const {
	return this->id;
}

int GameObject::currentID = 0;
