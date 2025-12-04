SRC_DIR=src

all:
	g++ -o repl $(SRC_DIR)/repl.cpp

test: all
	./repl
