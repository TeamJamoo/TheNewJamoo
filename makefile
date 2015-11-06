CC=g++
CFLAGS=-I $(IDIR)
LDFLAGS=

ODIR = obj
SDIR = src
IDIR = include

SRCS = Door_Node.cpp Floor_Tile.cpp Game.cpp Map.cpp Room_Node.cpp
DEPS = Door_Node.hpp Floor_Tile.hpp Game.hpp Map.hpp Room_Node.hpp Tile.hpp
OBJS = Door_Node.o   Floor_Tile.o   Game.o   Map.o   Room_Node.o


jamoo: $(OBJS)
	$(CC) $(LDFLAGS) -o jamoo $(OBJS)


%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
