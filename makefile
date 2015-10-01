IDIR =include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj

LIBS=
SDIR =src
_SRCS = Door_Node.cpp Floor_Tile.cpp Game.cpp map.cpp Room_Node.cpp
SRCS = $(patsubst %,$(SDIR)/%,$(_SRCS))

_DEPS = Door_Node.hpp Floor_Tile.hpp Game.hpp map.hpp Room_Node.hpp Tile.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Door_Node.o Floor_Tile.o Game.o map.o Room_Node.o Tile.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


jamoo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


$(OBJ): $(SRCS) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
