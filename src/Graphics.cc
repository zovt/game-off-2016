#include "Graphics.hh"

Graphics::Graphics(sf::RenderWindow &window) 
	: window(window) { }

void Graphics::add(const sf::Drawable * const drawable) {
	this->scene.insert(drawable);
}

void Graphics::render() {
	this->window.clear();

	for (auto &obj : this->scene) {
		this->window.draw(*obj);
	}

	this->window.display();
}

