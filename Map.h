//Author: Richard Holgate
//Last updated: 8/22/2015 by Richard Holgate

#ifndef _MAP
#define _MAP

#include "Tile.h"

class Map
{
public:
	void generate_map(int width, int height);
protected:
	void create_rooms(int room_x, int room_y, int room_width, int room_height);
	void insert_room(int x_pos, int y_pos, int width, int height);
	bool tile_empty(int tile_x, int tile_y);
	bool room_is_valid(int room_x, int room_y, int room_width, int room_height);
	bool valid_pos_remains();
private:
	Tile *** map_tiles;
};

#endif
