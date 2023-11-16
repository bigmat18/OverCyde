CC = g++
CFLAGS = -std=c++17 -Wall -g 
LFLAGS = -lglfw -lGLEW -framework OpenGL 

SRC_DIR = .
LIB_DIR := ${SRC_DIR}/src

LIB_COMPONENTS_DIR = ${LIB_DIR}/Components
LIB_HANDLERS_DIR = ${LIB_DIR}/Handlers
LIB_OBJS_DIR = ${LIB_DIR}/Objs

BUILD_DIR := ${SRC_DIR}/build

# ensure build directory exists
$(shell mkdir -p $(BUILD_DIR))

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
LIB_FILES := $(wildcard $(LIB_DIR)/*.cpp)
LIB_COMPONENTS_FILES := $(wildcard $(LIB_COMPONENTS_DIR)/*.cpp)
LIB_HANDLERS_FILES := $(wildcard $(LIB_HANDLERS_DIR)/*.cpp)
LIB_OBJS_FILES := $(wildcard $(LIB_OBJS_DIR)/*.cpp)

# Generate object file names from source files
EXE_FILES := $(patsubst $(SRC_DIR)/%.cpp, %, $(SRC_FILES))
LIB_OBJ_FILES := $(patsubst $(LIB_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(LIB_FILES))

LIB_OBJ_COMPONENTS_FILES := $(patsubst $(LIB_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(LIB_COMPONENTS_FILES))
LIB_OBJ_HANDLERS_FILES := $(patsubst $(LIB_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(LIB_HANDLERS_FILES))
LIB_OBJ_OBJS_FILES := $(patsubst $(LIB_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(LIB_OBJ_FILES))

OBJ_NAME = main

all: $(EXE_FILES)

# Build executable targets
$(EXE_FILES): % : $(BUILD_DIR)/%.o $(LIB_OBJ_FILES) $(LIB_OBJ_HANDLERS_FILES) $(LIB_OBJ_COMPONENTS_FILES) $(LIB_OBJ_OBJS_FILES)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

# Build object files from source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Build object files from library source files
$(BUILD_DIR)/%.o: $(LIB_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/* $(EXE_FILES)
