TARGETS = table_mwe1 table_mwe2 table_mwe3 table2_mwe1 table2_mwe2 table2_mwe3

all:	$(TARGETS)

OPTS =  -std=c99 -Wall -I ../../include -g

clean:
	-rm $(TARGETS)

table_mwe1: table_mwe1.c table.c ../dlist/dlist.c
	gcc -o $@ $(OPTS) $^

table_mwe2: table_mwe2.c table.c ../dlist/dlist.c
	gcc -o $@ $(OPTS) $^

table_mwe3: table_mwe3.c table.c ../dlist/dlist.c
	gcc -o $@ $(OPTS) $^

table2_mwe1: table_mwe1.c table2.c ../dlist/dlist.c
	gcc -o $@ $(OPTS) $^

table2_mwe2: table_mwe2.c table2.c ../dlist/dlist.c
	gcc -o $@ $(OPTS) $^

table2_mwe3: table_mwe3.c table2.c ../dlist/dlist.c
	gcc -o $@ $(OPTS) $^

memtest11: table_mwe1
	valgrind --leak-check=full --show-reachable=yes ./$<

memtest12: table_mwe2
	valgrind --leak-check=full --show-reachable=yes ./$<

memtest13: table_mwe3
	valgrind --leak-check=full --show-reachable=yes ./$<

memtest21: table2_mwe1
	valgrind --leak-check=full --show-reachable=yes ./$<

memtest22: table2_mwe2
	valgrind --leak-check=full --show-reachable=yes ./$<

memtest23: table2_mwe3
	valgrind --leak-check=full --show-reachable=yes ./$<

