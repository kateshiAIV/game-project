
///////////////////////////////////����� ������//////////////////////////////////
int getCurrentMission(int x)//�-��� ������ ������, ������� ������ ����� ������, � ����������� �� ���������� ������ � (���� ����� ���������� ��� ����������)
{
	int mission = 0;
	if (x == 1   ) { mission = 1; } //����� �� ������ ������
	if (x > 1400) { mission = 2; }//2��
	if (x > 150) { mission = 3; }//2��

	return mission;//�-��� ���������� ����� ������
}



/////////////////////////////////////����� ������/////////////////////////////////
std::string getTextMission(int currentMission) {

	std::string missionText = "";//����� ������ � ��� �������������

	switch (currentMission)//����������� ����� ������ � � ����������� �� ���� ���������� missionText ������������� ��������� �����
	{
	case 0: missionText = ""; break;
	case 1: missionText = "\nBaldur, asked me to \nkill boars to feed\nthe village. \nBoars must be \nnearby.\nThree have to \nbe enouth" ; break;
	case 2: missionText = "\nMission 2\n I was glad to see\n my old friend\n,but something worri-\nes me about him.\n I need to get to the\n castle and find\n out what is\n  happening "; break;
	case 3: missionText = "\nLord: Ryuk, you are \nfinnaly arrived \nMagician: why did you \n summon me? \nLord: I had no choice! \n Something terrorize \n my \nlands! There are dark \n knights around the \ncave on the west\n HELP US!!! \n(Space to summon \nthe fireball) "; break;
	}

	return missionText;//�-��� ���������� �����
};
