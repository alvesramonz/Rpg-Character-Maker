#Makefile for "Lab 2" C++ application
#Created by Hilton e Raul 06/04/2019

PROG = Ficheiro
CC = g++
CPPFLAGS = -O0 -g -Wall -pedantic
LIB = lib
OBJS = $(LIB)/Main_system.o $(LIB)/Ficha_system.o $(LIB)/Mar_system.o $(LIB)/Cabecalho_system.o $(LIB)/Villain_system.o $(LIB)/Personagem_system.o  

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

Main_system.o : 
	$(CC) $(CPPFLAGS) -c $(LIB)/Main_system.cpp -o $(LIB)/Main_system.o

Ficha_system.o :
	$(CC) $(CPPFLAGS) -c $(LIB)/Ficha_system.cpp -o $(LIB)/Ficha_system.o

Mar_system.o :
	$(CC) $(CPPFLAGS) -c $(LIB)/Mar_system.cpp -o $(LIB)/Mar_system.o

Cabecalho_system.o :
	$(CC) $(CPPFLAGS) -c $(LIB)/Cabecalho_system.cpp -o $(LIB)/Cabecalho_system.o

Villain_system.o :
	$(CC) $(CPPFLAGS) -c $(LIB)/Villain_system.cpp -o $(LIB)/Villain_system.o

Personagem_system.o :
	$(CC) $(CPPFLAGS) -c $(LIB)/Personagem_system.cpp -o $(LIB)/Personagem_system.o

clean :
	rm -f $(LIB)/*.o
	rm -f core $(PROG) $(OBJS)