ROOT_DIR = .
BIN_DIR = $(ROOT_DIR)/bin

ifeq ($(OS),Windows_NT)
	OBJ_NAME = main.exe
else
	OBJ_NAME = main
endif

all: build

run:
	$(BIN_DIR)/$(OBJ_NAME)

build_all: build_engine build_game

build_engine:
	./build.py engine

build_game:
	./build.py game

clear_all: clear_engine clear_game

clear_engine:
	./build.py clear engine 

clear_game:
	./build.py clear game 
