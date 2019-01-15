#include "stdafx.h"
#include "Submarine.h"

Submarine::Submarine()
{
	setShipLife(3);
	setShipSize(3);
	setShipName("Submarine");
}

void Submarine::ability(size_t x, size_t y, Board &AIBoard, Board &boardIsee)
{
	srand(time(NULL) + 1);
	if ((rand() % 100) <= 70)
	{
		
	}
	
}
