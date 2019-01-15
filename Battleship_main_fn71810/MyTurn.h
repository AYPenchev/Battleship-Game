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

//these variables are used to prevent using one ship more than one time in 5 moves
static size_t countAttackCarrier = 0;
static size_t countAttackBattleship = 0;
static size_t countAttackCruiser = 0;
static size_t countAttackSubmarine = 0;
static size_t countAttackDestroyer = 0;

class MyTurn
{
public:
	//function that attac his map by using input information from user
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

	void setShip(size_t ship);
	size_t getShip() const;

	void setUse(bool use);
	bool getUse() const;

	void setSubmarineAbility(bool submarineAbility);
	bool getSubmarineAbility() const;
private:
	//Mine ships
	Carrier carrier;
	Battleship battleship;
	Cruiser cruiser;
	Submarine submarine;
	Destroyer destroyer;
	
	// x coordinate
	size_t x; 

	// y coordinate
	size_t y; 

	//choice of ship
	size_t ship; 

	//if true use ability
	bool use = 0; 

	//whether to use submarineAbility or not
	bool submarineAbility = false;
 };