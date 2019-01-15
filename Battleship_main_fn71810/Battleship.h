#pragma once
#include <iostream>
#include "Ship.h"
#include "Board.h"


class Battleship : public Ship
{
public:
	//Default constructor
	Battleship();

	//Special ability
	void ability(size_t x, size_t y, Board & AIBoard, Board & boardIsee);
};