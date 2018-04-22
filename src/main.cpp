#include <SFML/Graphics.hpp>
#include <../include/board.hpp>
#include <../include/playerboard.hpp>
#include <../include/ship.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>

void placeShips(std::vector<Ship> & ships, sf::RenderWindow & window, sf::Sprite instructions, Board & board, PlayerBoard& playerBoard) {
	std::vector<int> shipPlacement{2,3,3,4,5};

	sf::Texture carrierText, battleshipText, cruiserText, submarineText, destroyerText;
	if ( !carrierText.loadFromFile("../sprites/carrier.png")
			|| !battleshipText.loadFromFile("../sprites/battleship.png")
			|| !cruiserText.loadFromFile("../sprites/cruiser.png")
			|| !submarineText.loadFromFile("../sprites/submarine.png")
			|| !destroyerText.loadFromFile("../sprites/destroyer.png") )
    {
    	throw std::runtime_error("Failed to load instruction sprites.");
    }

    std::vector<sf::Sprite> sprites;
    sprites.push_back(sf::Sprite(destroyerText));
    sprites.push_back(sf::Sprite(submarineText));
    sprites.push_back(sf::Sprite(cruiserText));
    sprites.push_back(sf::Sprite(battleshipText));
    sprites.push_back(sf::Sprite(carrierText));

    for (sf::Sprite &temp : sprites) {
    	temp.setPosition(temp.getPosition().x + 0, temp.getPosition().y + 180);
    }

	while( window.isOpen() && !shipPlacement.empty())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			//Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::MouseButtonPressed) {
				auto index =  board.getMouseSquare(window);
				if (index >= 100 && index < 200) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						// Vertical ship placement
						Ship temp{index - 100, 1, shipPlacement.back()};
						if (playerBoard.addShip(temp)) {
							ships.push_back(temp);
							shipPlacement.pop_back();
							sprites.pop_back();
						}
					} else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
						// Horizontal ship placement
						Ship temp{index - 100, shipPlacement.back(), 1};
						if (playerBoard.addShip(temp)) {
							ships.push_back(temp);
							shipPlacement.pop_back();
							sprites.pop_back();
						}
					}
				}
			}
		}

		window.clear();
		board.draw(window);
		window.draw(instructions);
		if (!sprites.empty()) window.draw(sprites.back());
		for (auto ship : ships){
			ship.draw(window, true);
		}
		window.display();
	}
}

void gameTest()
{
	sf::RenderWindow window{sf::VideoMode{400,840}, "SFML Window", sf::Style::Titlebar | sf::Style::Close};

	sf::Texture bannerOne, bannerTwo, instructions1, instructions2;
	if ( !bannerOne.loadFromFile("../sprites/player_one.png") || !bannerTwo.loadFromFile("../sprites/player_two.png")
			|| !instructions1.loadFromFile("../sprites/player1instructions.png") || !instructions2.loadFromFile("../sprites/player2instructions.png") )
    {
    	throw std::runtime_error("Failed to load sprites.");
    }

	sf::Sprite playerOneBanner{bannerOne};
	playerOneBanner.setPosition(0, 400);
	sf::Sprite playerTwoBanner{bannerTwo};
	playerTwoBanner.setPosition(0, 400);
	sf::Sprite player1instructions{instructions1};
	sf::Sprite player2instructions{instructions2};

	Board board{};
	PlayerBoard player1{};
	PlayerBoard player2{};

	std::vector<Ship> player1Ships;
	std::vector<Ship> player2Ships;
	placeShips(player1Ships, window, player1instructions, board, player1);
	placeShips(player2Ships, window, player2instructions, board, player2);

	bool player1_turn = true;

	while( window.isOpen() )
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			//Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::MouseButtonPressed) {
				auto index =  board.getMouseSquare(window);

				if (index >= 0 && index < 100) {
					if (player1_turn) {
						// If not fired at
						if (!player2.getSquare(index).first) {
							player2.setSquare(index, std::make_pair(true, player2.getSquare(index).second));
							player1_turn = false;
						}
					} else {
						// If not fired at
						if (!player1.getSquare(index).first) {
							player1.setSquare(index, std::make_pair(true, player1.getSquare(index).second));
							player1_turn = true;
						}
					}
				}
			}
		}

		window.clear();
		board.draw(window);
		for (auto ship : player1Ships){
			ship.draw(window, player1_turn);
		}
		for (auto ship : player2Ships){
			ship.draw(window, !player1_turn);
		}
		player1.draw(window, player1_turn);
		player2.draw(window, !player1_turn);
		if (player1_turn) {
			window.draw(playerOneBanner);
		} else {
			window.draw(playerTwoBanner);
		}
		window.display();
	}
}


void shipTest()
{
	sf::RenderWindow window{sf::VideoMode{400,840}, "SFML Window", sf::Style::Titlebar | sf::Style::Close};

	sf::Texture bannerOne, bannerTwo;
	if ( !bannerOne.loadFromFile("../sprites/player_one.png") || !bannerTwo.loadFromFile("../sprites/player_two.png") )
    {
    	throw std::runtime_error("Failed to load _backgroundImage in Board::Board.");
    }
	sf::Sprite playerOneBanner{bannerOne};
	playerOneBanner.setPosition(0, 400);
	sf::Sprite playerTwoBanner{bannerTwo};
	playerTwoBanner.setPosition(0, 400);

	Board board{};
	PlayerBoard player1{};
	PlayerBoard player2{};

	Ship battleship1(1,3,1);
	Ship battleship2(5,1,4);

	std::vector<Ship> player1Ships;
	player1.addShip(battleship1);
	player1Ships.push_back(battleship1);
	player1.addShip(battleship2);
	player1Ships.push_back(battleship2);

	bool player1_turn = true;

	while( window.isOpen() )
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			//Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::MouseButtonPressed) {
				auto index =  board.getMouseSquare(window);

				if (index >= 0 && index < 100) {
					if (player1_turn) {
						// If not fired at
						if (!player2.getSquare(index).first) {
							player2.setSquare(index, std::make_pair(true, player2.getSquare(index).second));
							player1_turn = false;
						}
					} else {
						// If not fired at
						if (!player1.getSquare(index).first) {
							player1.setSquare(index, std::make_pair(true, player1.getSquare(index).second));
							player1_turn = true;
						}
					}
				}
			}
		}

		window.clear();
		board.draw(window);
		for (auto ship : player1Ships){
			ship.draw(window, player1_turn);
		}
		player1.draw(window, player1_turn);
		player2.draw(window, !player1_turn);
		if (player1_turn) {
			window.draw(playerOneBanner);
		} else {
			window.draw(playerTwoBanner);
		}
		window.display();
	}
}

void guiTest()
{
	sf::RenderWindow window{sf::VideoMode{400,840}, "SFML Window", sf::Style::Titlebar | sf::Style::Close};

	sf::Texture bannerOne, bannerTwo;
	if ( !bannerOne.loadFromFile("../sprites/player_one.png") || !bannerTwo.loadFromFile("../sprites/player_two.png") )
    {
    	throw std::runtime_error("Failed to load _backgroundImage in Board::Board.");
    }
	sf::Sprite playerOneBanner{bannerOne};
	playerOneBanner.setPosition(0, 400);
	sf::Sprite playerTwoBanner{bannerTwo};
	playerTwoBanner.setPosition(0, 400);

	Board board{};
	PlayerBoard player1{};
	PlayerBoard player2{};

	player1.setSquare( 1, std::make_pair(false, true) );
	player2.setSquare( 2, std::make_pair(false, true) );

	bool player1_turn = true;

	while( window.isOpen() )
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			//Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::MouseButtonPressed) {
				auto index =  board.getMouseSquare(window);

				if (index >= 0 && index < 100) {
					if (player1_turn) {
						// If not fired at
						if (!player2.getSquare(index).first) {
							player2.setSquare(index, std::make_pair(true, player2.getSquare(index).second));
							player1_turn = false;
						}
					} else {
						// If not fired at
						if (!player1.getSquare(index).first) {
							player1.setSquare(index, std::make_pair(true, player1.getSquare(index).second));
							player1_turn = true;
						}
					}
				}
			}
		}

		window.clear();
		board.draw(window);
		player1.draw(window, player1_turn);
		player2.draw(window, !player1_turn);
		if (player1_turn) {
			window.draw(playerOneBanner);
		} else {
			window.draw(playerTwoBanner);
		}
		window.display();
	}
}

int main()
{
	gameTest();
	// shipTest();
	// guiTest();

	return 0;
}