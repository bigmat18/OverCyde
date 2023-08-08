HEADERS = $(wildcard src/utils/*.h) $(wildcard src/Rendering/*.h) $(wildcard src/Handlers/*.h) $(wildcard src/Components/*.h) $(wildcard src/*.h)
OBJS = $(wildcard src/Rendering/*.o) $(wildcard src/Handlers/*.o) $(wildcard src/Components/*.o)
CC = clang++

INCLUDE_PATHS = `pkg-config --cflags glfw3` `pkg-config --cflags glew`
LIBRARY_PATHS = `pkg-config --static --libs glfw3` `pkg-config --static --libs glew` 
COMPILER_FLAGS = -std=c++11 -stdlib=libc++ -Wall -Wextra -O -g -pthread

EXECS = Main

all: $(EXECS)

Main: src/Main.o src/Game.o src/GameObj.o src/Rendering/Cube.o src/Rendering/Shader.o src/Rendering/Texture3D.o src/Rendering/IndexBuffer.o src/Rendering/VertexBuffer.o src/Rendering/VertexArray.o src/Handlers/GameObjHandler.o src/Handlers/RendererHandler.o src/Components/RendererComponent.o
	$(CC) $(COMPILER_FLAGS) -o main $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) -framework OpenGL

Main.o: src/Main.cpp $(HEADERS) 
	$(CC) $(COMPILER_FLAGS) -c $< $(INCLUDE_PATHS) $(LIBRARY_PATHS) -framework OpenGL

clean:
	rm -f src/*.o src/*.out src/Rendering/*.o src/Components/*.o src/Handlers/*.o $(EXECS)