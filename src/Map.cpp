//Author: Richard Holgate
//Last Updated: 8/28/2015 by Richard Holgate

#include "Map.hpp"
#include "Tile.hpp"
#include "Floor_Tile.hpp"
#include "Door_Node.hpp"
#include <stdlib.h> //rand and srand
#include <iostream> //cout and cin
#include <time.h> //time
#include <vector> //vector<class_type>

//default room size (until made random later
#define ROOM_WIDTH 3
#define ROOM_HEIGHT 3
//TODO - eventually completely randomize



//DESCRIPTION: generate the map
//INPUT: the width and height of the map to be generated
//EFFECT: creates and fills a 2D array of tiles that represent the map
//OUTPUT: none
void Map::generate_map(int width, int height)
{
	map_width = width;
	map_height = height;
	//create empty map
	map_tiles = new Tile**[map_width];
	for (int i = 0; i < map_width; ++i)
	{
		map_tiles[i] = new Tile*[map_height];
	}

	//initialize all the pointers to null
	for (int i = 0; i < map_width; ++i)
	{
		for (int j = 0; j < map_height; ++j)
		{
			map_tiles[i][j] = NULL;
		}

	}
	//create the first room with default beginning coordinates
	create_rooms(1, 1, ROOM_WIDTH, ROOM_HEIGHT);
}



//DESCRIPTION: recursively create all the rooms
//INPUT: the x, y, width, and height of the current room to be made
//EFFECT: creates given room, and recurses to make the next door(s) and room(s)
//OUTPUT: none
void Map::create_rooms(int room_x, int room_y, int room_width, int room_height)
{

	//first, add the given room to the map
	insert_room(room_x, room_y, room_width, room_height);

	//the size of the room being generated
	int new_room_width = ROOM_WIDTH;
	int new_room_height = ROOM_HEIGHT;
	//the number of valid rooms generated (later used to pick one randomly)
	//if num_valid_rooms = 0 at the end, there's no valid rooms left, and return
	int num_valid_rooms = 0;

	//a vector to hold the valid doors - which hold valid rooms - generated
	std::vector<Door_Node> valid_doors;
	valid_doors.reserve((new_room_width*2) + (new_room_height*2)); //reserve space

	//check the left side of the previous room for valid door placements
	for (int i = room_y; i < room_y + room_height; ++i)
	{
		//the x and y of the current door being generated
		int door_x = room_x -1;
		int door_y = i;

		if (tile_empty(door_x, door_y))
		{
			//the new door
			Door_Node * new_door = new Door_Node(door_x, door_y);

			//generate valid rooms
			int new_room_x = door_x - new_room_width;
			int new_room_y;
			//loop through possible rooms
			for (int j = door_y - (new_room_height-1); j <= door_y; ++j)
			{
				new_room_y = j;
				//if it's a valid room, add it
				if (room_is_valid(new_room_x, new_room_y, new_room_width, new_room_height))
				{
					new_door->add_valid_room(new_room_x, new_room_y, new_room_width, new_room_height);
					num_valid_rooms += 1;
				}
			}
			
			//if the door has generated valid rooms, it's good
			//otherwise, delete it
			if (new_door->has_rooms())
				valid_doors.push_back(*new_door);
			else
				delete new_door;

		} //end if

	} //end for

	
	//check the top side of the previous room for valid door placements
	for (int i = room_x; i < room_x + room_width; ++i)
	{
		//the x and y of the current door being generated
		int door_x = i;
		int door_y = room_y-1;

		if (tile_empty(door_x, door_y))
		{
			//the new door
			Door_Node * new_door = new Door_Node(door_x, door_y);

			//generate valid rooms
			int new_room_x;
			int new_room_y = door_y - new_room_height;
			//loop through possible rooms
			for (int j = door_x - (new_room_width-1); j <= door_x; ++j)
			{
				new_room_x = j;
				//if it's a valid room, add it
				if (room_is_valid(new_room_x, new_room_y, new_room_width, new_room_height))
				{
					new_door->add_valid_room(new_room_x, new_room_y, new_room_width, new_room_height);
					++num_valid_rooms;
				}
			}

			//if the door has generated valid rooms, it's good
			//otherwise, delete it
			if (new_door->has_rooms())
				valid_doors.push_back(*new_door);
			else
				delete new_door;

		} //end if
	} //end for

	//check the right side of the previous room for valid door placements
	for (int i = room_y; i < room_y + room_height; ++i)
	{
		//the x and y of the current door being generated
		int door_x = room_x + room_width;
		int door_y = i;

		if (tile_empty(door_x, door_y))
		{
			//the new door
			Door_Node * new_door = new Door_Node(door_x, door_y);

			//generate valid rooms
			int new_room_x = door_x + 1;
			int new_room_y;
			//loop through possible rooms
			for (int j = door_y - (new_room_height-1); j <= door_y; ++j)
			{
				new_room_y = j;
				//if it's a valid room, add it
				if (room_is_valid(new_room_x, new_room_y, new_room_width, new_room_height))
				{
					new_door->add_valid_room(new_room_x, new_room_y, new_room_width, new_room_height);
					++num_valid_rooms;
				}
			}
			
			//if the door has generated valid rooms, it's good
			//otherwise, delete it
			if (new_door->has_rooms())
				valid_doors.push_back(*new_door);
			else
				delete new_door;

		} //end if
	} //end for

	//check the bottom side of the previous room for valid door placements
	for (int i = room_x; i < room_x + room_width; ++i)
	{
		//the x and y of the current door being generated
		int door_x = i;
		int door_y = room_y + room_height;

		if (tile_empty(door_x, door_y))
		{
			//the new door
			Door_Node * new_door = new Door_Node(door_x, door_y);

			//generate valid rooms
			int new_room_x;
			int new_room_y = door_y + 1;
			//loop throug possible rooms
			for (int j = door_x - (new_room_width-1); j <= door_x; ++j)
			{
				new_room_x = j;
				//if it's a valid room, add it
				if (room_is_valid(new_room_x, new_room_y, new_room_width, new_room_height))
				{
					new_door->add_valid_room(new_room_x, new_room_y, new_room_width, new_room_height);
					++num_valid_rooms;
				}
			}

			//if the door has valid rooms it's good
			//otherwise, delete it
			if (new_door->has_rooms())
				valid_doors.push_back(*new_door);
			else
				delete new_door;

		} //end if
	} //end for

	//if there were no valid rooms generated, then the base case is triggered, and the function returns
	if (num_valid_rooms == 0)
		return;

	//at this point, we have all the valid doors and rooms
	//now to randomly pick one (or some)
	
	//generate random seed
	srand(time(NULL));

	int chosen_room = rand() % num_valid_rooms + 1;
	int chosen_door = 0;

	//having generated a random choice, access it
	while (chosen_room > valid_doors.at(chosen_door).num_of_rooms())
	{
		chosen_room -= valid_doors.at(chosen_door).num_of_rooms();
		++chosen_door;
	}

	Room_Node * next_room = new Room_Node(valid_doors.at(chosen_door).get_room(chosen_room-1));

	//now recurse with the chosen door/room combo(s)
	create_rooms(next_room->get_x(), next_room->get_y(), next_room->get_width(), next_room->get_height());
	
	//delete the memory used to generate the doors and rooms
	for (int i = 0; i < valid_doors.size(); ++i)
	{
		delete &valid_doors.at(i);
	}

//	delete &valid_doors;
}


//add the tiles for a single room on the map
void Map::insert_room(int x_pos, int y_pos, int width, int height)
{
	for (int i = x_pos; i < x_pos + width; ++i)
	{
		for (int j = y_pos; j < y_pos + height; ++j)
		{
		//add a floor tile for each space in the room
		map_tiles[i][j] = new Floor_Tile();

		}
	}
}



//DESCRIPTION: return a randomly chosen 

//DESCRIPTION: chceks whether the given space on the map has a tile or not
//INPUT: the x and y of the tile to check
//EFFECT: none
//OUTPUT: true or false
bool Map::tile_empty(int tile_x, int tile_y)
{
	if (map_tiles[tile_x][tile_y] == NULL)	
		return true;
	else
		return false;
}



//DESCRIPTION: checks whether the given room coordinates/size constitues a valid room placement
//INPUT: the x, y, width, and height of a room to check
//EFFECT: none
//OUTPUT: true or false
bool Map::room_is_valid(int room_x, int room_y, int room_width, int room_height)
{
	//check if width and height are valid integers
	if (room_x < 0 || room_x > map_width)
		return false;
	if (room_y < 0 || room_y > map_height)
		return false;		

	//loop through each tile the room will occupy to see if it's empty
	for (int i = room_y; i < room_y + room_height; ++i)
       	{
		for (int j = room_x; j < room_x + room_width; ++j)
		{
			//if it's not empty, the room isn't valid
			if (map_tiles[j][i] != NULL)
				return false;
		}
	}
	//if all the tiles are empty, return true
	return true;
}



//DESCRIPTION: displays the map
//INPUT: none
//EFFECT: displays the map in std-out
//OUTPUT: none
void Map::display()
{
	//loop through each tile and display X or O
	for (int i = 0; i < map_height; ++i)
	{
		for (int j = 0; j < map_width; ++j)
		{
			if (j == map_height)
				std::cout << "\n";
			if (map_tiles[j][i] != NULL)
				std::cout << "X";
			else
				std::cout << "O";
		}
	}
}
