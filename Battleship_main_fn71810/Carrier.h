#pragma once
#include <iostream>
#include "Ship.h"
#include "Board.h"


class Carrier : public Ship
{
public:
	//Default constructor
	Carrier();

	//Special ability
	void ability(size_t x, size_t y, Board & AIBoard, Board & boardIsee);
};