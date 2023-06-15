CC=g++
CFLAGS= -Wall -Werror -Wextra
LDFLAGS= 
SOURCES=wave_demo.cpp waprint.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=m.out

all: cli_rc_sim

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o  m.out

waprint.o: waprint.cpp
	$(CC) $(CFLAGS) -c waprint.cpp -o waprint.o

main.o: wave_demo.cpp
	$(CC) $(CFLAGS) -c wave_demo.cpp -o main.o

test_files.o: test_files.cpp
	$(CC) $(CFLAGS) -c test_files.cpp -o test_files.o

simfiles.o: simfiles.cpp
	$(CC) $(CFLAGS) -c simfiles.cpp -o simfiles.o

test_files: test_files.o sim_files.o
	$(CC) $(LDLAGS) test_files.o simfiles.o -o test_files

items.o: items.cpp simfiles.o
	$(CC) $(CFLAGS) -c items.cpp -o items.o

test_items: test_items.o simfiles.o items.o waprint.o
	$(CC) $(LDLAGS) test_items.o simfiles.o items.o waprint.o -o test_items

cli_sim_rc.o: cli_sim_rc.cpp
	$(CC) $(CFLAGS) -c cli_sim_rc.cpp -o cli_sim_rc.o

cli_rc_sim: clean cli_sim_rc.o simfiles.o items.o waprint.o
	$(CC) $(LDLAGS) cli_sim_rc.o simfiles.o items.o waprint.o -lncurses -o cli_rc_sim

clean:
	rm -f *.o
	rm -f  test_items  test_files  m.out  cli_rc_sim
	rm -f sim_1 sim_2

rebuild:
	$(MAKE) clean
	$(MAKE) all
