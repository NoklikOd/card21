#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
using namespace std;
class Card
{
private:
	int point;
	char cardZnach;
	char cardMast;
	char** mas;
	const char V = 'V';
	const char D = 'D';
	const char K = 'K';
	const char T = 'T';

public:
	Card()
	{
		point = 0;
		srand((unsigned)time(0));
		int mast = rand() % 4 + 1;
		switch (mast)
		{
		case 1:
		{
			cardMast = (char)3;
			break;
		}
		case 2:
		{
			cardMast = (char)4;
			break;
		}
		case 3:
		{
			cardMast = (char)5;
			break;
		}
		case 4:
		{
			cardMast = (char)6;
			break;
		}
		}
		
		mas = new char* [11];
		for (int i = 0; i < 11; i++)
		{
			mas[i] = new char[10];
		}
		int tempZnach = rand() % 11 + 1;
		if (tempZnach >= 6 && tempZnach <= 10)
		{
			cardZnach = getCharZnach(tempZnach);
		}
		else
		{
			switch (tempZnach)
			{

			case 2:
			{
				point = 2;
				cardZnach = V;
				break;
			}
			case 3:
			{
				point = 3;
				cardZnach = D;
				break;
			}
			case 4:
			{
				point = 4;
				cardZnach = K;
				break;
			}
			case 11:
			{
				point = 11;
				cardZnach = T;
				break;
			}
			case 1:
			{
				point = 11;
				cardZnach = T;
				break;
			}
			}
		}
	}
	/*~Card()
	{

		for (int i = 0; i < 11; i++)
		{
			delete mas[i];
		}
		delete mas;

	}*/
	char getCharZnach(int znachenie)
	{
		switch (znachenie)
		{
		case 6:
		{
			point = 6;
			return '6';
			break;
		}case 7:
		{
			point = 7;
			return '7';
			break;
		}case 8:
		{
			point = 8;
			return '8';
			break;
		}case 9:
		{
			point = 9;
			return '9';
			break;
		}case 10:
		{
			point = 10;
			return '1';
			break;
		}
		}
	}
	char** getCard()
	{
		for (int i = 0; i < 11; i++)
		{
			for (int t = 0; t <11; t++)
			{
				mas[i][t] = ' ';
			}
		}
		

		for (int t = 1; t < 10; t++)
		{
			mas[0][t] = '-';
		}

		for (int t = 1; t < 10; t++)
		{
			mas[9][t] = '-';
		}

		for (int t = 1; t < 10; t++)
		{
			mas[t][0] = '|';
		}

		for (int t = 1; t < 11; t++)
		{
			mas[t][10] = '|';
		}
		mas[0][0] = '+';
		mas[0][10] = '+';
		mas[9][0] = '+';
		mas[9][10] = '+';

		mas[5][5] = cardMast;

		mas[1][1] = cardZnach;
		mas[8][8] = cardZnach;
		if (cardZnach == '1')
		{
			mas[1][2] = '0';
			mas[8][9] = '0';

		}
		
		return mas;
	

	}

	char getCharZnachForTable()
	{
		return cardZnach;
	}

	int getPoint()
	{
		return point;
	}
};

