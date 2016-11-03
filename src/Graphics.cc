#include "Graphics.hh"

Graphics::Graphics(sf::RenderWindow * const window) : window(window) {
}

void Graphics::addToScene(sf::Drawable const *drawable) {
	this->scene.insert(drawable);
}

void Graphics::removeFromScene(sf::Drawable const *drawable) {
	this->scene.erase(drawable);
}

void Graphics::render() const {
	this->window->clear();

	for (auto it = this->scene.begin(); it != this->scene.end(); it++) {
		this->window->draw(**it);
	}

	this->window->display();
}

