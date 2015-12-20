//Author: Richard Holgate
//Last Updated: 8/22/2015 by Richard Holgate

#ifndef _TILE
#define _TILE

class Tile
{
	public:
		virtual bool not_valid() =0;
	protected:
	private:
		int x_pos;
		int y_pos;

};

#endif
