#include <memory>

#include "Graphics.hh"

class Engine {
	public:
		void init();
		void close();

		std::shared_ptr<Graphics> graphics() const noexcept;
		bool pollEvent(sf::Event &event) const;
		bool isRunning() const;

	private:
		std::shared_ptr<sf::RenderWindow> window;
		std::shared_ptr<Graphics> _graphics;
};
