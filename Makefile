HEADERS = $(wildcard src/utils/*.h) $(wildcard src/*.h)
OBJS = $(wildcard src/*.o)
CC = g++

INCLUDE_PATHS = `pkg-config --cflags glfw3` `pkg-config --cflags glew`
LIBRARY_PATHS = `pkg-config --static --libs glfw3` `pkg-config --static --libs glew` 
COMPILER_FLAGS = -std=c++17 -Wall -Wextra -O -g -pthread

EXECS = Main

all: $(EXECS)

Main: $(OBJS)
	$(CC) -o main $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -framework OpenGL

Main.o: src/Main.cpp $(HEADERS) 
	$(CC) -c $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -framework OpenGL

clean:
	rm -f src/*.o src/*.out $(EXECS)