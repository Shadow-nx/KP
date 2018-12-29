#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "entity.hpp"
#include "enemy.hpp"
#include "player.hpp"
#include "level.hpp"
#include <vector>
#include <list>

using namespace std;
using namespace sf;
View view;

Vector2f mousePosition(RenderWindow& window) {
	Vector2i pixelPosition = Mouse::getPosition(window);
	Vector2f pos = window.mapPixelToCoords(pixelPosition);
	return pos;
}

int main()
{
	//Level lvl;
	//lvl.LoadFromFile("levels/test12.tmx");
	//RenderWindow window(VideoMode(1000, 600), "SFML works!");
	view.reset(FloatRect(0, 0, 1000, 600));
	
	//Object player = lvl.GetObject("Player");

	//Player p(lvl, player.rect.left, player.rect.top,96/4,96/4);
	




	double Current_Frame = 0.0;
	Clock clock;

	//while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		Event event;
		//while (window.pollEvent(event)) {
			//if (event.type == Event::Closed)
				//window.close();
		//}


		//if (Mouse::isButtonPressed(Mouse::Left)) {
			//p.update(mousePosition(window),time);
		//}
		
		//window.clear(Color(77, 83, 140));
		//lvl.Sort(p.getPlayerCoordinateX(), p.getPlayerCoordinatrY());
		//lvl.Draw(window, 1);
		//p.Draw(window, view);
		//lvl.Draw(window, 0);
		//window.display();

	//}


	system("PAUSE");
	return 0;
}
