HEADERS = $(wildcard src/utils/*.h) $(wildcard src/*.h)
OBJS = $(wildcard src/*.o)
CC = clang++

INCLUDE_PATHS = `pkg-config --cflags glfw3` `pkg-config --cflags glew`
LIBRARY_PATHS = `pkg-config --static --libs glfw3` `pkg-config --static --libs glew` 
COMPILER_FLAGS = -std=c++11 -stdlib=libc++ -Wall -Wextra -O -g -pthread

EXECS = Main

all: $(EXECS)

Main: src/Main.o src/Game.o src/RendererHandler.o
	$(CC) $(COMPILER_FLAGS) -o main $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) -framework OpenGL

Main.o: src/Main.cpp $(HEADERS) 
	$(CC) $(COMPILER_FLAGS) -c $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) -framework OpenGL

clean:
	rm -f src/*.o src/*.out $(EXECS)