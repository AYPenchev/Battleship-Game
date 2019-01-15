#include "stdafx.h"
#include "MyTurn.h"

//check whether or not the special attack was used
static size_t availableUseOfAbilityCarrier = 1;
static size_t availableUseOfAbilityBattleship = 1;
static size_t availableUseOfAbilityCruiser = 1;
static size_t availableUseOfAbilitySubmarine = 1;
static size_t availableUseOfAbilityDestroyer = 1;

void MyTurn::AttackWith(Board & mineBoard, Board & AIBoard, Board & boardIsee)
{
	switch (ship)
	{
	case 1: if (countAttackCarrier % 5 == 0)
			{
				if(getUse() && availableUseOfAbilityCarrier > 0)
				{
					carrier.ability(rand() % 8 + 1, rand() % 5 + 4, AIBoard, boardIsee);
					availableUseOfAbilityCarrier--;
				}
				carrier.attack(x, y, AIBoard, boardIsee);
			}
			else
			{
				std::cout << "You can't attack with this ship now" << std::endl;
				system("pause");
				AIBoard.setFlagHit(false);
				
			}
			countAttackCarrier++;
			(countAttackBattleship % 5) != 0 ? countAttackBattleship++ : false;
			(countAttackCruiser % 5) != 0 ? countAttackCruiser++ : false;
			(countAttackSubmarine % 5) != 0 ? countAttackSubmarine++ : false;
			(countAttackDestroyer % 5) != 0 ? countAttackDestroyer++ : false;
			break;
	case 2:if (countAttackBattleship % 5 == 0)
			{
				if (getUse() && availableUseOfAbilityBattleship > 0)
				{
					battleship.ability(x, y, AIBoard, boardIsee);
					availableUseOfAbilityBattleship--;
				}
				battleship.attack(x, y, AIBoard, boardIsee);
			}
		    else
		    {
			   std::cout << "You can't attack with this ship now" << std::endl;
			   system("pause");
			   AIBoard.setFlagHit(false);
		    }
		   (countAttackCarrier % 5) != 0 ? countAttackCarrier++ : false;
		   countAttackBattleship++;
		   (countAttackCruiser % 5) != 0 ? countAttackCruiser++ : false;
		   (countAttackSubmarine % 5) != 0 ? countAttackSubmarine++ : false;
		   (countAttackDestroyer % 5) != 0 ? countAttackDestroyer++ : false;
			break;
	case 3:	if (countAttackCruiser % 5 == 0)
			{
				if (getUse() && availableUseOfAbilityCruiser > 0)
				{
					cruiser.ability(x, y, mineBoard, boardIsee);
					availableUseOfAbilityCruiser--;
				}
				cruiser.attack(x, y, AIBoard, boardIsee);
			}
			else
			{
				std::cout << "You can't attack with this ship now" << std::endl;
				system("pause");
				AIBoard.setFlagHit(false);
			}
			(countAttackCarrier % 5) != 0 ? countAttackCarrier++ : false;
			(countAttackBattleship % 5) != 0 ? countAttackBattleship++ : false;
			countAttackCruiser++;
			(countAttackSubmarine % 5) != 0 ? countAttackSubmarine++ : false;
			(countAttackDestroyer % 5) != 0 ? countAttackDestroyer++ : false;
			break;
	case 4:	if (countAttackSubmarine % 5 == 0)
			{
				if (getUse() && availableUseOfAbilitySubmarine > 0 )
				{
					submarineAbility = true;
					availableUseOfAbilitySubmarine--;
				}
				submarine.attack(x, y, AIBoard, boardIsee);
			}
			else
			{
				std::cout << "You can't attack with this ship now" << std::endl;
				system("pause");
				AIBoard.setFlagHit(false);
			}
			(countAttackCarrier % 5) != 0 ? countAttackCarrier++ : false;
			(countAttackBattleship % 5) != 0 ? countAttackBattleship++ : false;
			(countAttackCruiser % 5) != 0 ? countAttackCruiser++ : false;
			countAttackSubmarine++;
			(countAttackDestroyer % 5) != 0 ? countAttackDestroyer++ : false;
			break;
	case 5:	if (countAttackDestroyer % 5 == 0)
			{
				if (getUse() && availableUseOfAbilityDestroyer > 0)
				{
					destroyer.ability(mineBoard.getX(), mineBoard.getY(), mineBoard, boardIsee);
					availableUseOfAbilityDestroyer--;
				}
				destroyer.attack(x, y, AIBoard, boardIsee);
			}
			else
			{
				std::cout << "You can't attack with this ship now" << std::endl;
				system("pause");
				AIBoard.setFlagHit(false);
			}
			(countAttackCarrier % 5) != 0 ? countAttackCarrier++ : false;
			(countAttackBattleship % 5) != 0 ? countAttackBattleship++ : false;
			(countAttackCruiser % 5) != 0 ? countAttackCruiser++ : false;
			(countAttackSubmarine % 5) != 0 ? countAttackSubmarine++ : false;
			countAttackDestroyer++;
			break;
	
	default:
		std::cout << "Wrong input!" << std::endl;
		system("pause");
		break;
	}
}

void MyTurn::setCarrier(Carrier carrier)
{
	this->carrier = carrier;
}

Carrier MyTurn::getCarrier() const
{
	return this->carrier;
}

void MyTurn::setBattleship(Battleship battleship)
{
	this->battleship = battleship;
}

Battleship MyTurn::getBattleship() const
{
	return this->battleship;
}

void MyTurn::setCruiser(Cruiser cruiser)
{
	this->cruiser = cruiser;
}

Cruiser MyTurn::getCruiser() const
{
	return this->cruiser;
}

void MyTurn::setSubmarine(Submarine submarine)
{
	this->submarine = submarine;
}

Submarine MyTurn::getSubmarine() const
{
	return this->submarine;
}

void MyTurn::setDestroyer(Destroyer destroyer)
{
	this->destroyer = destroyer;
}

Destroyer MyTurn::getDestroyer() const
{
	return this->destroyer;
}

void MyTurn::setY(size_t y)
{
	this->y = y;
}

size_t MyTurn::getY() const
{
	return this->y;
}

void MyTurn::setX(size_t x)
{
	this->x = x;
}

size_t MyTurn::getX() const
{
	return this->x;
}

void MyTurn::setShip(size_t ship)
{
	this->ship = ship;
}

size_t MyTurn::getShip() const
{
	return this->ship;
}

void MyTurn::setUse(bool use)
{
	this->use = use;
}

bool MyTurn::getUse() const
{
	return this->use;
}

void MyTurn::setSubmarineAbility(bool submarineAbility)
{
	this->submarineAbility = submarineAbility;
}

bool MyTurn::getSubmarineAbility() const
{
	return this->submarineAbility;
}
