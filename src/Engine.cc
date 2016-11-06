#include "Engine.hh"

Engine::Engine(int width, int height) 
	: window(sf::VideoMode(width, height), "Axcend"),
	_graphics(this->window) { }

Engine::~Engine() {
	this->close();
}

void Engine::close() {
	this->window.close();
}

Graphics& Engine::graphics() noexcept {
	return this->_graphics;
}

bool Engine::pollEvent(sf::Event &event) {
	return this->window.pollEvent(event);
}

bool Engine::isRunning() const {
		return this->window.isOpen();
}
