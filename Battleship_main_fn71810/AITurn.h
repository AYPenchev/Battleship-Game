#pragma once
#include <iostream>
#include "String.h"
#include "Board.h"
#include "Carrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"
#include "Destroyer.h"
#include <ctime>
static size_t AIcountAttackCarrier = 0;
static size_t AIcountAttackBattleship = 0;
static size_t AIcountAttackCruiser = 0;
static size_t AIcountAttackSubmarine = 0;
static size_t AIcountAttackDestroyer = 0;


class AITurn
{
public:
	void AttackWith(Board &mineBoard, Board &AIBoard, Board &boardIsee);

	//Set and Get functions
	void setCarrier(Carrier carrier);
	Carrier getCarrier() const;

	void setBattleship(Battleship battleship);
	Battleship getBattleship() const;

	void setCruiser(Cruiser cruiser);
	Cruiser getCruiser() const;

	void setSubmarine(Submarine submarine);
	Submarine getSubmarine() const;

	void setDestroyer(Destroyer destroyer);
	Destroyer getDestroyer() const;

	void setY(size_t y);
	size_t getY() const;

	void setX(size_t x);
	size_t getX() const;

	
private:
	//AI's ships
	Carrier carrier;
	Battleship battleship;
	Cruiser cruiser;
	Submarine submarine;
	Destroyer destroyer;

	//coordinates
	size_t x;
	size_t y;
};