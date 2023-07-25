OBJS = $(wildcard src/*.cpp)
CC = g++

INCLUDE_PATHS = `pkg-config --cflags glfw3` `pkg-config --cflags glew`
LIBRARY_PATHS = `pkg-config --static --libs glfw3` `pkg-config --static --libs glew` 
COMPILER_FLAGS = -std=c++17 -Wall -Wextra -O -g -pthread

EXECS = Main

all: $(EXECS)

Main: Main.o Game.o
	$(CC) -o $@ $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -framework OpenGL

Main.o: Main.cpp Game.h
	$(CC) -c $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -framework OpenGL

clean:
	rm -f *.o *.out $(EXECS)