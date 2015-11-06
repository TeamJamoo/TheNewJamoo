//Author: Richard Holgate
//Last Updated: 8/22/2015 by Richard Holgate

#ifndef _ROOM_NODE
#define _ROOM_NODE

class Room_Node
{
	public:
		int get_x();
		int get_y();
		int get_width();
		int get_height();
	protected:
	private:
		int room_x;
		int room_y;
		int room_width;
		int room_height;
};

#endif
