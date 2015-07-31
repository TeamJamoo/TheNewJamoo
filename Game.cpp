//Author: Richard Holgate
//Last Updated: 7/31/2015

//setup function - create the basic necessities for the game and set them up
void Game:setup() {
	//create a map
	gameMap = new Map();
}

main() {
	//Create Game and initialize
	Game game = new Game();
	//setup the game
	game.setup();
}
