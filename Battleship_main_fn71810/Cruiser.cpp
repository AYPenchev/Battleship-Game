#include "stdafx.h"
#include "Cruiser.h"
static size_t oneHeal = 1;
Cruiser::Cruiser()
{
	setShipLife(3);
	setShipSize(3);
	setShipName("Cruiser");
}

void Cruiser::ability(size_t x, size_t y, Board &mineBoard, Board &boardIsee)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (mineBoard.board[i][j] == 'X' && oneHeal > 0)
			{
				mineBoard.board[i][j] = '&';
				oneHeal--;
			}
		}
	}
}
