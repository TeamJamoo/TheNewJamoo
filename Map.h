//Author: Richard Holgate
//Last updated: 8/15/2015 by Richard Holgate

#include "Game.h"
#include "Tile.h"

class Map {
public:
	void generate_map(int width, int height);
protected:
	void create_rooms();
	void create_room(int x_pos, int y_pos, int width, int height);
	void create_door(int x_pos, int y_pos);
	int  gen_room_x(int door_side, int door_x);
	int  gen_room_y(int door_side, int door_x);
	void check_valid_pos_remains();
private:
	Tile ** map_tiles;
}
