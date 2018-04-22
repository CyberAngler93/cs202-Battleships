

#ifndef __PLAYERBOARD_HPP__
#define __PLAYERBOARD_HPP__

#include <SFML/Graphics.hpp>

#include "../include/playerboard.hpp"
#include "../include/ship.hpp"

#include <utility> // std::pair
#include <vector> // std::vector

class PlayerBoard
{
public:
	// Constructors
	PlayerBoard();

	// Member functions
	void draw(sf::RenderWindow & window, bool turn);

	bool addShip(const Ship &);
	
	std::pair<bool,bool> getSquare(int index);
	void setSquare(int index, const std::pair<bool,bool> & newSquare);

private:
	std::vector< std::pair<bool,bool> > _board;
	std::vector<sf::CircleShape> _shots;
};


#endif