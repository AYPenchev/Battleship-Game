#include "stdafx.h"
#include "Battleship.h"

Battleship::Battleship()
{
	setShipLife(4);
	setShipSize(4);
	setShipName("Battleship");
}

void Battleship::ability(size_t x, size_t y, Board & AIBoard, Board & boardIsee)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == x && j == y)
			{
				if (i - 1 >= 1 && j - 1 >= 1)
				{
					boardIsee.board[i - 1][j - 1] = AIBoard.board[i - 1][j - 1] == '.' ? 'O' : '&';
				}
				if (i - 1 >= 1)
				{
					boardIsee.board[i - 1][j] = AIBoard.board[i - 1][j] == '.' ? 'O' : '&';
				}
				if (i - 1 >= 1 && j + 1 <= 8)
				{
					boardIsee.board[i - 1][j + 1] = AIBoard.board[i - 1][j + 1] == '.' ? 'O' : '&';
				}

				if (j - 1 >= 1)
				{
					boardIsee.board[i][j - 1] = AIBoard.board[i][j - 1] == '.' ? 'O' : '&';
				}
				if (j + 1 <= 8)
				{
					boardIsee.board[i][j + 1] = AIBoard.board[i][j + 1] == '.' ? 'O' : '&';
				}

				if (i + 1 <= 8 && j - 1 >= 1)
				{
					boardIsee.board[i + 1][j - 1] = AIBoard.board[i + 1][j - 1] == '.' ? 'O' : '&';
				}
				if (i + 1 <= 8)
				{
					boardIsee.board[i + 1][j] = AIBoard.board[i + 1][j] == '.' ? 'O' : '&';
				}
				if (i + 1 <= 8 && j + 1 <= 8)
				{
					boardIsee.board[i + 1][j + 1] = AIBoard.board[i + 1][j + 1] == '.' ? 'O' : '&';
				}
			}
		}
	}
}
