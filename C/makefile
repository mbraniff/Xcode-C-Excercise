CC = g++

SRC_FILES = *.cpp

INCLUDE_PATHS = \
	-I CPP \
	-I DataStructures \
	-I Event

build:
	$(CC) $(INCLUDE_PATHS) -Wall $(SRC_FILES) -o program.exe

run:
	./program.exe

clean:
	rm -f program.exe