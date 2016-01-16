CC = gcc
CFLAGS = -c -Wall

TARGET = Parse

$(TARGET): Main.o parse.o symbol.o
	$(CC) -o $(TARGET) Main.o parse.o symbol.o

Main.o: Main.c global.h
	$(CC) $(CFLAGS) Main.c global.h

parse.o: parse.c parse.h
	$(CC) $(CFLAGS) parse.c parse.h

symbol.o: symbol.c symbol.h
	$(CC) $(CFLAGS) symbol.c symbol.h


