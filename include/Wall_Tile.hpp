//Author: Richard Holgate
//Last Edited: 12/17/2015 by Richard Holgate

#ifndef _WALL_TILE
#define _WALL_TILE

#include "Tile.hpp"

class Wall_Tile: public Tile
{
	public:
            bool may_touch_room();
	protected:
	private:
};


#endif
