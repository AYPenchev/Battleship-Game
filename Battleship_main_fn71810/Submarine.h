#pragma once
#include <iostream>
#include "Ship.h"
#include "Board.h"

class Submarine : public Ship
{
public:
	//Default constructor
	Submarine();

	//Special ability
	void ability(size_t x, size_t y, Board &AIBoard, Board &boardIsee);
};