#include "stdafx.h"
#include "Ship.h"
static size_t firstTime = 0;
void Ship::attack(size_t x, size_t y, Board & AIBoard, Board & boardIsee)
{
		AIBoard.checkBoardAtPosition(x, y);
		boardIsee.setFlagHit(AIBoard.getFlagHit());
		boardIsee.setEmptyBoard(x, y);	
}

void Ship::AIAttack(size_t x, size_t y, Board & mineBoard)
{
	size_t randomx = 20000000;
	size_t randomy = 1;
	
	do {
			srand(time(NULL) + randomx--);
			x = rand() % 8 + 1;
			srand(time(NULL) + randomy++);
			y = rand() % 8 + 1;
			mineBoard.checkBoardAtPosition(x, y);
			system("cls");
			std::cout << "AI attacked at position (x, y) = (" << x << ", " << y << ")" << std::endl;
			mineBoard.setX(x);
			mineBoard.setY(y);
		firstTime++;
	} while (mineBoard.getisHit());
}


size_t Ship::getShipLife() const
{
	return this->shipLife;
}

void Ship::setShipLife(size_t shipLife)
{
	this->shipLife = shipLife;
}

size_t Ship::getShipSize() const
{
	return this->shipSize;
}

void Ship::setShipSize(size_t shipSize)
{
	this->shipSize = shipSize;
}

String Ship::getShipName() const
{
	return this->shipName;
}

void Ship::setShipName(String shipName)
{
	this->shipName = shipName;
}
