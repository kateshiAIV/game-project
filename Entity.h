

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include <iostream>
#include <sstream>
#include "mission.h"
#include "iostream"
#include "level.h"
#include <vector>
#include <list>
#include "TinyXML/tinyxml.h"
#include "mapchanger.h"




class Fire {

public:
	float x_f, y_f;
	float w_f, h_f, dx_f, dy_f, speed_f;
	int dir = 0;
	FloatRect rect_f;
	String File_f;
	Image image_f;
	Texture texture_f;
	Sprite sprite_f;

	Fire(String F, float X, float Y, float W, float H) {
		dx_f = 0; dy_f = 0; speed_f = 0;
		File_f = F;
		w_f = W; h_f = H;
		image_f.loadFromFile(File_f);
		image_f.createMaskFromColor(Color(41, 33, 59));
		texture_f.loadFromImage(image_f);
		sprite_f.setTexture(texture_f);
		x_f = X; y_f = Y;
		sprite_f.setTextureRect(IntRect(0, 0, 64, 64));
	}
	void update(float time)
	{

		x_f += dx_f * time;
		y_f += dy_f * time;

		speed_f = 0;
		sprite_f.setPosition(x_f, y_f);
	}
	float getplayercoordinateX_f() {	//���� ������� ����� �������� ���������� �	
		return x_f;
	}
	float getplayercoordinateY_f() {	//���� ������� ����� �������� ���������� Y 	
		return y_f;
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

	Enemy(String F, float X, float Y, float W, float H, float x1, float y1, float x2, float y2) {
		dx_e = 0; dy_e = 0; speed_e = 0.05;
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
	void update(float time, Fire& f)
	{

		if (life) {
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

			// update sprite position
			sprite_e.setPosition(x_e, y_e);
		}
		if (sprite_e.getGlobalBounds().intersects(f.sprite_f.getGlobalBounds())) {
			sprite_e.setPosition(-100, -100);
			life = false;
		}
	}
	float getplayercoordinateX_f() {	//���� ������� ����� �������� ���������� �	
		return x_e;
	}
	float getplayercoordinateY_f() {	//���� ������� ����� �������� ���������� Y 	
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
	Texture texture;
	Sprite sprite;
	bool lifee = true;

	Player(String F, float X, float Y, float W, float H) {
		dx = 0; dy = 0; speed = 0;
		File = F;
		w = W; h = H;
		image.loadFromFile(File);
		image.createMaskFromColor(Color(41, 33, 59));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 128, 64, 64));
	}
	void update(float time, Enemy& e)
	{

		if (lifee) {
			x += dx * time;
			y += dy * time;
		}
		interactionWithMap(0);//�������� �������, ���������� �� �������������� � ������
		interactionWithMap(1);//�������� �������, ���������� �� �������������� � ������

		speed = 0;
		sprite.setPosition(x, y);

		if (sprite.getGlobalBounds().intersects(e.sprite_e.getGlobalBounds())) {
			lifee = false;
		}
	}
	float getplayercoordinateX() {	//���� ������� ����� �������� ���������� �	
		return x;
	}
	float getplayercoordinateY() {	//���� ������� ����� �������� ���������� Y 	
		return y;
	}
	void interactionWithMap(int dir)//�-��� �������������� � ������
	{

		for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������, �������������� � �������,, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
			for (int j = x / 32; j < (x + w) / 32; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
			{
				if (TileMap[i][j] == '0' or TileMap[i][j] == 'z' or TileMap[i][j] == 'x' or TileMap[i][j] == 'c' or TileMap[i][j] == 'v' or TileMap[i][j] == 'q' or TileMap[i][j] == 'w' or TileMap[i][j] == 'e' or TileMap[i][j] == 'r' or TileMap[i][j] == '1' or TileMap[i][j] == '2' or TileMap[i][j] == '3' or TileMap[i][j] == '4' or TileMap[i][j] == 'i' or TileMap[i][j] == 'o' or TileMap[i][j] == 'k' or TileMap[i][j] == 'l' or TileMap[i][j] == 'h' or TileMap[i][j] == 'j' or TileMap[i][j] == 'n' or TileMap[i][j] == 'm' or TileMap[i][j] == '5')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
				{
					if ((dy > 0) && (dir == 1))//���� �� ��� ����,
					{
						y = i * 32 - h;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
					}
					if ((dy < 0) && (dir == 1))
					{
						y = i * 32 + 32;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
					}
					if ((dx > 0) && (dir == 0))
					{
						x = j * 32 - w;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
					}
					if ((dx < 0) && (dir == 0))
					{
						x = j * 32 + 32;//���������� ���� �����
					}
				}
				if (TileMap[i][j] == 's')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
				{
					if ((dy > 0) && (dir == 1))//���� �� ��� ����,
					{
						y = i * 32 - h;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
					}
					if ((dy < 0) && (dir == 1))
					{
						y = i * 32 + 32;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
					}
					if ((dx > 0) && (dir == 0))
					{
						x = j * 32 - w;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
					}
					if ((dx < 0) && (dir == 0))
					{
						x = j * 32 + 32;//���������� ���� �����
					}
				}
			}
	}
};


