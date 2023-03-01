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
prueba: prueba.o node.o
	$(CC) -o $@ $^

######
#
#	OBJETOS
#
###### 
prueba.o: prueba.c node.h
	$(CC) $(CFLAGS) $<
	
node.o: node.c node.h types.h
	$(CC) $(CFLAGS) $<

######
#
#	Limpieza
#
######
clean:
	rm -rf *.o

clean_all:
	rm -rf *.o prueba
	