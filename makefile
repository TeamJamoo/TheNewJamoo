CC=g++
CFLAGS=-I $(IDIR)
LDFLAGS=

SDIR = src/
IDIR = include/
ODIR = obj/

_SRCS = Door_Node.cpp Floor_Tile.cpp Game.cpp Map.cpp Room_Node.cpp
SRCS  = $(addprefix $(SDIR), $(_SRCS))

_DEPS = Door_Node.hpp Floor_Tile.hpp Game.hpp Map.hpp Room_Node.hpp Tile.hpp
DEPS  = $(addprefix $(IDIR), $(_DEPS))

_OBJS = Door_Node.o   Floor_Tile.o   Game.o   Map.o   Room_Node.o
OBJS  = $(addprefix $(ODIR), $(_OBJS))


jamoo: $(OBJS)
	$(CC) $(LDFLAGS) -o jamoo $(OBJS)


$(ODIR)%.o : $(SDIR)%.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
