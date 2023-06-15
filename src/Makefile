CC=g++
CFLAGS= -Wall -Werror -Wextra
LDFLAGS= 
SOURCES= waprint.cpp cli_sim_rc.cpp simfiles.cpp items.cpp
OBJECTS= $(SOURCES:.c=.o)
EXECUTABLE= cli_rc_sim

all: cli_rc_sim

objects:
	$(CC) $(CFLAGS) -c $(SOURCES) $(OBGECTS)

cli_rc_sim: objects
	$(CC) $(LDLAGS) cli_sim_rc.o simfiles.o items.o waprint.o -lncurses -o cli_rc_sim

clean:
	rm -f *.o
	rm -f  test_items  test_files  m.out  cli_rc_sim
	rm -f sim_1 sim_2

rebuild:
	$(MAKE) clean
	$(MAKE) all
