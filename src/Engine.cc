#include "Engine.hh"

void Engine::init() {
	this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "");
	this->_graphics = std::make_shared<Graphics>(this->window);
}

void Engine::close() {
	this->window->close();
}

std::shared_ptr<Graphics> Engine::graphics() const noexcept {
	return this->_graphics;
}

bool Engine::pollEvent(sf::Event &event) const {
	return this->window->pollEvent(event);
}

bool Engine::isRunning() const {
	return this->_graphics != nullptr 
		&& this->window != nullptr
		&& this->window->isOpen();
}
