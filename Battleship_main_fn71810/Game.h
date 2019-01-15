#pragma once
#include <iostream>
#include "String.h"
#include "Board.h"
#include "Carrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "MyTurn.h"
#include "AITurn.h"
#include <ctime>
static size_t mineCount = 0;
static size_t AICount = 0;

class Game
{
public:
	//Play funciton that have both user's and AI's turns
	void Play();

	//Set and Get functions
	void setAIturn(AITurn AIturn);
	AITurn getAIturn() const;

	void setMyTurn(MyTurn myturn);
	MyTurn getMyTurn() const;

	void setMineBoard(Board mineBoard);
	Board getMineBoard() const;

	void setAIBoard(Board AIBoard);
	Board getAIBoard() const;

	void setBoardIsee(Board boardIsee);
	Board getBoardIsee() const;

	void setMineCountt(size_t mineCountt);
	size_t getMineCountt() const;

	void setAICountt(size_t AICountt);
	size_t getAICountt() const;
	
	void mineBoardInit();
	void AIBoardInit();
	void boardIseeInit();

private:
	//My turn
	MyTurn myturn;

	//AI's turn
	AITurn AIturn;

	// mine board
	Board mineBoard;

	//computer's board
	Board AIBoard; 

	//board I see
	Board boardIsee; 

	//this counters are used to check whether user or AI win the game in every iteration
	size_t mineCountt;
	size_t AICountt;
	
	
};