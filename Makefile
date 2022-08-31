CC=g++
//CFLAGS= -c -Wall -Werror -Wextra -fsanitize=address -g
CFLAGS= -c -Wall -Werror -Wextra
LDFLAGS=
SOURCES=wave_demo.cpp waprint.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=m.out

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o m.out

waprint.o: waprint.cpp
	$(CC) $(CFLAGS) -c waprint.cpp -o waprint.o

main.o: wave_demo.cpp
	$(CC) $(CFLAGS) -c wave_demo.cpp -o main.o

test_files.o: test_files.cpp
	$(CC) $(CFLAGS) -c test_files.cpp -o test_files.o

sim_files.o: sim_files.cpp
	$(CC) $(CFLAGS) -c sim_files.cpp -o sim_files.o

test_files:: test_files.o sim_files.o
	$(CC) $(LDLAGS) test_files.o sim_files.o -o test_files

clean:
	rm -f *.o
	rm -f m.out
	rm -f a.out

rebuild:
	$(MAKE) clean
	$(MAKE) all
