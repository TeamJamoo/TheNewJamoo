//Author: Richard Holgate
//Last Updated: 12/21/2015 by Richard Holgate

#ifndef _TILE
#define _TILE

class Tile
{
	public:
		virtual bool may_touch_room()=0;
	protected:
	private:
		int x_pos;
		int y_pos;

};

#endif
