#include "stdafx.h"
#include "Destroyer.h"

Destroyer::Destroyer()
{
	setShipLife(3);
	setShipSize(3);
	setShipName("Destroyer");
}

void Destroyer::ability(size_t x, size_t y, Board &mineBoard, Board &boardIsee)
{
	mineBoard.board[x][y] = '@';
}
