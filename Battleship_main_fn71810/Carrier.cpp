#include "stdafx.h"
#include "Carrier.h"

Carrier::Carrier()
{
	setShipLife(5);
	setShipSize(5);
	setShipName("Carrier");
}

void Carrier::ability(size_t x, size_t y, Board & AIBoard, Board & boardIsee)
{
	AIBoard.checkBoardAtPosition(x, y);
	boardIsee.setFlagHit(AIBoard.getFlagHit());
	boardIsee.setEmptyBoard(x, y);
}

