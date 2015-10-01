//Author: Richard Holgate
//Last Updated: 8/22/2015 by Richard Holgate

#ifndef _DOOR_NODE
#define _DOOR_NODE

#include "Room_Node.hpp"
#include <vector> //vector<class_type>

class Door_Node
{
	public:
		Door_Node();
		Door_Node(int door_x, int door_y);
		~Door_Node();

		void add_valid_room(int room_x, int room_y, int room_width, int room_height);
		Room_Node get_room(int room_index);
		int num_of_rooms();
		bool has_rooms();
	protected:
	private:
		int x_pos;
		int y_pos;

		std::vector<Room_Node> valid_rooms;
};

#endif
