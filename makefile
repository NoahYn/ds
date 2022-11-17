SURC = *.cpp
EXEC = run
CC = g++
FLAG = -std=c++11 -g
all: $(SURC)
		$(CC) $(FLAG) -o $(EXEC) $^

clean:
	rm -rf *.gch *.o