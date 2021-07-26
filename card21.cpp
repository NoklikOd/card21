#include <iostream>
#include "Card.h"
#include "map.h"
#include <Windows.h>

void answerClient(map);
void buttonLeft(map);
void buttonRight(map);

int main()
{
	setlocale(LC_ALL, "Russian");

	//цикл вопроса
	
	map Map;

	Map.addNewCardClient();
	Map.addNewCardKrupe();
	Map.printMap();
	
	Map.buttonLeft();

	Map.addNewCardClient();
	Map.printMap();

	Map.buttonRight();

	Map.addNewCardClient();
	Map.addNewCardKrupe();
	Map.answerClient();
	Map.printMap();

	

	return 0;
}

void gameOver()
{

}





