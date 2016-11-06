#include <memory>

#include "Graphics.hh"

class Engine {
	public:
		Engine(int width, int height);
		~Engine();

		void close();

		Graphics& graphics() noexcept;
		bool pollEvent(sf::Event &event);
		bool isRunning() const;

	private:
		sf::RenderWindow window;
		Graphics _graphics;
};
