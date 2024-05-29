void menu(RenderWindow& window, sf::Music& sound, sf::Music& music) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("start1.png");
	menuTexture2.loadFromFile("menu1.png");
	menuTexture3.loadFromFile("exit1.png");
	aboutTexture.loadFromFile("background2.png");
	menuBackground.loadFromFile("background.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(200, 240);
	menu2.setPosition(280, 240);
	menu3.setPosition(360, 240);
	menuBg.setPosition(0, 0);

	sound.play();
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(200, 240, 60, 60).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(280, 240, 60, 60).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(360, 240, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	music.play();
	sound.stop();
	////////////////////////////////////////////////////
}
void menu3(RenderWindow& window, sf::Music& sound, sf::Music& music) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("start1.png");
	menuTexture2.loadFromFile("menu1.png");
	menuTexture3.loadFromFile("exit1.png");
	aboutTexture.loadFromFile("background2.png");
	menuBackground.loadFromFile("background.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(view.getCenter().x - 110, view.getCenter().y );
	menu2.setPosition(view.getCenter().x - 30, view.getCenter().y );
	menu3.setPosition(view.getCenter().x + 50, view.getCenter().y );
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);

	sound.play();
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(200, 240, 60, 60).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(280, 240, 60, 60).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(360, 240, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	music.play();
	sound.stop();
	////////////////////////////////////////////////////
}
void menuend1(RenderWindow& window, Font font, sf::Music& music) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("end1.png");
	Text text("After the murder of the king, you fled the kingdom, ",font,25);
	Text text1("but rumors of the atrocities committed by ", font, 25);
	Text text2("the monsters from those lands still reach you.", font, 25);
	Sprite  menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;

	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	text.setPosition(view.getCenter().x - 250, view.getCenter().y - 110);
	text1.setPosition(view.getCenter().x - 250, view.getCenter().y - 75);
	text2.setPosition(view.getCenter().x - 250, view.getCenter().y - 40);
	text.setFillColor(Color::Black);
	text1.setFillColor(Color::Black);
	text2.setFillColor(Color::Black);


	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text);
		window.draw(text1);
		window.draw(text2);
		window.display();
	}

	////////////////////////////////////////////////////
}
void menuend2(RenderWindow& window, Font font, sf::Music& music) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("end2.png");
	Text text("You helped the king rid the land of monsters, ", font, 25);
	Text text1(" which led to the dawn of humanity.", font, 25);
	Sprite  menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;

	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	text.setPosition(view.getCenter().x - 250, view.getCenter().y - 110);
	text1.setPosition(view.getCenter().x - 250, view.getCenter().y - 75);
	text.setFillColor(Color::White);
	text1.setFillColor(Color::White);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text);
		window.draw(text1);
		window.display();
	}

	////////////////////////////////////////////////////
}



