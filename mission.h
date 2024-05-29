
///////////////////////////////////НОМЕР МИССИИ//////////////////////////////////
int getCurrentMission(int x)//ф-ция номера миссия, которая меняет номер миссии, в зависимости от координаты игрока Х (сюда будем передавать эту координату)
{
	int mission = 0;
	if (x == 1   ) { mission = 1; } //игрок на первой миссии
	if (x > 1400) { mission = 2; }//2ой
	if (x > 150) { mission = 3; }//2ой

	return mission;//ф-ция возвращает номер миссии
}



/////////////////////////////////////ТЕКСТ МИССИИ/////////////////////////////////
std::string getTextMission(int currentMission) {

	std::string missionText = "";//текст миссии и его инициализация

	switch (currentMission)//принимается номер миссии и в зависимости от него переменной missionText присваивается различный текст
	{
	case 0: missionText = ""; break;
	case 1: missionText = "\nBaldur, asked me to \nkill boars to feed\nthe village. \nBoars must be \nnearby.\nThree have to \nbe enouth" ; break;
	case 2: missionText = "\nMission 2\n I was glad to see\n my old friend\n,but something worri-\nes me about him.\n I need to get to the\n castle and find\n out what is\n  happening "; break;
	case 3: missionText = "\nLord: Ryuk, you are \nfinnaly arrived \nMagician: why did you \n summon me? \nLord: I had no choice! \n Something terrorize \n my \nlands! There are dark \n knights around the \ncave on the west\n HELP US!!! \n(Space to summon \nthe fireball) "; break;
	}

	return missionText;//ф-ция возвращает текст
};
