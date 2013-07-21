CC=g++
CFLAGS=-c -Wall

GLOBALFLAGS=-L/usr/local/lib -lthrift

all: bin/DBWorker_server

bin/DBWorker_server: constants.o types.o dbworker.o server.o
		     $(CC) $(GLOBALFLAGS) constants.o types.o dbworker.o server.o -o bin/DBWorker_server

constants.o: mancity_constants.cpp
	     $(CC) $(CFLAGS) mancity_constants.cpp -o constants.o

types.o: mancity_types.cpp
	 $(CC) $(CFLAGS) mancity_types.cpp -o types.o

dbworker.o: DBWorker.cpp
	    $(CC) $(CFLAGS) DBWorker.cpp -o dbworker.o

server.o: DBWorker_server.cpp
	  $(CC) $(CFLAGS) DBWorker_server.cpp -o server.o

