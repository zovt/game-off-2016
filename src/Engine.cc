#include "Engine.hh"
#include <iostream>

Engine::Engine() {
}

void Engine::init() {
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "");
	this->_graphics = new Graphics(this->window);
}

void Engine::close() {
	this->window->close();
}

Graphics* Engine::graphics() const noexcept {
	return this->_graphics;
}

bool Engine::pollEvent(sf::Event &event) const {
	return this->window->pollEvent(event);
}

bool Engine::isRunning() const {
	return this->window->isOpen();
}
