TARGET = main.out
CC = g++ -Werror -Wextra -Wall

PTR_SOURCE = ./source/
PTR_OBJ = ../obj/
PTR_TARGET = ../build/


all: main

main: main.o matrix_class.o
	$(CC) $(PTR_OBJ)*.o -o $(PTR_TARGET)$(TARGET)

main.o:
	$(CC) -c $(PTR_SOURCE)main.cpp -o $(PTR_OBJ)main.o

matrix_class.o:
	$(CC) -c $(PTR_SOURCE)matrix_class.cpp -o $(PTR_OBJ)matrix_class.o

clean:
	rm $(PTR_OBJ)*.o $(PTR_TARGET)*.out

leak:
	valgrind --tool=memcheck --leak-check=yes $(PTR_TARGET)$(TARGET)

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem $(PTR_SOURCE)*.cpp