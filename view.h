#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;//объ€вили sfml объект "вид", который и €вл€етс€ камерой

void getplayercoordinateforview(float x, float y) { //функци€ дл€ считывани€ координат игрока
	float tempX = x; float tempY = y;//считываем коорд игрока и провер€ем их, чтобы убрать кра€

		if (x < 320) tempX = 320;//убираем из вида левую сторону
		if (x > 2172) tempX = 2172;//убираем из вида левую сторону
		if (y < 240) tempY = 240;//верхнюю сторону
		if (y > 2160) tempY = 2160;//нижнюю сторону

	view.setCenter(tempX, tempY); //следим за игроком, передава€ его координаты. 

}
