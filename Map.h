//Author: Richard Holgate
//Last updated: 8/18/2015 by Richard Holgate

#include "Game.h"
#include "Tile.h"

class Map {
public:
	void generate_map(int width, int height);
protected:
	void create_rooms(int x_pos, int y_pos, int width, int height, int direction);
	void insert_room(int x_pos, int y_pos, int width, int height);
	void create_door(int x_pos, int y_pos);
	int  gen_room_x(int door_side, int door_x);
	int  gen_room_y(int door_side, int door_x);
private:
	Tile ** map_tiles;
}
