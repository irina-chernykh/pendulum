#include <SFML/Graphics.hpp> 
#include "partPendulum.h"
#include "const.h"

using namespace sf;

void DrawElements(RenderWindow &window)
{
	window.clear(Color::White);
	window.draw(pendulum.base);
	window.draw(pendulum.leftPartArrow);
	window.draw(pendulum.rightPartArrow);
	window.draw(pendulum.cargo);

	window.draw(pendulum.upCog);
	window.draw(pendulum.downCog);

	window.display();
}

void StartMove(RenderWindow &window)
{
	pendulum.InitElementsOfPendulum();
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		pendulum.Update();
		DrawElements(window);
	}
}

int main() {
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	Texture upCogwheel, downCogwheel;
	upCogwheel.loadFromFile("images/blackCog.psd");
	downCogwheel.loadFromFile("images/greenCog.psd");
	pendulum.upCog.setTexture(&upCogwheel);
	pendulum.downCog.setTexture(&downCogwheel);


	RenderWindow window(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Pendulum", Style::Default, settings);
	StartMove(window);
	return 0;
}
