#include "Graphics.hh"

Graphics::Graphics(std::shared_ptr<sf::RenderWindow> window) : window(window) {
}

void Graphics::add(std::shared_ptr<sf::Drawable> const drawable) {
	this->scene.insert(drawable);
}

void Graphics::render() {
	this->window->clear();

	for (auto it = this->scene.begin(); it != this->scene.end(); it++) {
		this->window->draw(**it);
	}

	this->window->display();

	this->scene.clear();
}

