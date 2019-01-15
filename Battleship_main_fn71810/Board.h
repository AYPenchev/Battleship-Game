#pragma once
#include <iostream>

class Board
{
public:
	//Clear map
	void clearBoard();

	//print map
	void printBoard();

	//set ships at random positions and orientations
	void setShips();

	//Checks whether there is ship on this coordinates and changes the place to X if hit or O if miss
	void checkBoardAtPosition(size_t x,size_t y);

	//Set the position from the upper function in the empty map that user see
	void setEmptyBoard(size_t x, size_t y);

	//Set and Get functions
	size_t getX() const;
	void setX(size_t x);

	size_t getY() const;
	void setY(size_t y);

	bool getFlagHit() const;
	void setFlagHit(bool flagHit);

	bool getisHit() const;
	void setisHit(bool flagHit);

	int board[9][9];
private:
	//coordinates
	size_t x;
	size_t y;

	// if ship is hit
	bool flagHit = false; 

	// if the position is hit
	bool isHit = false; 

	//get random position for the start of the ship
	void autoSetPosition();

	//Checks and set vertical ships
	bool chekVerticalPositionsForShip(size_t life);
	void setVerticalPositionsForShip(size_t life);

	//Checks and set horizontal ships
	bool chekHorizontalPositionsForShip(size_t life);
	void setHorizontalPositionsForShip(size_t life);
};