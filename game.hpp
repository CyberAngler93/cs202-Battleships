/*	
 *
 *
 */

#ifndef __GAME__
#define __GAME__

#include "ship.hpp"
#include "board.hpp"
#include <vector>

class Game
{

public:
	Game();
	void takeInput(char & row, int & column, int player);
	void default_setup();

	void playerOneShot(char row, int column);
	void playerTwoShot(char row, int column);

	int victoryConditions(); // see which ships are still alive, create string list, etc
	void print();

private:
	std::vector<Ship*> _playerOneShips;
	std::vector<Ship*> _playerTwoShips;
	
	Board _playerOneBoard;
	Board _playerTwoBoard;

	// delete later
	Battleship b1;
	Battleship b2;

	Cruiser c1;
	Cruiser c2;

	Submarine s1;
	Submarine s2;

	Carrier C1;
	Carrier C2;

	Destroyer d1;
	Destroyer d2;
};

#endif