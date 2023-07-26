OBJS = $(wildcard src/utils/*.h)
CC = g++

INCLUDE_PATHS = `pkg-config --cflags glfw3` `pkg-config --cflags glew`
LIBRARY_PATHS = `pkg-config --static --libs glfw3` `pkg-config --static --libs glew` 
COMPILER_FLAGS = -std=c++17 -Wall -Wextra -O -g -pthread

EXECS = Main

all: $(EXECS)

Main: src/Main.o src/Game.o
	$(CC) -o main $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -framework OpenGL

Main.o: src/Main.cpp $(OBJS) 
	$(CC) -c $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -framework OpenGL

clean:
	rm -f src/*.o src/*.out $(EXECS)