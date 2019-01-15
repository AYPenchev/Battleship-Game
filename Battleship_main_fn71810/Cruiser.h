#pragma once
#include <iostream>
#include "Ship.h"
#include "Board.h"

class Cruiser : public Ship
{
public:
	//Default constructor
	Cruiser();

	//Special ability
	void ability(size_t x, size_t y, Board &AIBoard, Board &boardIsee);
};