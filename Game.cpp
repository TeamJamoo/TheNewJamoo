//Author: Richard Holgate
//Last Updated: 8/22/2015

#include "Game.h"

main() {
	//Create Game and initialize
	Game * game = new Game();
	//setup the game
	game->setup();
}


//DESCRIPTION: setup the game
//INPUT: none
//EFFECT: the game is setup and ready to run
//OUTPUT: none
void Game::setup() {
	//create a map
	gameMap = new Map();
}


//DESCRIPTION: display the game board
//INPUT: none
//EFFECT: none
//OUTPUT: none
void Game::display()
{
	//TODO
}
