//Author: Richard Holgate
//Last Updated: 7/31/2015

#include "map.h"

void Map:generate_map(int width, int height)
{
	//create empty map
	map_tiles = new Tile*[width];
	for (int i = 0; i < width; ++i)
	{
		map_tiles[i] = Tile[height];
	}

	//create the first room
	this.create_room(1,1,3,3);

}
