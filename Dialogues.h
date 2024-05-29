void bald_dia(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: Hello, My dear friend! I would like to meet you under better circumstances.", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: Hello, What happened?", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: Hello, I'm sorry i have no time for this.", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 1;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 3;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 4;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: Dark times have come, our village is starving.");  text5.setString("Y: How can I help you?"); text6.setString("Y: Did someone die already?"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("i am glad to see you, fu iamm nott  baaldd"); text5.setString("answ22"); text6.setString("answ22"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("I saw a herd of wild boars to the east, could you kill some of them and bring their meat?"); text8.setString("Y: Ok. keep an eye oon village.");  text9.setString("Y: I can't."); }
			if (menuNum == 4) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("N: Not yet, I saw a herd oof boars to  the east, their meet could help uss a lot"); text8.setString("Y: Ok. keep an eye oon village."); text9.setString("Y: No time for hunt."); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);


		window.display();
	}
	////////////////////////////////////////////////////
}

void bald_dia2(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: Thank you! That helped us a lot!", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: ...", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: (Leave the meet with you)", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 1;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 3;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 4;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: By the way, a bird flew in with a message from the governor. He needs help. ");  text5.setString("Y: Where can i find him?"); text6.setString("Y: Who is governor?"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("i am glad to see you, fu iamm nott  baaldd"); text5.setString("answ22"); text6.setString("answ22"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("N: Just follow the road, it leads to White Tower"); text8.setString("Y: (I Should chech it)");  text9.setString("Y: No, Thanks."); }
			if (menuNum == 4) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("N: Sir Arthas! He wants the best for local lands, you should meet him"); text8.setString("Y: Ok."); text9.setString("Y: No."); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);


		window.display();
	}
	////////////////////////////////////////////////////
}

void kid_dia(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: Hello, Sir! Can you help my mom?", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: What happened to yoour mom?", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: No.", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 1;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 3;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 4;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: She  went to forest a day ago and didn't come back, please find her!");  text5.setString("Y: Why did she go there?"); text6.setString("Y: How does she look?"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("i am glad to see you, fu iamm nott  baaldd"); text5.setString("answ22"); text6.setString("answ22"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("N: We have nothing to eat, she went for food"); text8.setString("Y: Ok. I  will bring her back.");  text9.setString("Y: I can't."); }
			if (menuNum == 4) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("N: She has brown hair and she is verry beautiful!"); text8.setString("Y: Ok. I  will bring her back."); text9.setString("Y: No time for that."); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);


		window.display();
	}
	////////////////////////////////////////////////////
}

void mom_dia(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: Thank you! I was looking for berries than they kidnaped me.", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: Your son  told me you lost in the forest.", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: ...", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 1;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: My boy! Thanks god he meet you");  text5.setString("Y: Go to your son now"); text6.setString("Y: ..."); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("i am glad to see you, fu iamm nott  baaldd"); text5.setString("answ22"); text6.setString("answ22"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("We have nothing to eat, she went for food"); text8.setString("Ok. I  will bring her back.");  text9.setString("I can't."); }
			if (menuNum == 4) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("She has brown hair and she is verry beautiful!"); text8.setString("Ok. I  will bring her back."); text9.setString("No time for that."); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);


		window.display();
	}
	////////////////////////////////////////////////////
}

void mom_dia2(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: We are so happy. Thank  you", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: ...", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: ...", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: My boy! Thanks god he meet you");  text5.setString("Y: Go to your son now"); text6.setString("Y: ..."); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("i am glad to see you, fu iamm nott  baaldd"); text5.setString("answ22"); text6.setString("answ22"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("N: We have nothing to eat, she went for food"); text8.setString("Y: Ok. I  will bring her back.");  text9.setString("Y: I can't."); }
			if (menuNum == 4) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("N: She has brown hair and she is verry beautiful!"); text8.setString("Y: Ok. I  will bring her back."); text9.setString("Y: No time for that."); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);


		window.display();
	}
	////////////////////////////////////////////////////
}

void king_dia(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: ...", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: Glad to see you, sir! I heard that you need help! ", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: ...", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 1;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 3;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 4;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: Who the fuck let this freak come in?!!?!? Are you able to kill something?");  text5.setString("Y: Yeah, I am"); text6.setString("Y: Whom do you want me to kill?"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("i am glad to see you, fu iamm nott  baaldd"); text5.setString("answ22"); text6.setString("answ22"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("N: Ok,  then there is a wolf in a cave on the west, bring me his head"); text8.setString("Y: Ok.");  text9.setString("Y: No, Thanks."); }
			if (menuNum == 4) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("N: Wofl which hunts on our people! It  lives on the west"); text8.setString("Y: I will catch him"); text9.setString("Y: Not my business"); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);


		window.display();
	}
	////////////////////////////////////////////////////
}

void wolf_dia(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: ''groans in pain'' Please, Hunter, listen to me.", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: (It's not just a wolf) W-Why Should i listen to you? ", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: Innocent people have died because of creatures like you.", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 1;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 3;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: I swear to you, I didn't choose this curse. If help me to get out...");  text5.setString("Y: Why should I trust you?"); text6.setString("Y: I don't belive you!"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("i am glad to see you, fu iamm nott  baaldd"); text5.setString("answ22"); text6.setString("answ22"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("N: I understand your doubts, but I don't have much time..."); text8.setString("Y: (Help a werwolf)");  text9.setString("Y: (Kill a werwolf)"); }
			if (menuNum == 4) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("N: Thank you, Hunter. Help me to get out of this lands"); text8.setString("Y: ..."); text9.setString("Y: ..."); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);


		window.display();
	}
	////////////////////////////////////////////////////
}

void king_dia2(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: Finally you came back! Where is wolf's head?!", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: You didn't mention it was a werwolf ", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: I lost it.(lie)", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);

	Text text10("", font, 15);
	text10.setFillColor(Color::Black);
	text10.setPosition(view.getCenter().x - 300, view.getCenter().y - 40);
	Text text11("", font, 15);
	text11.setFillColor(Color::Black);
	text11.setPosition(view.getCenter().x - 300, view.getCenter().y - 20);
	Text text12("", font, 15);
	text12.setFillColor(Color::Black);
	text12.setPosition(view.getCenter().x - 300, view.getCenter().y);


	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 1;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 2;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 3;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 4;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}

		else if (IntRect(20, 220, 120, 15).contains(Mouse::getPosition(window)))
		{
			text11.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 240, 120, 15).contains(Mouse::getPosition(window)))
		{
			text12.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
			text11.setFillColor(Color::Black);
			text12.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: What's the difference? Anyway did you kill him?");  text5.setString("Y: Yes, I did (lie)"); text6.setString("Y: I helped him to get out."); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("N: NICE!!! Anyway i will find out if you are lying."); text5.setString("Y: What's next?"); text6.setString("Y: ..."); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("N: NICE!!! Anyway i will find out if you are lying. "); text8.setString("Y: What's next?");  text9.setString("Y: ..."); }
			if (menuNum == 4) { text8.setFillColor(Color::Green); text9.setFillColor(Color::Red); text10.setString("N: Go to Rogh mount and kill the Golem which lives there"); text11.setString("Y: Ok."); text12.setString("Y: Later."); }
			if (menuNum == 5) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("N: Go to Rogh mount and kill the Golem which lives there"); text8.setString("Y: Ok."); text9.setString("Y: Later."); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);
		window.draw(text10);
		window.draw(text11);
		window.draw(text12);

		window.display();
	}
	////////////////////////////////////////////////////
}

void king_dia3(RenderWindow& window, Font font, bool showDia, int x, int y) {
	Texture  menuTexture3, aboutTexture, menuBackground;
	menuTexture3.loadFromFile("exit1.png");
	menuBackground.loadFromFile("bgdia.png");
	Sprite menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool answer = true;
	sf::Event event1;
	menu3.setPosition(view.getCenter().x + 240, view.getCenter().y + 160);
	menuBg.setPosition(view.getCenter().x - 320, view.getCenter().y - 240);
	Text text1("N: Finally you came back! Where is wolf's head?!", font, 15);
	text1.setFillColor(Color::Black);
	text1.setPosition(view.getCenter().x - 300, view.getCenter().y - 220);
	Text text2("Y: (Show the head)", font, 15);
	text2.setFillColor(Color::Black);
	text2.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);
	Text text3("Y: ...", font, 15);
	text3.setFillColor(Color::Black);
	text3.setPosition(view.getCenter().x - 300, view.getCenter().y - 180);
	Text text4("", font, 15);
	text4.setFillColor(Color::Black);
	text4.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);
	Text text5("", font, 15);
	text5.setFillColor(Color::Black);
	text5.setPosition(view.getCenter().x - 300, view.getCenter().y - 140);
	Text text6("", font, 15);
	text6.setFillColor(Color::Black);
	text6.setPosition(view.getCenter().x - 300, view.getCenter().y - 120);
	Text text7("", font, 15);
	text7.setFillColor(Color::Black);
	text7.setPosition(view.getCenter().x - 300, view.getCenter().y - 100);
	Text text8("", font, 15);
	text8.setFillColor(Color::Black);
	text8.setPosition(view.getCenter().x - 300, view.getCenter().y - 80);
	Text text9("", font, 15);
	text9.setFillColor(Color::Black);
	text9.setPosition(view.getCenter().x - 300, view.getCenter().y - 60);



	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{


		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(560, 400, 60, 60).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 9; }


		if (IntRect(20, 40, 150, 15).contains(Mouse::getPosition(window)))
		{
			text2.setFillColor(Color::White);
			menuNum = 1;
		}
		else if (IntRect(20, 60, 240, 15).contains(Mouse::getPosition(window)))
		{
			text3.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 100, 130, 15).contains(Mouse::getPosition(window)))
		{
			text5.setFillColor(Color::White);
			menuNum = 3;
		}
		else if (IntRect(20, 120, 160, 15).contains(Mouse::getPosition(window)))
		{
			text6.setFillColor(Color::White);
			menuNum = 4;
		}
		else if (IntRect(20, 160, 160, 15).contains(Mouse::getPosition(window)))
		{
			text8.setFillColor(Color::White);
			menuNum = 9;
		}
		else if (IntRect(20, 180, 120, 15).contains(Mouse::getPosition(window)))
		{
			text9.setFillColor(Color::White);
			menuNum = 9;
		}


		else
		{
			text3.setFillColor(Color::Black);
			text2.setFillColor(Color::Black);
			text5.setFillColor(Color::Black);
			text6.setFillColor(Color::Black);
			text8.setFillColor(Color::Black);
			text9.setFillColor(Color::Black);
		}







		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { text2.setFillColor(Color::Green); text3.setFillColor(Color::Red); text4.setString("N: Nice, you proved you can be useful. ");  text5.setString("Y: What's next?"); text6.setString("Y: He spoke too me..."); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { text2.setFillColor(Color::Red); text3.setFillColor(Color::Green);  text4.setString("i am glad to see you, fu iamm nott  baaldd"); text5.setString("answ22"); text6.setString("answ22"); }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { text5.setFillColor(Color::Green); text6.setFillColor(Color::Red); text7.setString("N: I want you kill trents in cursed forest"); text8.setString("Y: Ok.");  text9.setString("Y: No, Thanks."); }
			if (menuNum == 4) { text6.setFillColor(Color::Green); text5.setFillColor(Color::Red); text7.setString("N: A lot of people died because of that creature"); text8.setString("Y: Yeah, i made a right decision"); text9.setString("Y: ..."); }
			if (menuNum == 9) { showDia = true; isMenu = false; }

		}



		window.draw(menuBg);
		window.draw(menu3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text9);


		window.display();
	}
	////////////////////////////////////////////////////
}