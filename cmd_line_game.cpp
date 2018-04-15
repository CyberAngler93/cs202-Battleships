


#include "game.hpp"
#include "board.hpp"
#include "ship.hpp"
#include <iostream>


int main()
{
	Game game;
	game.default_setup();

	char row;
	int column;
	int winner;

	while( true )
	{
		// player one shot
		game.takeInput(row, column, 1);
		// player one shot
		game.playerOneShot(row, column);
		game.print();
		// check for victory
		winner = game.victoryConditions();
		if(winner != 0) break;
		// player two shot
		game.takeInput(row, column, 2);
		game.playerTwoShot(row, column);
		// redraw board
		game.print();
		// check for victory
		winner = game.victoryConditions();
		if(winner != 0) break;
	}
	// declare the winner and end game
	std::cout << std::endl << std::endl << "You win, what a great game! (player " << winner << ") wins." << std::endl << std::endl;

	return 0;	
};