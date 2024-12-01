#include "Main.h"

int main()
{
	RenderWindow window({ WINDOWWIDTH,WINDOWHEIGHT }, "Snake");

	Snake snake;

	Clock moveClock;
	Time moveTimer;

	Clock inBetweens;
	Time dt;

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		moveTimer = moveClock.getElapsedTime();
		if (moveTimer.asSeconds() > .5)
		{
			moveClock.restart();
			snake.move();
		}
		snake.changeDirection();

		dt = inBetweens.restart();

		window.clear();
		for (int i = 0; i < snake.drawSnek().size(); i++)
		{
			window.draw(snake.drawSnek().at(i));
		}
		window.display();

	}



	return 0;
}