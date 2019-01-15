#include "stdafx.h"
#include "Game.h"

void Game::Play()
{	

	this->myturn.AttackWith(this->mineBoard, this->AIBoard, this->boardIsee);
	if (AIBoard.getFlagHit())
	{
		mineCount++;
		setMineCountt(mineCount);
	}
	if (myturn.getSubmarineAbility())
	{
		srand(time(NULL) + 1);
		if ((rand() % 100) <= 70)
		{
			this->AIturn.AttackWith(this->mineBoard, this->AIBoard, this->boardIsee);
			if (mineBoard.getFlagHit())
			{
				AICount++;
				setAICountt(AICount);
			}
		}
	}
	else 
	{
		this->AIturn.AttackWith(this->mineBoard, this->AIBoard, this->boardIsee);
		if (mineBoard.getFlagHit())
		{
			AICount++;
			setAICountt(AICount);
		}
	}
}

void Game::setAIturn(AITurn AIturn)
{
	this->AIturn = AIturn;
}

AITurn Game::getAIturn() const
{
	return this->AIturn;
}

void Game::setMyTurn(MyTurn myturn)
{
	this->myturn = myturn;
}

MyTurn Game::getMyTurn() const
{
	return this->myturn;
}

void Game::setMineBoard(Board mineBoard)
{
	this->mineBoard = mineBoard;
	
}

Board Game::getMineBoard() const
{
	return this->mineBoard;
}

void Game::setAIBoard(Board AIBoard)
{
	this->AIBoard = AIBoard;
	
}

Board Game::getAIBoard() const
{
	return this->AIBoard;
}

void Game::setBoardIsee(Board boardIsee)
{
	this->boardIsee = boardIsee;
}

Board Game::getBoardIsee() const
{
	return this->boardIsee;
}

void Game::setMineCountt(size_t mineCountt)
{
	this->mineCountt = mineCountt;
}

size_t Game::getMineCountt() const
{
	return this->mineCountt;
}

void Game::setAICountt(size_t AICountt)
{
	this->AICountt = AICountt;
}

size_t Game::getAICountt() const
{
	return this->AICountt;
}

void Game::mineBoardInit()
{
	this->mineBoard.clearBoard();
	srand(time(NULL));
	this->mineBoard.setShips();
}

void Game::AIBoardInit()
{
	this->AIBoard.clearBoard();
	srand(time(NULL) + 1);
	this->AIBoard.setShips();
}

void Game::boardIseeInit()
{
	this->boardIsee.clearBoard();
}
