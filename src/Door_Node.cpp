//Author: Richard Holgate
//Last Updated: 8/22/2015 by Richard Holgate

#include "Door_Node.hpp"

//constructor
Door_Node::Door_Node()
{
	//TODO
}

//constructor
Door_Node::Door_Node(int door_x, int door_y)
{

}	//TODO

//desctructor
Door_Node::~Door_Node()
{
	//TODO
}


//DESCRIPTION: add a valid room to the valid_rooms vector
//INPUT: the x, y, width, and height of the room to add
//EFFECT: adds a room with given attributes to the valid_rooms vector
//OUTPUT: none
void Door_Node::add_valid_room(int room_x, int room_y, int room_width, int room_height)
{
	//TODO
}

//DESCRIPTION: return the room at point room_index in the valid_rooms vector
//INPUT: the index of the room wanted
//EFFECT: none
//OUTPUT: valid_rooms[room_index]
Room_Node Door_Node::get_room(int room_index)
{
	return valid_rooms[room_index];
}


//DESCRIPTION: gives the number of rooms contained in the door node
//INPUT: none
//EFFECT: none
//OUTPUT: the number of rooms in the valid_rooms vector
int Door_Node::num_of_rooms()
{
	return valid_rooms.size();
}


//DESCRIPTION: returns whether the door_node contains any rooms
//INPUT: none
//EFFECT: none
//OUTPUT: true or false
bool Door_Node::has_rooms()
{
	if (valid_rooms.size() == 0)
		return false;
	else
		return true;
}
