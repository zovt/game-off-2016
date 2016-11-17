#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

#include "graphics.hh"
#include "world.hh"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Axcend");
	Graphics graphics(window);
	World world(Box(800, 600));

	auto prevTime = std::chrono::high_resolution_clock().now();
	std::chrono::microseconds lag = std::chrono::microseconds::zero();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		clearGraphics(graphics);

		auto currentTime = std::chrono::high_resolution_clock().now();
		auto timeDelta = std::chrono::duration_cast<std::chrono::microseconds>(currentTime.time_since_epoch() - prevTime.time_since_epoch());
		lag += timeDelta;
		prevTime = currentTime;
		if (lag >= MS_PER_UPDATE) {
			updateWorld(world);
			lag -= MS_PER_UPDATE;
		}

		drawWorld(world, graphics);
		render(graphics);
	}

	return 0;
}
