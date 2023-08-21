SRC_FILES := $(wildcard src/*/*.cpp)
HEADERS := $(wildcard src/utils/*.h) $(wildcard src/Objs/*.h) $(wildcard src/Rendering/*.h) $(wildcard src/Handlers/*.h) $(wildcard src/Components/*.h) $(wildcard src/*.h)
OBJS := $(patsubst $(SRC_FILES)/%.cpp, $(SRC_FILES)/%.o, $(SRC_FILES))
CC = g++

INCLUDE_PATHS = `pkg-config --cflags glfw3` `pkg-config --cflags glew`
LIBRARY_PATHS = `pkg-config --static --libs glfw3` `pkg-config --static --libs glew` 
COMPILER_FLAGS = -std=c++17 -Wall -O2 -g

EXECS = Main

all: $(EXECS)

Main: src/Main.o src/Game.o $(OBJS)
	$(CC) $(COMPILER_FLAGS) -o main $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) -framework OpenGL

Main.o: src/Main.cpp $(HEADERS) 
	$(CC) $(COMPILER_FLAGS) -c $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) -framework OpenGL

clean:
	rm -f src/*.o src/*.out src/Rendering/*.o src/Components/*.o src/Handlers/*.o $(EXECS)
