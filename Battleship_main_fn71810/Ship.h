#pragma once
#include <iostream>
#include "String.h"
#include "Board.h"
#include <ctime>


class Ship
{
public:
	//virtual function that is different for every ship
	virtual void ability(size_t x, size_t y,Board &AIBoard, Board &boardIsee) = 0;

	//this function is used when the user attacks
	void attack(size_t x, size_t y, Board &AIBoard, Board &boardIsee);

	//this function is used when the AI attacks
	void AIAttack(size_t x, size_t y, Board &mineBoard);

	//Set and Get functions
	size_t getShipLife() const;
	void setShipLife(size_t shipLife);

	size_t getShipSize() const;
	void setShipSize(size_t shipSize);

	String getShipName() const;
	void setShipName(String shipName);
	

private:
	//ship life (2, 3, 4 or 5)
	size_t shipLife;

	//ship size (2, 3, 4 or 5)
	size_t shipSize;

	//ship name
	String shipName;
	
};
