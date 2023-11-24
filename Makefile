CC = g++
CFLAGS = -std=c++17 -Wall -g 
LFLAGS = -lglfw -lGLEW -framework OpenGL 

SRC_DIR = .
BUILD_DIR := ${SRC_DIR}/build
LIB_DIR := ${SRC_DIR}/src
COMPONENT_DIR := ${SRC_DIR}/src/Components
RENDERING_DIR := ${SRC_DIR}/src/Rendering

# ensure build directory exists
$(shell mkdir -p $(BUILD_DIR))

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
LIB_FILES := $(wildcard $(LIB_DIR)/*.cpp)
COMPONENT_FILES := $(wildcard $(COMPONENT_DIR)/*.cpp)
RENDERING_FILES := $(wildcard $(RENDERING_DIR)/*.cpp)


# Generate object file names from source files
EXE_FILES := $(patsubst $(SRC_DIR)/%.cpp, %, $(SRC_FILES))
LIB_OBJ_FILES := $(patsubst $(LIB_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(LIB_FILES))
COMPONENT_OBJ_FILES := $(patsubst $(COMPONENT_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(COMPONENT_FILES))
RENDERING_OBJ_FILES := $(patsubst $(RENDERING_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(RENDERING_FILES))

OBJ_NAME = main

all: $(EXE_FILES)

# Build executable targets
$(EXE_FILES): % : $(BUILD_DIR)/%.o $(LIB_OBJ_FILES) $(COMPONENT_OBJ_FILES) $(RENDERING_OBJ_FILES) 
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

# Build object files from source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Build object files from library source files
$(BUILD_DIR)/%.o: $(LIB_DIR)/%.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(RENDERING_DIR)/%.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(COMPONENT_DIR)/%.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/* $(EXE_FILES)
