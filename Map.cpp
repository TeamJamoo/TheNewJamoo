//Author: Richard Holgate
//Last Updated: 8/20/2015 by Richard Holgate

#include "map.h"
#include <stdlib.h> //rand and srand
#include <time.h> //time

//default room size (until made random later
#define ROOM_SIZE 3 //TODO - seperate into ROOM_WIDTH and ROOM_HEIGHT
		    //TODO - eventually completely randomize

void Map::generate_map(int width, int height)
{
	//create empty map
	map_tiles = new Tile*[width];
	for (int i = 0; i < width; ++i)
	{
		map_tiles[i] = Tile[height];
	}

	//create the first room with default beginning coordinates
	this.create_rooms(1, 1, ROOM_SIZE, ROOM_SIZE);
}

//recursively create all the rooms
void Map::create_rooms(int x_pos, int y_pos, int width, int height, int direction)
{	
	//the position of the room
	int room_x_pos = x_pos;
	int room_y_pos = y_pos;
	//the position of the door
	int door_x_pos;
	int door_y_pos;	
	//which side of the room the current door is being generated on
	//(1 = left, 2 = top, 3 = right, 4 = bottom)
	int door_side;
	//generate random seed
	srand(time(NULL));

	//insert the room into the map
	insert_room(room_x_pos, room_y_pos, width, height); 

	//check if the map is full, and if so, return
	if(!valid_pos_remains()) //TODO
		return;

	//the currently generated room is valid unless set otherwise
	bool current_pos_valid = true;

	//loop until a next door and room are succesfully prepared
	do {
		//choose a random tile for a door to be placed between 1 and 4
		door_side = rand() % 4 + 1;

		//if door_side = 1, door is on the left side
		if (door_side == 1) {
			door_x_pos = room_x_pos - 1;
			door_y_pos = rand() % height + room_y_pos;
		} else 
		//if door_side = 2, door is on the top side
		if (door_side == 2) {
			door_x_pos = rand() % room_x_pos + width;
			door_y_pos = room_y_pos - 1;

		} else
		//if door_side = 3, door is on the right side
		if (door_side == 3) {
			door_x_pos = room_x_pos + height;
			door_y_pos = rand() room_y_pos + height;
		} else
		//if door_side = 4, door is on the bottom side
		if (door_side == 4) {
			door_x_pos = room_x_pos + width;
			door_y_pos = room_y_pos +height;

		}

		//determine the coordinates of the next room to be made
		//if a valid position is found, set current_pos_valid to true
		//if a valid position isn't found, loop
		room_x_pos = gen_room_x(door_side, door_x_pos);
		room_y_pos = gen_room_y(door_side, door_y_pos);

	} while(!current_pos_valid);

	//once out of the loop, that means a valid door and room position were found
	//time to create the door, and loop again to create the next room
	insert_door(door_x_pos, door_y_pos);
	//next recursive step
	create_rooms(room_x_pos, room_y_pos, ROOM_SIZE, ROOM_SIZE, door_side);
}



//add the tiles for a single room on the map
void Map::insert_room(int x_pos, int y_pos, int width, int height)
{
	for (int i = x_pos, i < x_pos+width; ++i)
	{
		for (int j = y_pos, j < y_pos+height; ++i)
		{
		//add a floor tile for each space in the room
		map_tiles[i][j] = new floor_tile();

		}
	}
}



//add a door tile to the given position
void Map::insert_door(int x_pos, int y_pos)
{
	map_tiles[x_pos][y_pos] = new door_tile();
}



//find a valid x-position for the next room to be made.
//if a valid position isn't found, set current_pos_valid to false
int Map::gen_room_x(int door_side, int door_x)
{
	//room is valid until set otherwise
	bool room_valid = true;
	//loop until a valid room is found. If there aren't any, set current_pos_valid to false, and return -1
	do {
		//the placement of the room depends on the direction of the door
		//(1 = left, 2 = top, 3 = right, 4 = bottom)

		if (door_side == 1) {
			//door on the left side, x position is fixed
			return door_x - ROOM_SIZE;		
		} else 
		if (door_side == 2) {
			//door on the top side, room-x can been door-x +/- (room_size-1)
			return (rand() % ((ROOM_SIZE * 2)-1)) + door_x - (ROOM_SIZE-1);
		} else
		if (door_side == 3) {
			//door on the left side, x position if fixed
			return door_x + 1;
		} else
		if (door_side == 4) {
			//door on the bottom side, same equation as top side
			return (rand() % ((ROOM_SIZE * 2)-1)) + door_x - (ROOM_SIZE-1);
		}

		//Check the validity of the given room coordinates
		//TODO

	} while (!room_valid);
}
