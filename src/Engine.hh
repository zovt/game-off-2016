#include <memory>

#include "Graphics.hh"

class Engine {
	public:
		Engine();
		~Engine();

		void close();

		Graphics graphics() const noexcept;
		bool pollEvent(sf::Event &event);
		bool isRunning() const;

	private:
		sf::RenderWindow window;
		Graphics _graphics;
};
