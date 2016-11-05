#include "Graphics.hh"

Graphics::Graphics(std::unique_ptr<sf::RenderWindow> window) 
	: window(std::move(window)) { }

void Graphics::add(sf::Drawable * const drawable) {
	this->scene.insert(drawable);
}

void Graphics::render() {
	this->window->clear();

	for (auto obj : this->scene) {
		this->window->draw(*obj);
	}

	this->window->display();

	this->scene.clear();
}

