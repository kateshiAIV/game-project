
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include <iostream>
#include <sstream>
#include "mission.h"
#include "menu.h"
#include "iostream"
#include "level.h"
#include <vector>
#include <cstdlib> 
#include <list>
#include <algorithm>
#include "TinyXML/tinyxml.h"
#include "mapchanger.h"
#include "Dialogues.h"

using namespace sf;
using namespace std;



////////////////////////////////////////////////////КЛАСС ИГРОКА////////////////////////

class Bullet {
public:
	float x, y;
	float dx, dy;
	Sprite sprite;
	float distanceTravelled;
	Bullet(Texture& texture, float X, float Y, float targetX, float targetY) {
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(16, 106, 16, 162));
		x = X + 72;
		y = Y + 72;
		float angle = atan2(targetY - y, targetX - x);
		dx = targetX;
		dy = targetY;
		distanceTravelled = 0;
	}


};

class PlantsSpawner {
public:
	float x, y;
	int pt;
	Sprite sprite;
	PlantsSpawner(Texture& texture, float X , float Y, int plantType) {
		sprite.setTexture(texture);
		x = X;
		y = Y;
		pt = plantType;
		if(pt == 1){ sprite.setTextureRect(IntRect(190, 140, 100, 140)); }
		if (pt == 2) { sprite.setTextureRect(IntRect(350, 130, 65, 60)); }
		if (pt == 3) { sprite.setTextureRect(IntRect(0, 192 , 92, 92)); }



	}
};



class Enemy {

public:
	float x_e, y_e, x1_e, x2_e, y1_e, y2_e;
	float w_e, h_e, dx_e, dy_e, speed_e;
	int dir = 0;
	FloatRect rect_e;
	String File_e;
	Image image_e;
	Texture texture_e;
	Sprite sprite_e;
	bool life = true;

	Enemy(String F, float X, float Y, float W, float H, float x1, float y1, float x2, float y2, float speed = 0.05) {
		dx_e = 0; dy_e = 0;
		speed_e = speed;
		x1_e = x1;
		x2_e = x2;
		y1_e = y1;
		y2_e = y2;
		File_e = F;
		w_e = W; h_e = H;
		int dir_e = 0;
		image_e.loadFromFile(File_e);
		image_e.createMaskFromColor(Color(41, 33, 59));
		texture_e.loadFromImage(image_e);
		sprite_e.setTexture(texture_e);
		x_e = X; y_e = Y;
		sprite_e.setTextureRect(IntRect(0, 0, 64, 64));
		float CF = 0;
	}
	void update(float time, std::vector<Bullet>& bullets, float playerX, float playerY)
	{

		if (life) {
			// move enemy towards the player
			float distX = playerX - x_e;
			float distY = playerY - y_e;
			float dist = sqrt(distX * distX + distY * distY);
			if (dist <= 200) {
				dx_e = distX / dist * speed_e;
				dy_e = distY / dist * speed_e;

				// update enemy position
				x_e += dx_e * time;
				y_e += dy_e * time;
			}
			else {
				// move enemy in a square pattern
				if (x_e <= x1_e && y_e <= y1_e) {
					dx_e = 0;
					dy_e = speed_e;
				}
				else if (x_e >= x2_e && y_e <= y1_e) {
					dx_e = -speed_e;
					dy_e = 0;
					dir = 1;
				}
				else if (x_e >= x2_e && y_e >= y2_e) {
					dx_e = 0;
					dy_e = -speed_e;
					dir = 2;
				}
				else if (x_e <= x1_e && y_e >= y2_e) {
					dx_e = speed_e;
					dy_e = 0;
					dir = 3;
				}

				// update enemy position
				x_e += dx_e * time;
				y_e += dy_e * time;
			}
			sprite_e.setPosition(x_e, y_e);
		}
		for (auto bulletIter = bullets.begin(); bulletIter != bullets.end(); ) {
			Bullet& bullet = *bulletIter;

			// Check for collision with the enemy
			if (sprite_e.getGlobalBounds().intersects(bullet.sprite.getGlobalBounds())) {
				// Delete the bullet and move on to the next one
				bulletIter = bullets.erase(bulletIter);
				sprite_e.setPosition(-100, -100);
				life = false;;
				continue;
			}
			// Move the bullet
			bullet.x += bullet.dx;
			bullet.y += bullet.dy;
			bullet.sprite.setPosition(bullet.x, bullet.y);

			// Increment the iterator
			++bulletIter;
		}
	}
	float getplayercoordinateX_f() {	//этим методом будем забирать координату Х	
		return x_e;
	}
	float getplayercoordinateY_f() {	//этим методом будем забирать координату Y 	
		return y_e;
	}

};

class Friend {

public:
	float x_e, y_e, x1_e, x2_e, y1_e, y2_e;
	float w_e, h_e, dx_e, dy_e, speed_e;
	int dir = 0;
	FloatRect rect_e;
	String File_e;
	Image image_e;
	Texture texture_e;
	Sprite sprite_e;
	bool life = true;


	Friend(String F, float X, float Y, float W, float H, float x1, float y1, float x2, float y2) {
		dx_e = 0; dy_e = 0; speed_e = 0.05;
		x1_e = x1;
		x2_e = x2;
		y1_e = y1;
		y2_e = y2;
		File_e = F;
		w_e = W; h_e = H;
		image_e.loadFromFile(File_e);
		image_e.createMaskFromColor(Color(41, 33, 59));
		texture_e.loadFromImage(image_e);
		sprite_e.setTexture(texture_e);
		x_e = X; y_e = Y;
		sprite_e.setTextureRect(IntRect(x1_e, y1_e, x2_e, x2_e));
		sprite_e.setPosition(x_e, y_e);
	}
	
};


class Player {

public:
	float x, y;
	float w, h, dx, dy, speed;
	int dir = 0;
	FloatRect rect;
	String File;
	Image image;
	Image  death;
	Texture  death_texture;
	Texture texture;
	Sprite sprite;
	bool lifee = true;
	Player(String F, float X, float Y, float W, float H) {
		dx = 0; dy = 0; speed = 0;
		File = F;
		w = W; h = H;
		image.loadFromFile(File);
		image.createMaskFromColor(Color(41, 33, 59));
		death.loadFromFile("bow.png");
		death_texture.loadFromImage(death);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 64*10, 64, 64));
	}
	void update(float time, Enemy& e, Enemy& e1, Enemy& l1, Enemy& l2, Enemy& l3, Enemy l4)
	{
		
		if (lifee) {
			x += dx * time;
			y += dy * time;
		}
		if (!lifee) {
			sprite.setTexture(death_texture);
			sprite.setTextureRect(IntRect(64 * 4, 64 * 20, 64, 64));
		}
			interactionWithMap(0);//вызываем функцию, отвечающую за взаимодействие с картой
			interactionWithMap(1);//вызываем функцию, отвечающую за взаимодействие с картой
	
			speed = 0;
			sprite.setPosition(x, y);

		if (sprite.getGlobalBounds().intersects(e.sprite_e.getGlobalBounds())) {
			lifee = false;
		}
		if (sprite.getGlobalBounds().intersects(e1.sprite_e.getGlobalBounds())) {
			lifee = false;
		}
		if (sprite.getGlobalBounds().intersects(l1.sprite_e.getGlobalBounds())) {
			lifee = false;
		}
		if (sprite.getGlobalBounds().intersects(l2.sprite_e.getGlobalBounds())) {
			lifee = false;
		}
		if (sprite.getGlobalBounds().intersects(l3.sprite_e.getGlobalBounds())) {
			lifee = false;
		}
		if (sprite.getGlobalBounds().intersects(l4.sprite_e.getGlobalBounds())) {
			lifee = false;
		}
	}
	float getplayercoordinateX() {	//этим методом будем забирать координату Х	
		return x;
	}
	float getplayercoordinateY() {	//этим методом будем забирать координату Y 	
		return y;
	}


	void interactionWithMap(int dir)//ф-ция взаимодействия с картой
	{

		

		for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по тайликам, контактирующим с игроком,, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
			for (int j = x / 32; j < (x + w) / 32; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
			{
				if (TileMap[i][j] == '0' or TileMap[i][j] == 'z' or TileMap[i][j] == 'x' or TileMap[i][j] == 'c' or TileMap[i][j] == 'v' or TileMap[i][j] == 'q' or TileMap[i][j] == 'w' or TileMap[i][j] == 'e' or TileMap[i][j] == 'r' or TileMap[i][j] == '1' or TileMap[i][j] == '2' or TileMap[i][j] == '3' or TileMap[i][j] == '4' or TileMap[i][j] == 'i' or TileMap[i][j] == 'o' or TileMap[i][j] == 'k' or TileMap[i][j] == 'l' or TileMap[i][j] == 'h' or TileMap[i][j] == 'j' or TileMap[i][j] == 'n' or TileMap[i][j] == 'm' or TileMap[i][j] == '5')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
				{
					if ((dy > 0) && (dir == 1))//если мы шли вниз,
					{
						y = i * 32 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
					}
					if ((dy < 0) && (dir == 1))
					{
						y = i * 32 + 32;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
					}
					if ((dx > 0) && (dir == 0))
					{
						x = j * 32 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
					}
					if ((dx < 0) && (dir == 0))
					{
						x = j * 32 + 32;//аналогично идем влево
					}
				}
				if (TileMap[i][j] == 's')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
				{
					if ((dy > 0) && (dir == 1))//если мы шли вниз,
					{
						y = i * 32 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
					}
					if ((dy < 0) && (dir == 1))
					{
						y = i * 32 + 32;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
					}
					if ((dx > 0) && (dir == 0))
					{
						x = j * 32 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
					}
					if ((dx < 0) && (dir == 0))
					{
						x = j * 32 + 32;//аналогично идем влево
					}
				}
				if (TileMap[i][j] == '$' or TileMap[i][j] == '#' or TileMap[i][j] == '=') {
					TileMap[i][j] = ' ';
				}
			}
	}
};


//////////////////////////////////////////




void playMusic(sf::Music& music) {
	music.setLoop(true);
	music.play(); 
}

int main()
{




	Music music;
	music.openFromFile("Realm.wav");
	sf::Music sound;
	sound.openFromFile("SpaceDebris.wav");
	RenderWindow window(sf::VideoMode(640, 480), "Game");
	menu(window,sound,music);//вызов мен
	view.reset(sf::FloatRect(0, 0, 640, 480));//размер "вида" камеры при создании объекта вида камеры. (потом можем менять как хотим) Что то типа инициализации
	Image map_image;
	map_image.loadFromFile("caveH12.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);



	sf::Font font;
	font.loadFromFile("CyrilicOld.ttf");
	sf::Text text("", font, 20);
	text.setFillColor(Color::Black);

		
	Image quest_image;
	quest_image.loadFromFile("missionbg.jpg");
	quest_image.createMaskFromColor(Color(0, 0, 0));
	Texture quest_texture;
	quest_texture.loadFromImage(quest_image);
	Sprite s_quest;
	s_quest.setTexture(quest_texture);
	s_quest.setTextureRect(IntRect(0, 0, 340, 510));  //приведение типов, размеры картинки исходные
	s_quest.setScale(0.6f, 0.6f);//чуть уменьшили картинку, => размер стал меньше

	float CurrentFrame = 0;
	float CurrentFrames = 0;
	float CurrentFrameb = 0;
	float CF = 0;
	float CFb = 0;
	float CFl = 0;
	Texture  q;
	q.loadFromFile("bow.png");
	Sprite att;
	att.setTexture(q);
	Texture enemy_text;
	enemy_text.loadFromFile("123.png");
	Texture bulletTexture;
	bulletTexture.loadFromFile("Archer.png");
	Texture plantTexture;
	plantTexture.loadFromFile("plant.png");



	Player p("bow.png", 100, 100, 64, 64);
	Friend bald("bald.png", 1300, 150, 64, 64, 0, 128, 64, 64);
	Friend kid("kid.png", 1500, 150, 64, 64, 0,  64*9, 64, 64);
	Friend momk("mom.png", 525, 600, 64, 64, 0, 128, 64, 64);
	Enemy e("darksoldier.png", 500, 600, 64, 64, 500, 600, 600, 700);
	Enemy e1("darksoldier.png", 500, 650, 64, 64, 500, 650, 800, 750);
	Enemy b1("BoarWalk.png", 1800,  200 , 64, 64, 1800, 200, 2000, 400, 0.05);
	Enemy b2("BoarWalk.png", 1850, 350, 64, 64, 1850, 350, 2000, 550, 0.05);
	Enemy b3("BoarWalk.png", 2000, 100, 64, 64, 2000, 100, 2200, 600, 0.05);
	Enemy l1("log.png", 100, 2000, 64, 64, 100, 2000,2300, 2300);
	Enemy l2("log.png", 650, 2300, 64, 64, 650, 2000, 1200, 2300);
	Enemy l3("log.png", 1200, 2000, 64, 64, 1200, 2000, 2300, 1750);
	Enemy l4("log.png", 1750, 2300, 64, 64, 1750, 2000, 2200, 2300);
	Enemy king("king.png", 1900, 1320, 64, 64, 200, 1200, 250, 1250, 0);
	Friend s1("knight123.png", 1985, 1320, 64, 64, 0, 128, 64, 64);
	Friend s2("knight123.png", 2300, 1320, 64, 64, 0, 128, 64, 64);
	Friend s3("knight123.png", 1985, 1230, 64, 64, 0, 0, 64, 64);
	Friend s4("knight123.png", 1925, 1230, 64, 64, 0, 0, 64, 64);
	Friend s5("knight123.png", 1865, 1230, 64, 64, 0, 0, 64, 64);
	Friend s6("knight123.png", 2300, 1230, 64, 64, 0, 0, 64, 64);
	Friend s7("knight123.png", 2365, 1230, 64, 64, 0, 0, 64, 64);
	Friend s8("knight123.png", 2430, 1230, 64, 64, 0, 0, 64, 64);
	Enemy wolf("wolf.png", 200, 1200, 64, 64, 200, 1200, 250, 1250, 0);

	bool showMissionText = true;
	bool showDia = true;
	bool mom = false;
	bool wolf_dead = false;
	bool wolf_saved = false;
	Clock clock;

	std::vector<Bullet> bullets;
	vector<PlantsSpawner> plants;



	for (int i = 50; i < 2000; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 250 + rand() % 50, 2);
		plants.push_back(plant);

	}
	for (int i = 0; i < 2000; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 350 + rand() % 50, 2);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2000; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 450 + rand() % 50, 2);
		plants.push_back(plant);

	}
	for (int i = 0; i < 2000; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 550 + rand() % 50, 2);
		plants.push_back(plant);

	}
	for (int i = 0; i < 2000; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 650 + rand() % 50, 2);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2000; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 750 + rand() % 50, 2);
		plants.push_back(plant);

	}
	for (int i = 0; i < 2000; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 850 + rand() % 50, 2);
		plants.push_back(plant);

	}


	for (int i = 0; i < 2000; i+=100) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 300 + rand() % 50, 1);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2000; i += 100) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 400 + rand() % 50, 1);
		plants.push_back(plant);

	}
	for (int i = 0; i < 2000; i += 100) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 500 + rand() % 50, 1);
		plants.push_back(plant);

	}
	for (int i = 0; i < 2000; i += 100) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 600 + rand() % 50, 1);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2000; i += 100) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 700 + rand() % 50, 1);
		plants.push_back(plant);

	}
	for (int i = 0; i < 2000; i += 100) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 800 + rand() % 50, 1);
		plants.push_back(plant);

	}
	for (int i = 50; i < 800; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 1600 + rand() % 50, 3);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2600; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 1800 + rand() % 50, 3);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2600; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 1900 + rand() % 50, 3);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2600; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 2000 + rand() % 50, 3);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2600; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 2100 + rand() % 50, 3);
		plants.push_back(plant);

	}
	for (int i = 50; i < 2600; i += 150) {

		PlantsSpawner plant(plantTexture, i + rand() % 50, 2200 + rand() % 50, 3);
		plants.push_back(plant);

	}
	


	int progress = 0;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float times = clock.getElapsedTime().asSeconds();
		clock.restart();
		time = time / 800;
		sf::Event event;

		Level lvl;
		lvl.LoadFromFile("map.tmx");

		bool lookup = false, lookdown = false, lookleft=false, lookright=false;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)//событие нажатия клавиши
				if ((event.key.code == Keyboard::Tab)) {//если клавиша ТАБ
					switch (showMissionText) {//переключатель, реагирующий на логическую переменную showMissionText
					case true: {
						std::ostringstream task;//строка текста миссии
						task << getTextMission(getCurrentMission(progress));//вызывается функция getTextMission (она возвращает текст миссии), которая принимает в качестве аргумента функцию getCurrentMission(возвращающую номер миссии), а уже эта ф-ция принимает в качестве аргумента функцию p.getplayercoordinateX() (эта ф-ция возвращает Икс координату игрока)
						text.setString(task.str());
						showMissionText = false;//эта строка позволяет убрать все что мы вывели на экране
						break;//выходим , чтобы не выполнить условие "false" (которое ниже)
					}
					case false: {
						text.setString("");//если не нажата клавиша таб, то весь этот текст пустой
						showMissionText = true;// а эта строка позволяет снова нажать клавишу таб и получить вывод на экран
						break;
					}
					}
				}

			if (event.type == Event::KeyPressed)//событие нажатия клавиши
				if ((event.key.code == Keyboard::E)) {//если клавиша ТАБ
					switch (showDia) {//переключатель, реагирующий на логическую переменную showMissionText
					case true: {
						showDia = false;//эта строка позволяет убрать все что мы вывели на экране
						break;//выходим , чтобы не выполнить условие "false" (которое ниже)
					}
					case false: {
						showDia = true;// а эта строка позволяет снова нажать клавишу таб и получить вывод на экран
						break;
					}
					}
				}
		}


		////////////////////////////ENEMY AANIMATIONS///////////////////////////////////////////////

		
		CF += 0.005 * time;
		CFb += 0.005 * time;
		CFl += 0.005 * time;
		wolf.sprite_e.setTextureRect(IntRect(0,64*3, 64, 64));
		king.sprite_e.setTextureRect(IntRect(0, 64 *2, 64, 64));
		if (e.dy_e > 0) {
			if (CF > 6) CF -= 6;
			e.sprite_e.setTextureRect(IntRect(64 * int(CF), 0, 64, 64));
		}
		if (e.dy_e < 0) {
			if (CF > 6) CF -= 6;
			e.sprite_e.setTextureRect(IntRect(64 * int(CF),64, 64, 64));
		}
		if (e.dx_e > 0) {
			if (CF > 5) CF -= 5;
			e.sprite_e.setTextureRect(IntRect(64 * int(CF), 128, 64, 64));
		}
		if (e.dx_e < 0) {
			if (CF >5) CF -= 5;
			e.sprite_e.setTextureRect(IntRect(64 * int(CF), 192, 64, 64));
		}
		if (e1.dy_e > 0) {
			if (CF > 6) CF -= 6;
			e1.sprite_e.setTextureRect(IntRect(64 * int(CF), 0, 64, 64));
		}
		if (e1.dy_e < 0) {
			if (CF > 6) CF -= 6;
			e1.sprite_e.setTextureRect(IntRect(64 * int(CF), 64, 64, 64));
		}
		if (e1.dx_e > 0) {
			if (CF > 5) CF -= 5;
			e1.sprite_e.setTextureRect(IntRect(64 * int(CF), 128, 64, 64));
		}
		if (e1.dx_e < 0) {
			if (CF > 5) CF -= 5;
			e1.sprite_e.setTextureRect(IntRect(64 * int(CF), 192, 64, 64));
		}
		if (b1.dy_e > 0) {
			if (CFb > 3) CFb -= 3;
			b1.sprite_e.setTextureRect(IntRect(64 * int(CFb), 128, 64, 64));
		}
		if (b1.dy_e < 0) {
			if (CFb > 3) CFb -= 3;
			b1.sprite_e.setTextureRect(IntRect(64 * int(CFb), 0, 64, 64));
		}
		if (b1.dx_e > 0) {
			if (CFb > 3) CFb -= 3;
			b1.sprite_e.setTextureRect(IntRect(64 * int(CFb), 192, 64, 64));
		}
		if (b1.dx_e < 0) {
			if (CFb > 3) CFb -= 3;
			b1.sprite_e.setTextureRect(IntRect(64 * int(CFb), 64, 64, 64));
		}
		if (b2.dy_e > 0) {
			if (CFb > 3) CFb -= 3;
			b2.sprite_e.setTextureRect(IntRect(64 * int(CFb), 128, 64, 64));
		}
		if (b2.dy_e < 0) {
			if (CFb > 3) CFb -= 3;
			b2.sprite_e.setTextureRect(IntRect(64 * int(CFb), 0, 64, 64));
		}
		if (b2.dx_e > 0) {
			if (CFb > 3) CFb -= 3;
			b2.sprite_e.setTextureRect(IntRect(64 * int(CFb), 192, 64, 64));
		}
		if (b2.dx_e < 0) {
			if (CFb > 3) CFb -= 3;
			b2.sprite_e.setTextureRect(IntRect(64 * int(CFb), 64, 64, 64));
		}
		if (b3.dy_e > 0) {
			if (CFb > 3) CFb -= 3;
			b3.sprite_e.setTextureRect(IntRect(64 * int(CFb), 128, 64, 64));
		}
		if (b3.dy_e < 0) {
			if (CFb > 3) CFb -= 3;
			b3.sprite_e.setTextureRect(IntRect(64 * int(CFb), 0, 64, 64));
		}
		if (b3.dx_e > 0) {
			if (CFb > 3) CFb -= 3;
			b3.sprite_e.setTextureRect(IntRect(64 * int(CFb), 192, 64, 64));
		}
		if (b3.dx_e < 0) {
			if (CFb > 3) CFb -= 3;
			b3.sprite_e.setTextureRect(IntRect(64 * int(CFb), 64, 64, 64));
		}
		if (wolf.dy_e > 0) {
			if (CF > 6) CF -= 6;
			wolf.sprite_e.setTextureRect(IntRect(64 * int(CF), 64*10, 64, 64));
		}
		if (wolf.dy_e < 0) {
			if (CF > 6) CF -= 6;
			wolf.sprite_e.setTextureRect(IntRect(64 * int(CF), 64*8, 64, 64));
		}
		if (wolf.dx_e > 0) {
			if (CF > 6) CF -= 6;
			wolf.sprite_e.setTextureRect(IntRect(64 * int(CF), 64*11, 64, 64));
		}
		if (wolf.dx_e < 0) {
			if (CF >6) CF -= 6;
			wolf.sprite_e.setTextureRect(IntRect(64 * int(CF), 64*9, 64, 64));
		}
		if (l1.dy_e > 0) {
			if (CFl > 4) CFl -=4;
			l1.sprite_e.setTextureRect(IntRect(32 * int(CFl), 0, 32, 32));
		}
		if (l1.dy_e < 0) {
			if (CFl > 4) CFl -= 4;
			l1.sprite_e.setTextureRect(IntRect(32 * int(CFl),32, 32, 32));
		}
		if (l1.dx_e > 0) {
			if (CFl > 4) CFl -= 4;
			l1.sprite_e.setTextureRect(IntRect(32 * int(CFl), 64, 32,32));
		}
		if (l1.dx_e < 0) {
			if (CFl > 4) CFl -= 4;
			l1.sprite_e.setTextureRect(IntRect(32 * int(CFl), 94, 32, 32));
		}
		if (l2.dy_e > 0) {
			if (CFl > 4) CFl -= 4;
			l2.sprite_e.setTextureRect(IntRect(32 * int(CFl), 0, 32, 32));
		}
		if (l2.dy_e < 0) {
			if (CFl > 4) CFl -= 4;
			l2.sprite_e.setTextureRect(IntRect(32 * int(CFl), 32, 32, 32));
		}
		if (l2.dx_e > 0) {
			if (CFl > 4) CFl -= 4;
			l2.sprite_e.setTextureRect(IntRect(32 * int(CFl), 64, 32, 32));
		}
		if (l2.dx_e < 0) {
			if (CFl > 4) CFl -= 4;
			l2.sprite_e.setTextureRect(IntRect(32 * int(CFl), 94, 32, 32));
		}
		if (l3.dy_e > 0) {
			if (CFl > 4) CFl -= 4;
			l3.sprite_e.setTextureRect(IntRect(32 * int(CFl), 0, 32, 32));
		}
		if (l3.dy_e < 0) {
			if (CFl > 4) CFl -= 4;
			l3.sprite_e.setTextureRect(IntRect(32 * int(CFl), 32, 32, 32));
		}
		if (l3.dx_e > 0) {
			if (CFl > 4) CFl -= 4;
			l3.sprite_e.setTextureRect(IntRect(32 * int(CFl), 64, 32, 32));
		}
		if (l3.dx_e < 0) {
			if (CFl > 4) CFl -= 4;
			l3.sprite_e.setTextureRect(IntRect(32 * int(CFl), 94, 32, 32));
		}
		if (l4.dy_e > 0) {
			if (CFl > 4) CFl -= 4;
			l4.sprite_e.setTextureRect(IntRect(32 * int(CFl), 0, 32, 32));
		}
		if (l4.dy_e < 0) {
			if (CFl > 4) CFl -= 4;
			l4.sprite_e.setTextureRect(IntRect(32 * int(CFl), 32, 32, 32));
		}
		if (l4.dx_e > 0) {
			if (CFl > 4) CFl -= 4;
			l4.sprite_e.setTextureRect(IntRect(32 * int(CFl), 64, 32, 32));
		}
		if (l4.dx_e < 0) {
			if (CFl > 4) CFl -= 4;
			l4.sprite_e.setTextureRect(IntRect(32 * int(CFl), 94, 32, 32));
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			att.setTextureRect(IntRect(64 * int(CurrentFrame), 128, 64, 64));; // если нажата клавиша "пробел", запустить анимацию
			window.draw(att);
		}
		
	
		


		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////



		

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			p.dx = -0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 64*9, 64, 64));
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
			lookleft = true;
			lookup = false; lookdown = false; lookright = false;
			p.dy = 0;  //todel
		}
		else {
			p.dx = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			p.dx = 0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 7) CurrentFrame -= 7;
			p.sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 64*11, 64, 64));
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
			lookright = true;
			lookup = false; lookdown = false; lookleft = false;
			p.dy = 0; //todel

		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			p.dy = -0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 64*8, 64, 64));
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
			lookup = true;
			lookright = false; lookdown = false; lookleft = false; 
			p.dx = 0; //todel
		}
		else {
			p.dy = 0;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			p.dy = 0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 64*10, 64, 64));
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камеро
			lookdown = true;
			lookright = false; lookup = false; lookleft = false;
			p.dx = 0; //todel

		}
			

		
		
		

		if (Keyboard::isKeyPressed(Keyboard::Space) && lookright) {
			CurrentFrameb += 0.008 * time;
			p.dx = 0;
			p.dy = 0;
			p.sprite.setTextureRect(IntRect(64 * int(CurrentFrameb), 64 * 19, 64, 64));
			if (CurrentFrameb > 12) {

				Bullet bullet(bulletTexture, p.x, p.y - 48, 10, 0);
				bullet.sprite.setRotation(90);
				bullets.push_back(bullet);
				CurrentFrameb -= 12;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space) && lookleft) {
			CurrentFrameb += 0.008 * time;
			p.dx = 0;
			p.dy = 0;
			p.sprite.setTextureRect(IntRect(64 * int(CurrentFrameb), 64 * 17, 64, 64));
			if (CurrentFrameb > 12) {
				Bullet bullet(bulletTexture, p.x - 32, p.y - 32, -10, 0);
				bullet.sprite.setRotation(270);
				bullets.push_back(bullet);
				CurrentFrameb -= 12;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Space) && lookdown) {
			CurrentFrameb += 0.008 * time;
			p.dx = 0;
			p.dy = 0;
			p.sprite.setTextureRect(IntRect(64 * int(CurrentFrameb), 64 * 18, 64, 64));
			if (CurrentFrameb > 12) {

				Bullet bullet(bulletTexture, p.x-32, p.y - 32, 0,10);
				bullet.sprite.setRotation(180);
				bullets.push_back(bullet);
				CurrentFrameb -= 12;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Space) && lookup) {
			CurrentFrameb += 0.008 * time;
			p.dx = 0;
			p.dy = 0;
			p.sprite.setTextureRect(IntRect(64 * int(CurrentFrameb), 64 * 16, 64, 64));
			if (CurrentFrameb > 12) {
				Bullet bullet(bulletTexture, p.x - 48, p.y - 32, 0, -10);
				bullet.sprite.setRotation(0);
				bullets.push_back(bullet);
				CurrentFrameb -= 12;
			}
		}


		
		
	


		// Update the position of each bullet and draw it on the screen:
		
		p.update(time,e,e1, l1, l2,l3,l4);
		e.update(time,bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		e1.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		b1.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		b2.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		b3.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		l1.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		l2.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		l3.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		l4.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		wolf.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());
		king.update(time, bullets, p.getplayercoordinateX(), p.getplayercoordinateY());

		if (Keyboard::isKeyPressed(Keyboard::R) ){
			p.x = 100;
			p.y = 100;
			p.lifee = true;
		}

	





		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			menu3(window, sound, music);//вызов мен
		}
	
		

		if (wolf.getplayercoordinateX_f() < 100 and wolf.getplayercoordinateY_f() < 100) {
			wolf.speed_e = 0;
			wolf_saved = true;
			wolf.sprite_e.setPosition(-100, 100);
		}
		
		
		window.setView(view);//"оживляем" камеру в окне sfml
		window.clear();
		/////////////////////////////Рисуем карту/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(740, 40, 32, 32));
				if ((TileMap[i][j] == '5')) s_map.setTextureRect(IntRect(393, 107, 64, 64));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(144, 112, 64, 64));
				if (TileMap[i][j] == 'z')  s_map.setTextureRect(IntRect(675, 515, 32, 32));
				if (TileMap[i][j] == 'x')  s_map.setTextureRect(IntRect(675 +32, 515, 32, 32));
				if (TileMap[i][j] == 'c')  s_map.setTextureRect(IntRect(675 + 64, 515, 32, 32));
				if (TileMap[i][j] == 'v')  s_map.setTextureRect(IntRect(675 +96, 515, 32, 32));
				if (TileMap[i][j] == 'a')  s_map.setTextureRect(IntRect(675, 515+32, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(675+32, 515 + 32, 32, 32));
				if (TileMap[i][j] == 'd')  s_map.setTextureRect(IntRect(675+64, 515 + 32, 32, 32));
				if (TileMap[i][j] == 'f')  s_map.setTextureRect(IntRect(675+96, 515 + 32, 32, 32));
				if (TileMap[i][j] == 'q')  s_map.setTextureRect(IntRect(675, 515 + 64, 32, 32));
				if (TileMap[i][j] == 'w')  s_map.setTextureRect(IntRect(675+32, 515 + 64, 32, 32));
				if (TileMap[i][j] == 'e')  s_map.setTextureRect(IntRect(675+64, 515 + 64, 32, 32));
				if (TileMap[i][j] == 'r')  s_map.setTextureRect(IntRect(675+96, 515 + 64, 32, 32));
				if (TileMap[i][j] == '1')  s_map.setTextureRect(IntRect(675, 515 + 96, 32, 32));
				if (TileMap[i][j] == '2')  s_map.setTextureRect(IntRect(675 + 32, 515 + 96, 32, 32));
				if (TileMap[i][j] == '3')  s_map.setTextureRect(IntRect(675 + 64, 515 + 96, 32, 32));
				if (TileMap[i][j] == '4')  s_map.setTextureRect(IntRect(675 + 96, 515 + 96, 32, 32));
				if (TileMap[i][j] == '7')  s_map.setTextureRect(IntRect(610 , 479 , 32, 32));
				if (TileMap[i][j] == '8')  s_map.setTextureRect(IntRect(512 , 256, 32, 32));
				if (TileMap[i][j] == '9')  s_map.setTextureRect(IntRect(833, 446, 32, 32));
				if (TileMap[i][j] == 'h')  s_map.setTextureRect(IntRect(1108, 600,64, 64));
				if (TileMap[i][j] == 'j')  s_map.setTextureRect(IntRect(1108+32, 600, 64, 64));
				if (TileMap[i][j] == 'n')  s_map.setTextureRect(IntRect(1108, 600+32, 64, 64));
				if (TileMap[i][j] == 'm')  s_map.setTextureRect(IntRect(1108+32, 600+32, 64, 64));
				if (TileMap[i][j] == 'i')  s_map.setTextureRect(IntRect(1116, 514, 64, 64));
				if (TileMap[i][j] == 'o')  s_map.setTextureRect(IntRect(1116 + 32, 514, 64, 64));
				if (TileMap[i][j] == 'k')  s_map.setTextureRect(IntRect(1116, 514 + 32, 64, 64));
				if (TileMap[i][j] == 'l')  s_map.setTextureRect(IntRect(1116 + 32, 514 + 32, 64, 64));
				if (TileMap[i][j] == 'p')  s_map.setTextureRect(IntRect(940, 832, 64, 64));
				if (TileMap[i][j] == '?')  s_map.setTextureRect(IntRect(0, 284, 64, 64));
				if (TileMap[i][j] == '+')  s_map.setTextureRect(IntRect(777, 80 , 64, 64));
				if (TileMap[i][j] == '-')  s_map.setTextureRect(IntRect(867, 206, 64, 64));
				if (TileMap[i][j] == '#')  s_map.setTextureRect(IntRect(582, 44, 64, 64));
				if (TileMap[i][j] == '=')  s_map.setTextureRect(IntRect(550, 44, 64, 64));
				if (TileMap[i][j] == '$')  s_map.setTextureRect(IntRect(518, 44, 64, 64));
				s_map.setPosition(j * 32, i * 32);
				window.draw(s_map);
			}

		
	
		if ((p.x > 1100) && (p.x < 1400) && (p.y < 400)) {

			if (showDia == false and b1.life == true and b2.life == true and b3.life == true) {

				bald_dia(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
				progress = 1;
				showDia = true;
			}
			

		else if (b1.life == false and b2.life == false and b3.life == false and showDia == false) {

			bald_dia2(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
			showDia = true;

		
		}
		else { showDia = true; }
		}


		if ((p.x > 1500) && (p.x < 1700) && (p.y < 400)) {
			if (showDia == false and mom == false) {

				kid_dia(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
				showDia = true;
			}
			else if (showDia == false and mom == true) {
				mom_dia2(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
				showDia = true;
			}
			else {showDia = true;}
		}

		
			
		if ((p.x > 475) && (p.x < 575) && (p.y < 650) && (p.y > 550)) {
			if (showDia == false and mom == false) {

				mom_dia(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
				showDia = true;
				mom = true;
				momk.sprite_e.setPosition(1600, 150);
			}
			else { showDia = true; }
		}




		if ((p.x > 1850) && (p.x < 1950) && (p.y > 1200) && (p.y < 1400)) {
			if (showDia == false ) {
				if (wolf_saved == false and wolf.life == true) {
					king_dia(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
					showDia = true;
				}
				else if (wolf_saved == true and wolf.life == true) {
					king_dia2(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
					showDia = true;
				}
				else if (wolf.life == false) {
					king_dia3(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
					showDia = true;
				}
			}
			else { showDia = true; }
		}

		if ((p.x > 150) && (p.x < 300) && (p.y > 1150) && (p.y < 1300)) {
			if (showDia == false and wolf.life == true) {
				wolf_dia(window, font, showDia, p.getplayercoordinateX(), p.getplayercoordinateY());
				wolf.speed_e = 0.05;
				showDia = true;
			}
			else { showDia = true; }
		}

		if (king.life == false) {
			menuend1(window, font, music);//вызов мен
		}

		if ((l1.life == false) && (l2.life == false)&& (l3.life == false) && (l4.life == false)) {
			menuend2(window, font, music);//вызов мен
		}

		


	
		

		window.draw(bald.sprite_e);
		window.draw(kid.sprite_e);
		window.draw(momk.sprite_e);
		window.draw(king.sprite_e);
		window.draw(s1.sprite_e);
		window.draw(s2.sprite_e);
		window.draw(s3.sprite_e);
		window.draw(s4.sprite_e);
		window.draw(s5.sprite_e);
		window.draw(s6.sprite_e);
		window.draw(s7.sprite_e); 
		window.draw(s8.sprite_e);
		window.draw(wolf.sprite_e);
		window.draw(p.sprite);
		window.draw(e.sprite_e);
		window.draw(e1.sprite_e);
		window.draw(b1.sprite_e);
		window.draw(b2.sprite_e);
		window.draw(b3.sprite_e);
		window.draw(l1.sprite_e);
		window.draw(l2.sprite_e);
		window.draw(l3.sprite_e);
		window.draw(l4.sprite_e);

		for (int i = 0; i < bullets.size(); i++) {
			bullets[i].x += bullets[i].dx;
			bullets[i].y += bullets[i].dy;
			bullets[i].sprite.setPosition(bullets[i].x, bullets[i].y);
			window.draw(bullets[i].sprite);
		}
		for (int i = 0; i < plants.size(); i++) {
			plants[i].sprite.setPosition(plants[i].x, plants[i].y);
			window.draw(plants[i].sprite);
		}
		if (!showMissionText) {
			text.setPosition(view.getCenter().x + 125, view.getCenter().y - 130);//позиция всего этого текстового блока
			s_quest.setPosition(view.getCenter().x + 115, view.getCenter().y - 130);//позиция фона для блока			
			window.draw(s_quest); window.draw(text); //рисуем спрайт свитка (фон для текста миссии). а затем и текст. все это завязано на логическую переменную, которая меняет свое состояние от нажатия клавиши ТАБ
		}

		window.display();

		

	}
}