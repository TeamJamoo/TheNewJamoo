//Author: Richard Holgate
//Last Updated: 8/22/2015 by Richard Holgate

#include "Room_Node.hpp"

//DESCRIPTION: default initializer
//INPUT: none
//OUTPUT: Room_Node object
Room_Node::Room_Node()
{
	//TODO
}

//DESCRIPTION: initializer with all variables
//INPUT: the x and y position of the room, the width and height of the room
//OUTPUIT: Room_Node object
Room_Node::Room_Node(int x, int y, int width, int height)
{
	room_x = x;
	room_y = y;
	room_width = width;
	room_height = height;
}

//DESCRIPTION: get the x value of the room_node
//INPUT: none
//EFFECT: none
//OUTPUT: the x value of the room_node
int Room_Node::get_x()
{
	return room_x;
}


//DESCRIPTION: get the y value of the room_node
//INPUT: none
//EFFECT: none
//OUTPUT: the y value of the room_node
int Room_Node::get_y()
{
	return room_y;
}


//DESCRIPTION: get the width of the room_node
//INPUT: none
//EFFECT: none
//OUTPUT: the width of the room_node
int Room_Node::get_width()
{
	return room_width;
}


//DESCRIPTION: get the height of the room_node
//INPUT: none
//EFFECT: none
//OUTPUT: the height of the room_node
int Room_Node::get_height()
{
	return room_height;
}
