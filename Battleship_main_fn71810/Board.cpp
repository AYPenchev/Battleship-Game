#include "stdafx.h"
#include "Board.h"
#include <ctime>

void Board::clearBoard()
{
	size_t countI = 0;
	size_t countJ = 1;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == 0)
			{
				board[i][j] = countI++;
			}
			else if (j == 0)
			{
				board[i][j] = countJ++;
			}
			else
			{
				board[i][j] = '.';
			}
		}
	}
}

void Board::printBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != 0 && j != 0)
			{
				std::cout << (char)board[i][j] << " ";
			}
			else
			{
				std::cout << board[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}

void Board::setShips()
{
	
	//number of the ships
	size_t ship = 0;
	while (ship < 5)
	{
		autoSetPosition();

		// 0 - horizontal ship, 1 - vertical ship
		 size_t direction = rand() % 2;

		//check for existing ship on this position
		if (board[this->x][this->y] != '&') 
		{
			if (direction)
			{
				switch (ship)
				{
				case 0:
					if (chekVerticalPositionsForShip(2))
					{
						setVerticalPositionsForShip(2);
						ship++;
					}
					break;
				case 1:
				case 2:
					if (chekVerticalPositionsForShip(3))
					{
						setVerticalPositionsForShip(3);
						ship++;
					}
					break;
				case 3:
					if (chekVerticalPositionsForShip(4))
					{
						setVerticalPositionsForShip(4);
						ship++;
					}
					break;
				case 4:
					if (chekVerticalPositionsForShip(5))
					{
						setVerticalPositionsForShip(5);
						ship++;
					}
					break;
				}
			}
			else
			{
				switch (ship)
				{
				case 0:
					if (chekHorizontalPositionsForShip(2))
					{
						setHorizontalPositionsForShip(2);
						ship++;
					}
					break;
				case 1:
				case 2:
					if (chekHorizontalPositionsForShip(3))
					{
						setHorizontalPositionsForShip(3);
						ship++;
					}
					break;
				case 3:
					if (chekHorizontalPositionsForShip(4))
					{
						setHorizontalPositionsForShip(4);
						ship++;
					}
					break;
				case 4:
					if (chekHorizontalPositionsForShip(5))
					{
						setHorizontalPositionsForShip(5);
						ship++;
					}
					break;
				}
			}
		}
	}
}

void Board::checkBoardAtPosition(size_t x, size_t y)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == x && j == y)
			{
				if ((char)board[i][j] == '&' || (char)board[i][j] == 'X')
				{
					if ((char)board[i][j] == '&')
					{
						this->isHit = false;
						this->flagHit = true;
					}
					else
					{
						this->isHit = true;
						this->flagHit = false;
					}
					this->board[i][j] = 'X';
				}
				else if ((char)board[i][j] == '.')
				{
					this->isHit = false;
					this->flagHit = false;
					this->board[i][j] = 'O';
				}
				else if ((char)board[i][j] == 'O')
				{
					this->isHit = true;
					this->flagHit = false;
				}
			}	
		}
	}
}

void Board::setEmptyBoard(size_t x, size_t y)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == x && j == y)
			{
				if (this->flagHit)
				{
					this->board[i][j] = 'X';
				}
				else
				{
					this->board[i][j] = 'O';
				}
			}
		}
	}
	
}

size_t Board::getX() const
{
	return this->x;
}

void Board::setX(size_t x)
{
	this->x = x;
}

size_t Board::getY() const
{
	return this->y;
}

bool Board::getFlagHit() const
{
	return this->flagHit;
}

void Board::setFlagHit(bool flagHit)
{
	this->flagHit = flagHit;
}

bool Board::getisHit() const
{
	return this->isHit;
}

void Board::setisHit(bool flagHit)
{
	this->isHit = isHit;
}

void Board::setY(size_t y)
{
	this->y = y;
}

void Board::autoSetPosition()
{
	//random position for the ship
	this->x = rand() % 8 + 1;
	this->y = rand() % 8 + 1;
}

bool Board::chekVerticalPositionsForShip(size_t life)
{
	size_t count = 0;
	for (size_t i = 0; i < life; i++)
	{
		if (board[this->x + i][this->y] != '&' && (this->x + i) < 9)
		{
			count++;
		}
	}
	return count == life;
}

void Board::setVerticalPositionsForShip(size_t life)
{
	for (size_t i = 0; i < life; i++)
	{
		board[this->x + i][this->y] = '&';
	}
}

bool Board::chekHorizontalPositionsForShip(size_t life)
{
	size_t count = 0;
	for (size_t i = 0; i < life; i++)
	{
		if (board[this->x][this->y + i] != '&' && (this->y + i) < 9)
		{
			count++;
		}
	}
	return count == life;
}

void Board::setHorizontalPositionsForShip(size_t life)
{
	for (size_t i = 0; i < life; i++)
	{
		board[this->x][this->y + i] = '&';
	}
}