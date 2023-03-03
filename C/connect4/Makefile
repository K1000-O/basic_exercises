######
#
#		
#
######
CC=gcc
CFLAGS= -g -Wall -pedantic -c

######
#
#	EJECUTABLES
#
######
all: game mv_obj

game: game.o player.o
	$(CC) -o $@ $^

######
#
#	OBJETOS
#
######
game.o: ./src/game.c ./includes/player.h ./includes/types.h
	$(CC) $(CFLAGS) $<

player.o: ./src/player.c ./includes/player.h ./includes/types.h
	$(CC) $(CFLAGS) $<

######
#
#	Limpieza
#
######
clean:
	rm -rf ./obj/*.o

clean_all:
	rm -rf ./obj/*.o ./*.o game

mv_obj:
	mv *.o ./obj
	