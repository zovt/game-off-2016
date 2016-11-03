#include "Graphics.hh"

class Engine {
	public:
		Engine();

		void init();
		void close();

		Graphics* graphics() const noexcept;
		bool pollEvent(sf::Event &event) const;
		bool isRunning() const;

	private:
		sf::RenderWindow *window;
		Graphics *_graphics;
};
