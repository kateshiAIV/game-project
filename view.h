#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;//�������� sfml ������ "���", ������� � �������� �������

void getplayercoordinateforview(float x, float y) { //������� ��� ���������� ��������� ������
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����

		if (x < 320) tempX = 320;//������� �� ���� ����� �������
		if (x > 2172) tempX = 2172;//������� �� ���� ����� �������
		if (y < 240) tempY = 240;//������� �������
		if (y > 2160) tempY = 2160;//������ �������

	view.setCenter(tempX, tempY); //������ �� �������, ��������� ��� ����������. 

}
