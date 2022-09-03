CC=clang++
//CFLAGS= -c -Wall -Werror -Wextra -fsanitize=address -g
//CFLAGS= -Wall -Werror -Wextra
CFLAGS=
LDFLAGS=
SOURCES=wave_demo.cpp waprint.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=m.out

all: cli_rc_sim

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o ../build/m.out

waprint.o: waprint.cpp
	$(CC) $(CFLAGS) -c waprint.cpp -o waprint.o

main.o: wave_demo.cpp
	$(CC) $(CFLAGS) -c wave_demo.cpp -o main.o

test_files.o: test_files.cpp
	$(CC) $(CFLAGS) -c test_files.cpp -o test_files.o

simfiles.o: simfiles.cpp
	$(CC) $(CFLAGS) -c simfiles.cpp -o simfiles.o

test_files: test_files.o sim_files.o
	$(CC) $(LDLAGS) test_files.o simfiles.o -o ../build/test_files

items.o: items.cpp simfiles.o
	$(CC) $(CFLAGS) -c items.cpp -o items.o

test_items: test_items.o simfiles.o items.o waprint.o
	$(CC) $(LDLAGS) test_items.o simfiles.o items.o waprint.o -o ../build/test_items

cli_sim_pll.o: cli_sim_pll.cpp
	$(CC) $(CFLAGS) -c cli_sim_pll.cpp -o cli_sim_pll.o

cli_sim_rc.o: cli_sim_rc.cpp
	$(CC) $(CFLAGS) -c cli_sim_rc.cpp -o cli_sim_rc.o

cli_pll_sim: clean cli_sim_pll.o simfiles.o items.o waprint.o
	$(CC) $(LDLAGS) -lncurses cli_sim_pll.o simfiles.o items.o waprint.o -o ../build/cli_pll_sim

cli_rc_sim: clean cli_sim_rc.o simfiles.o items.o waprint.o
	$(CC) $(LDLAGS) -lncurses cli_sim_rc.o simfiles.o items.o waprint.o -o ../build/cli_rc_sim

clean:
	rm -f *.o
	rm -f ../build/cli_rc_sim ../build/test_items ../build/test_files ../build/m.out
	rm -f sim_1 sim_2

rebuild:
	$(MAKE) clean
	$(MAKE) all
