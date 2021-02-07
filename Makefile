
CC = g++
CFLAG = -c -Wall

all: output
	
output: main.o matrix.o 
	$(CC) main.o matrix.o -o output

main.o: main.cpp 
	$(CC) $(CFLAG) main.cpp

matrix.o: Matrix.cpp Matrix.h
	$(CC) $(CFLAG) matrix.cpp

clean: 
	rm *.o output