#pragma once
#include <iostream>
#include "Ship.h"
#include "Board.h"

class Destroyer : public Ship
{
public:
	//Default constructor
	Destroyer();

	//Special ability
	void ability(size_t x, size_t y, Board &AIBoard, Board &boardIsee);
};