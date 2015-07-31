//Author: Richard Holgate
//Last Updated: 7/31/2015

#include "map.h"
#include <stdlib.h> //rand and srand
#include <time.h> //time

void Map::generate_map(int width, int height)
{
	//create empty map
	map_tiles = new Tile*[width];
	for (int i = 0; i < width; ++i)
	{
		map_tiles[i] = Tile[height];
	}

	//create the first room
	this.create_rooms();
}

void Map::create_rooms()
{
	//the x and y of the room being generated
	int room_x_pos = 1;
	int room_y_pos = 1;
	//which side of the room the current door is being generated on
	//(1 = left, 2 = top, 3 = right, 4 = bottom)
	int door_side;
	//generate random seed
	srand(time(NULL));

	//continue making rooms until there's no positions left and the map is full
	while(valid_pos_remain) {
		//create a room
		create_room(room_x_pos,room_y_pos,3,3);
		//choose a random tile for a door to be placed
		door_side = rand() % 4 + 1;
	}
}
