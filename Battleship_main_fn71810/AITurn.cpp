#include "stdafx.h"
#include "AITurn.h"

//used to switch ships
static size_t ship = 1;
void AITurn::AttackWith(Board & mineBoard, Board & AIBoard, Board & boardIsee)
{	
	switch (ship)
	{
	case 1:	carrier.AIAttack(x, y, mineBoard);break;
	case 2:	battleship.AIAttack(x, y, mineBoard);break;
	case 3: cruiser.AIAttack(x, y, mineBoard);break;
	case 4:	submarine.AIAttack(x, y, mineBoard);break;
	case 5:	destroyer.AIAttack(x, y, mineBoard);break;
	}
	ship++;
	if (ship == 6)
	{
		ship = 1;
	}
}

void AITurn::setCarrier(Carrier carrier)
{
	this->carrier = carrier;
}

Carrier AITurn::getCarrier() const
{
	return this->carrier;
}

void AITurn::setBattleship(Battleship battleship)
{
	this->battleship = battleship;
}

Battleship AITurn::getBattleship() const
{
	return this->battleship;
}

void AITurn::setCruiser(Cruiser cruiser)
{
	this->cruiser = cruiser;
}

Cruiser AITurn::getCruiser() const
{
	return this->cruiser;
}

void AITurn::setSubmarine(Submarine submarine)
{
	this->submarine = submarine;
}

Submarine AITurn::getSubmarine() const
{
	return this->submarine;
}

void AITurn::setDestroyer(Destroyer destroyer)
{
	this->destroyer = destroyer;
}

Destroyer AITurn::getDestroyer() const
{
	return this->destroyer;
}

void AITurn::setY(size_t y)
{
	this->y = y;
}

size_t AITurn::getY() const
{
	return this->y;
}

void AITurn::setX(size_t x)
{
	this->x = x;
}

size_t AITurn::getX() const
{
	return this->x;
}