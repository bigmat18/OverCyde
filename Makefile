CC = clang++
CCFLAGS  = -std=c++20 -stdlib=libc++ -O1 -g -Wall -Wextra -Wpedantic
CCFLAGS += -Wno-c99-extensions -Wno-unused-parameter -Wno-vla-extension
CCFLAGS += -Wno-c++11-extensions -Wno-gnu-statement-expression
CCFLAGS += -Wno-gnu-zero-variadic-macro-arguments -Wno-nested-anon-types
CCFLAGS += -Wno-gnu-anonymous-struct

# ensure build directory exists
$(shell mkdir -p $(BUILD_DIR))

ROOT_DIR = .
SRC_DIR = ${ROOT_DIR}/src
LIBS_DIR := ${ROOT_DIR}/libs
BUILD_DIR := ${ROOT_DIR}/build

RENDERING_DIR = $(SRC_DIR)/Rendering
EVENTS_DIR = $(SRC_DIR)/Events
WINDOW_DIR = $(SRC_DIR)/Windows

# DIR := $(sort $(dir $(wildcard $(SRC_DIR)/*/)))
# FILES := $(foreach path, $(DIR), $(wildcard $(path)*.cpp))
# OBJS_FILE := $(foreach file, $(FILES), $(patsubst $(RENDERING_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(file)))

ROOT_FILES := $(wildcard ${ROOT_DIR}/*.cpp)
LIBS_FILES := $(wildcard $(LIBS_DIR)/*.cpp)
SRC_FILES := $(wildcard ${SRC_DIR}/*.cpp)

RENDERING_FILES := $(wildcard $(RENDERING_DIR)/*.cpp)
EVENTS_FILES := $(wildcard $(EVENTS_DIR)/*.cpp)
WINDOW_FILES := $(wildcard $(WINDOW_DIR)/*.cpp)

# Generate object file names from source files
EXE_FILES := $(patsubst ${ROOT_DIR}/%.cpp, %, $(ROOT_FILES))
SRC_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

RENDERING_OBJ_FILES := $(patsubst $(RENDERING_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(RENDERING_FILES))
EVENTS_OBJ_FILES := $(patsubst $(EVENTS_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(EVENTS_FILES))
WINDOW_OBJ_FILES := $(patsubst $(WINDOW_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(WINDOW_FILES))

OBJ_NAME = main

# Configurazione delle librerie GLEW e GLFW
GLEW_LIB = -lGLEW
GLFW_LIB = -lglfw

# Percorso alle librerie GLEW e GLFW
GLEW_PATH = ${LIBS_DIR}/glew
GLFW_PATH = ${LIBS_DIR}/glfw
GLM_PATH = ${LIBS_DIR}/glm
SPDLOG_PATH = ${LIBS_DIR}/spdlog

# Aggiungi i percorsi delle librerie al compilatore e al linker
CCFLAGS += -I$(GLEW_PATH)/include -I$(GLFW_PATH)/include -I${GLM_PATH} -I${SPDLOG_PATH}/include
LDFLAGS += -L$(GLEW_PATH)/lib -L$(GLFW_PATH)/src -L${GLM_PATH} -L${SPDLOG_PATH}/src

# Collega le librerie GLEW e GLFW
LDLIBS += $(GLEW_LIB) $(GLFW_LIB) -lX11 -lm -ldl -lpthread -framework OpenGL

# Aggiungi i file sorgente delle librerie al tuo progetto
SOURCES += $(GLEW_PATH)/src/*.c $(GLFW_PATH)/src/*.c

all: $(EXE_FILES)

# Build executable targets
$(EXE_FILES): % : $(BUILD_DIR)/%.o $(SRC_OBJ_FILES) $(RENDERING_OBJ_FILES) $(EVENTS_OBJ_FILES) $(WINDOW_OBJ_FILES) 
	$(CC) $(CCFLAGS) $(LDLIBS) $^ -o $@ 

# Build object files from source files
$(BUILD_DIR)/%.o: ${ROOT_DIR}/%.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# Build object files from library source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp 
	$(CC) $(CCFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(RENDERING_DIR)/%.cpp 
	$(CC) $(CCFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(EVENTS_DIR)/%.cpp 
	$(CC) $(CCFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(WINDOW_DIR)/%.cpp 
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/* $(EXE_FILES)

test: $(info [${FILES}])
