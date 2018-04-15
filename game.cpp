




#include "ship.hpp"
#include "board.hpp"
#include "game.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

Game::Game()
{
	// Can't push bakc in ship vectors because they don't exist yet.
};

void Game::takeInput(char & row, int & column, int player)
{
	while(true)
	{
		std::cout << "Player " << player << " turn." << std::endl;
		std::cout << "Choose a row (a-j) to attack." << std::endl;
		std::cin >> row;
		std::cout << "Choose a column (1-10) to attack." << std::endl;
		std::cin >> column;

		if(row >= 'a' & row <= 'j' & column >= 1 & column <= 10)
		{
			if( (player == 1 & _playerOneBoard.get(row, column) == 0) | (player == 2 & _playerTwoBoard.get(row, column) == 0) )
			{
				break;
			}
		}
	std::cout << "Your input is out of bounds or you've already fired at that location. Please try again." << std::endl;
	}
};

void Game::default_setup()
{
	_playerOneShips.push_back( &b1 );
	_playerOneShips.push_back( &c1 );
	_playerOneShips.push_back( &s1 );
	_playerOneShips.push_back( &C1 );
	_playerOneShips.push_back( &d1 );

	_playerTwoShips.push_back( &b2 );
	_playerTwoShips.push_back( &c2 );
	_playerTwoShips.push_back( &s2 );
	_playerTwoShips.push_back( &C2 );
	_playerTwoShips.push_back( &d2 );
};

void Game::playerOneShot(char row, int column)
{
	bool hit = false;
	for(int i = 0; i < _playerTwoShips.size(); ++i )
	{
		if( _playerTwoShips[i]->isHit(row, column) )
		{
			hit = true;
			_playerOneBoard.shot(row, column, hit);
			
			if( _playerTwoShips[i]->isDestroyed() )
			{
				_playerTwoShips.erase( _playerTwoShips.begin() + i );
				std::cout << "BLEEP BLEEP DESTROYED" << std::endl; // remove this line!!!
			}

			return;
		}
	}
	_playerOneBoard.shot(row, column, hit);
};

void Game::playerTwoShot(char row, int column)
{
	bool hit = false;
	for(int i = 0; i < _playerOneShips.size(); ++i )
	{
		if( _playerOneShips[i]->isHit(row, column) )
		{
			hit = true;
			_playerTwoBoard.shot(row, column, hit);
			
			if( _playerOneShips[i]->isDestroyed() )
			{
				_playerOneShips.erase( _playerOneShips.begin() + i );
				std::cout << "BLEEP BLEEP DESTROYED" << std::endl; // remove this line!!!
			}

			return;
		}
	}
	_playerTwoBoard.shot(row, column, hit);
};

int Game::victoryConditions()
{
	if( _playerOneShips.size() == 0 )
	{
		return 2;
	}
	else if( _playerTwoShips.size() == 0 )
	{
		return 1;
	}
	return 0;
};

void Game::print()
{
	std::cout << "Player One Shot History" << std::endl;
	_playerOneBoard.print();
	std::cout << std::endl;
	std::cout << "Player Two Shot History" << std::endl;
	_playerTwoBoard.print();
	std::cout << std::endl;
};