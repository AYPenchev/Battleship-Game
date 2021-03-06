#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include "String.h"
#include "Board.h"
#include "Ship.h"
#include "Carrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Game.h"
#include "MyTurn.h"
#include "AITurn.h"
#include <ctime>

size_t menu(String userName)
{
	// delete console
	system("cls");
	std::cout << "Menu: " << std::endl;
	std::cout << "Type 1 to play" << std::endl;
	std::cout << "Type 2 for rules" << std::endl;
	std::cout << "Type 0 to exit" << std::endl;
	String choice;
	std::cin >> choice;
	system("cls");
	//check your choice
	if (choice[0] == '0' && strlen(choice.convertToPointer()) == 1)
	{
		return 0;
	}
	else if (choice[0] == '1' && strlen(choice.convertToPointer()) == 1)
	{	
		Game game;
		MyTurn myturn;
	
		//initialization of boards
		game.mineBoardInit();
		game.AIBoardInit();
		game.boardIseeInit();

		//coordinates for my attack, choice for ship, choice whether to use special ability of the chosen ship
		char x;
		char y;
		char ship;
		bool use;
	
	
		for(int i = 0;game.getMineCountt() != 17 && game.getAICountt() != 17; i++)
		{
			std::cout << "Enter 1 to attack with Carrier" << std::endl;
			std::cout << "Enter 2 to attack with Battleship" << std::endl;
			std::cout << "Enter 3 to attack with Cruiser" << std::endl;
			std::cout << "Enter 4 to attack with Submarine" << std::endl;
			std::cout << "Enter 5 to attack with Destroyer" << std::endl;

			std::cout << std::endl << userName ;
			
			//printing boards
			game.getMineBoard().printBoard();
		//	game.getAIBoard().printBoard(); //for cheating
			std::cout <<std::endl<< "Siri: " << std::endl;
			game.getBoardIsee().printBoard();
					
			//Input of the coordinates for my attack, choice for ship, choice whether to use special ability of the chosen ship
			std::cout << std::endl << "Enter Y coordinate between 1 and 8:";
			std::cin >> x;
			if (x >= 49 && x <= 56)
			{				
				myturn.setX(x-48);
			}
			std::cout << std::endl;

			std::cout << "Enter X coordinate between 1 and 8:" ;
			std::cin >> y;
			if (x >= 49 && x <= 56)
			{
				myturn.setY(y - 48);
			}
			std::cout << std::endl;
			
			
			std::cout << "Enter your choice for ship:";
			std::cin >> ship;
			if (x >= 49 && x <= 53)
			{
				myturn.setShip(ship - 48);
			}
			else
			{
				myturn.setShip(6);
			}
			std::cout << std::endl;
			
			
			std::cout << "if you want to use special ability press 1, you can use the ability of every ship 1 time.";
			std::cin >> use;
			if (use == 1)
			{
				myturn.setUse(use);
			}
			else
			{
				myturn.setUse(0);
			}
			std::cout << std::endl;
			

			game.setMyTurn(myturn);
			
			game.Play();
		}
		if (game.getMineCountt() == 17)
		{
			std::cout << "I WIN" << std::endl;
			
			return 0;
		}
		else if (game.getAICountt() == 17)
		{
			std::cout << "AI WIN" << std::endl;
			return 0;
		}

	}
	else if (choice[0] == '2' && strlen(choice.convertToPointer()) == 1)
	{
		std::cout << "Battleship (also Battleships or Sea Battle) is a guessing game for two players." << std::endl;
		std::cout << "is played on ruled grids(paper or board) on which the players' fleets of ships" << std::endl;
		std::cout << "(including battleships) are marked.The locations of the fleet are concealed from" << std::endl;
		std::cout << "the other player.Players alternate turns calling \"shots\" at the other player's" << std::endl;
		std::cout << "ships, and the objective of the game is to destroy the opposing player's fleet." << std::endl;
		std::cout << "Press any key to return to the menu!" << std::endl;
		system("pause");
		return menu(userName);
	}
	else
	{
		std::cout << "Wrong input! Please press enter to return. ";
		system("pause");
		return menu(userName);
	}
}

size_t loadOrPlay()
{
	system("cls"); // iztriva konzolata
	std::cout << "Battleship! " << std::endl;
	std::cout << "Type 0 to exit " << std::endl;
	std::cout << "Type 1 for new game" << std::endl;
	std::cout << "Type 2 to load game " << std::endl;
	String choice;
	std::cin >> choice;
	system("cls");
	if (choice[0] == '2' && strlen(choice.convertToPointer()) == 1)
	{
		std::cout << "This function will be available soon in Battleship 2.0" << std::endl;
		system("pause");
		return loadOrPlay();
	}
	else if (choice[0] == '1' && strlen(choice.convertToPointer()) == 1)
	{
		std::cout << "Enter your name: ";
		String userName;
		std::cin >> userName;
		std::cin.clear();
		menu(userName);
	}
	else if (choice[0] == '0' && strlen(choice.convertToPointer()) == 1)
	{
		return 0;
	}
	else
	{
		std::cout << "Wrong input! Please press enter to return. ";
		system("pause");
		return loadOrPlay();
	}
}

int main()
{
	loadOrPlay();
	
    return 0;
}