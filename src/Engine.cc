#include "Engine.hh"

Engine::Engine() 
	: window(sf::VideoMode(800, 600), ""),
	_graphics(this->window) { }

Engine::~Engine() {
	this->close();
}

void Engine::close() {
	this->window.close();
}

Graphics Engine::graphics() const noexcept {
	return this->_graphics;
}

bool Engine::pollEvent(sf::Event &event) {
	return this->window.pollEvent(event);
}

bool Engine::isRunning() const {
		return this->window.isOpen();
}
