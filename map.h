#pragma once
#include "Card.h"


class map
{
private:
	bool new_card;
	int pointClient;
	int pointKrupe;
	int clientW;
	int clientH;
	int krupeW;
	int krupeH;
	char** mas;
	
public:
	map()
	{
		new_card = false;
		pointClient = 0;
		pointKrupe = 0;
		mas = new char*[30];
		for (size_t i = 0; i < 30; i++)
		{
			mas[i] = new char[120];
		}
		clientW = 0;
		clientH = 0;
		krupeW =65;
		krupeH =0;
		for (size_t i = 0; i < 30; i++)
		{
			for (size_t k = 0; k < 120; k++)
			{
				if (k == 60)
				{
					mas[i][k] = '|';
					continue;
				}
				mas[i][k] = ' ';
			}
		}
	}
	void addNewCardClient()
	{
		if (getNewCard())
		{
			Card card;
			char** masCard = card.getCard();
			clientW += 3;
			clientH += 2;
			pointClient += card.getPoint();

			for (size_t i = 0; i < 10; i++)
			{
				for (size_t k = 0; k < 11; k++)
				{
					mas[i + clientW][k + clientH] = masCard[i][k];
				}
			}
		}
		new_card = false;
	}
	void addNewCardKrupe()
	{
		if (getNewCard())
		{
			Card card;
			krupeW += 3;
			krupeH += 2;
			pointKrupe += card.getPoint();

			char** masCard = card.getCard();
			for (size_t i = 0; i < 10; i++)
			{
				for (size_t k = 0; k < 11; k++)
				{
					mas[i + krupeH][k + krupeW] = masCard[i][k];
				}
			}
		}
		new_card = false;

	}
	void printMap()
	{
		mas[1][3] = 'È';
		mas[1][4] = 'ã';
		mas[1][5] = 'ð';
		mas[1][6] = 'î';
		mas[1][7] = 'ê';
		mas[1][8] = ':';
		if (pointClient > 9)
		{
			int second = pointClient % 10;
			int first = (pointClient - second) / 10;
			mas[1][9] = first + '0';
			mas[1][10] = second + '0';
		}
		else if (pointClient < 10)
		{			
			mas[1][9] = pointClient + '0';
		}
	 
		
		mas[1][33] = 'Ê';
		mas[1][34] = 'ð';
		mas[1][35] = 'ó';
		mas[1][36] = 'ï';
		mas[1][37] = 'ü';
		mas[1][38] = 'å';
		mas[1][39] = ':';
		if (pointKrupe > 9)
		{
			int second = pointKrupe % 10;
			int first = (pointKrupe - second) / 10;
			mas[1][40] = first + '0';
			mas[1][41] = second + '0';
		}
		else if(pointKrupe < 10)
		{
			mas[1][40] = pointKrupe + '0';
		}
		 
		for (size_t i = 0; i < 30; i++)
		{
			for (size_t t = 0; t < 120; t++)
			{
					cout << mas[i][t];
			}
			cout << endl;
		}
	}
	char** getMap()
	{
		return mas;
	}
	bool getNewCard()
	{
		return new_card;
	}
	void setNewCard()
	{
		new_card = true;
	}


	void answerClient(map _map)
	{
		char** m = _map.getMap();
		m[25][20] = 'Å';
		m[25][21] = 'ù';
		m[25][22] = 'å';
		m[25][23] = ' ';
		m[25][24] = 'ê';
		m[25][25] = 'à';
		m[25][26] = 'ð';
		m[25][27] = 'ò';
		m[25][28] = 'ó';
		m[25][29] = '?';


		//button "yes"
		m[27][20] = '+';
		m[27][21] = '-';
		m[27][22] = '-';
		m[27][23] = '-';
		m[27][24] = '-';
		m[27][25] = '-';
		m[27][26] = '+';

		m[28][20] = '|';
		m[28][26] = '|';

		m[29][20] = '+';
		m[29][21] = '-';
		m[29][22] = '-';
		m[29][23] = '-';
		m[29][24] = '-';
		m[29][25] = '-';
		m[29][26] = '+';

		m[28][22] = 'Ä';
		m[28][23] = 'à';

		//button "no"


		m[27][30] = '+';
		m[27][31] = '-';
		m[27][32] = '-';
		m[27][33] = '-';
		m[27][34] = '-';
		m[27][35] = '-';
		m[27][36] = '+';

		m[28][30] = '|';
		m[28][36] = '|';

		m[29][30] = '+';
		m[29][31] = '-';
		m[29][32] = '-';
		m[29][33] = '-';
		m[29][34] = '-';
		m[29][35] = '-';
		m[29][36] = '+';

		m[28][32] = 'Í';
		m[28][33] = 'å';
		m[28][34] = 'ò';
	}

	void buttonLeft(map _map)
	{
		char** m = _map.getMap();
		char sim = '#';
		m[27][20] = sim;
		m[27][21] = sim;
		m[27][22] = sim;
		m[27][23] = sim;
		m[27][24] = sim;
		m[27][25] = sim;
		m[27][26] = sim;

		m[28][20] = sim;
		m[28][26] = sim;

		m[28][22] = 'Ä';
		m[28][23] = 'à';

		m[29][20] = sim;
		m[29][21] = sim;
		m[29][22] = sim;
		m[29][23] = sim;
		m[29][24] = sim;
		m[29][25] = sim;
		m[29][26] = sim;

	}
	void buttonRight(map _map)
	{
		char** m = _map.getMap();
		char sim = '#';
		m[27][30] = sim;
		m[27][31] = sim;
		m[27][32] = sim;
		m[27][33] = sim;
		m[27][34] = sim;
		m[27][35] = sim;
		m[27][36] = sim;

		m[28][30] = sim;
		m[28][36] = sim;

		m[28][32] = 'Í';
		m[28][33] = 'å';
		m[28][34] = 'ò';

		m[29][30] = sim;
		m[29][31] = sim;
		m[29][32] = sim;
		m[29][33] = sim;
		m[29][34] = sim;
		m[29][35] = sim;
		m[29][36] = sim;

	}
};

