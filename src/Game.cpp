//Author: Richard Holgate
//Last Updated: 8/28/2015 by Richard Holgate

#include "Game.hpp"

//the size of the map
#define MAP_WIDTH 50
#define MAP_HEIGHT 50

int main() {
	//Create Game and initialize
	Game * game = new Game();
	//setup the game
	game->setup();
	
	return 0;
}


//DESCRIPTION: setup the game
//INPUT: none
//EFFECT: the game is setup and ready to run
//OUTPUT: none
void Game::setup() {
	//create a map
	game_map = new Map();
	//generate it
	game_map->generate_map(MAP_WIDTH, MAP_HEIGHT);
	game_map->display();
}
