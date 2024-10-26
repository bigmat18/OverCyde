#!/usr/bin/python3
import argparse
import subprocess
import logging
import os
import datetime
import sys

logging.basicConfig(format="%(asctime)s - %(message)s", level=logging.INFO)

if os.name == 'nt':
    _ = "\\"
else: 
    _ = "/"

class __LastBuildTime():
    build_time_file_name : str = "__build_time"
    __LAST_BUILD_TIME = None

    @classmethod
    def time(cls):
        if cls.__LAST_BUILD_TIME is None:
            cls.__get_last_build_time()

        if not cls.__LAST_BUILD_TIME:
            cls.__LAST_BUILD_TIME = str(datetime.datetime.now())

        return datetime.datetime.strptime(cls.__LAST_BUILD_TIME, "%Y-%m-%d %H:%M:%S.%f")

    @classmethod
    def update(cls):
        cls.__LAST_BUILD_TIME = datetime.datetime.now()
        cls.__set_last_build_time()

    @classmethod
    def __get_last_build_time(cls):
        try:
            with open(cls.build_time_file_name, "r") as file:
                cls.__LAST_BUILD_TIME = file.read()
                file.close()
        except FileNotFoundError:
            cls.__LAST_BUILD_TIME = ""
                
    @classmethod
    def __set_last_build_time(cls):
        with open(cls.build_time_file_name, "w") as file:
            file.write(str(cls.__LAST_BUILD_TIME))
            file.close()


def __execute(command : str, dir : str = ".") -> str:
    logging.info(command)
    return subprocess.check_output(command, cwd=dir, shell=True)\
                     .decode("utf-8")

def __modifid(file: str) -> bool:
    return datetime.datetime.fromtimestamp(os.path.getmtime(file)) > __LastBuildTime.time()

def __exists(file: str) -> bool:
    return os.path.exists(file)

def __get_files_recursive(path : str) -> list[str]:
    result = []
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(".cpp"):
                result.append(os.path.join(root, file))
    return result

def __get_files(path: str) -> list[str]:
    result = []
    for file in os.listdir(path):
        if file.endswith(".cpp"):
            result.append(os.path.join(path, file))
    return result

###############################################################################################
################################### Build definitions #########################################
###############################################################################################

CC = "clang++"
CCFLAGS = "-std=c++20 -stdlib=libc++ -O3 -g -Wall -Wextra -Wpedantic "
CCFLAGS += "-Wno-c99-extensions -Wno-unused-parameter -Wno-vla-extension "
CCFLAGS += "-Wno-c++11-extensions -Wno-gnu-statement-expression "
CCFLAGS += "-Wno-gnu-zero-variadic-macro-arguments -Wno-nested-anon-types "
CCFLAGS += "-Wno-gnu-anonymous-struct "

ROOT_DIR = "."
SRC_DIR = f"{ROOT_DIR}/src"
LIBS_DIR = f"{ROOT_DIR}/libs"
BUILD_DIR = f"{ROOT_DIR}/build"
BIN_DIR = f"{ROOT_DIR}/bin"

OBJ_NAME = "main"
DLL_NAME = "libengine.dylib"            if not os.name == 'nt' else "libengine.dll"
GLEW_LIB = "-lGLEW"                     if not os.name == 'nt' else "-lglew32"
GLFW_LIB = "-lglfw"                     if not os.name == 'nt' else "-lglfw3"
OPENGL_LIB = "-framework OpenGL     \
             -framework Cocoa       \
             -framework IOKit       \
             -framework CoreVideo"      if not os.name == 'nt' else "-lgdi32 -lopengl32 -limm32"

GLEW_PATH = f"{LIBS_DIR}/glew"
GLFW_PATH = f"{LIBS_DIR}/glfw"
GLM_PATH = f"{LIBS_DIR}/glm"
SPDLOG_PATH = f"{LIBS_DIR}/spdlog"
STB_PATH = f"{LIBS_DIR}/stb"
IMGUI_PATH = f"{LIBS_DIR}/imgui"

LDLIBS = f"-L{SPDLOG_PATH}/src -L{BIN_DIR}"
ILIBS = f"-I{GLEW_PATH}/include -I{GLFW_PATH}/include -I{GLM_PATH} -I{SPDLOG_PATH}/include -I{STB_PATH} -I{IMGUI_PATH}"

DLLFLAGS = "-dynamiclib" if not os.name == 'nt' else "-shared"
LDFLAGS = f"{GLEW_LIB} {GLFW_LIB} {OPENGL_LIB} -lm -lpthread -limgui"

def clear(spec : str):
    BUILD_CLEAR = ""
    if spec == "all" or spec == "":
        BUILD_CLEAR = f"{BUILD_DIR}"
    elif spec == "engine":
        BUILD_CLEAR = f"{BUILD_DIR}/Engine"
    elif spec == "game":
        BUILD_CLEAR = f"{BUILD_DIR}/Game"
    else: 
        logging.error(f"Specifica {spec} inesistente")
        sys.exit(0)
    
    for file in os.listdir(f"{BUILD_CLEAR}"):
        os.remove(os.path.join(f"{BUILD_CLEAR}", file))
    
    if spec == "Engine" or spec == "" or spec == "all":
        if os.path.isfile(f"{BIN_DIR}/{DLL_NAME}"):
            os.remove(f"{DLL_NAME}")
    
    if spec == "Game" or spec == "" or spec == "all":
        if os.path.isfile(f"{BIN_DIR}/{OBJ_NAME}"):
            os.remove(f"{OBJ_NAME}")
            
        if os.path.isfile(f"{BIN_DIR}/{OBJ_NAME}.exe"):
            os.remove(f"{BIN_DIR}/{OBJ_NAME}.exe")
        
    if spec == "Engine" or spec == "" or spec == "all":
        if os.path.isfile(f"{BUILD_DIR}/Engine/__build_time"):
            os.remove(f"{BUILD_DIR}/Engine/__build_time")
    
    if spec == "Game" or spec == "" or spec == "all":
        if os.path.isfile(f"{BUILD_DIR}/Game/__build_time"):
            os.remove(f"{BUILD_DIR}/Game/__build_time")


def engine(spec : str):
    ENGINE_DIR = f"{SRC_DIR}/Engine"
    ENGINE_BUILD_DIR = f"{BUILD_DIR}/Engine"
    __LastBuildTime.build_time_file_name = f"{ENGINE_BUILD_DIR}/__build_time"
    
    src_files = [el[2:] for el in __get_files_recursive(f"{ENGINE_DIR}")]
    objs_files = [f"{ENGINE_BUILD_DIR[2:]}/{el.split(_)[-1].replace('.cpp', '.o')}" for el in src_files]

    for idx, el in enumerate(src_files):
        if __modifid(f"./{el}") or not __exists(f"./{objs_files[idx]}"):
            __execute(f"{CC} {CCFLAGS} {ILIBS} -c {el} -o {objs_files[idx]}")

    __execute(f"{CC} {DLLFLAGS} {CCFLAGS} {ILIBS} {LDFLAGS} {LDLIBS} {' '.join(objs_files)} -o {BIN_DIR}/{DLL_NAME}")
    __LastBuildTime.update()


def game(spec : str):
    GAME_DIR = f"{SRC_DIR}/Game"
    GAME_BUILD_DIR = f"{BUILD_DIR}/Game"
    __LastBuildTime.build_time_file_name = f"{GAME_BUILD_DIR}/__build_time"

    src_files = [el[2:] for el in __get_files_recursive(f"{GAME_DIR}")]
    objs_files = [f"{GAME_BUILD_DIR[2:]}/{el.split(_)[-1].replace('.cpp', '.o')}" for el in src_files]

    for idx, el in enumerate(src_files):
        if __modifid(f"./{el}") or not __exists(f"./{objs_files[idx]}"):
            __execute(f"{CC} {CCFLAGS} -I./src/Engine {ILIBS} -c {el} -o {objs_files[idx]}")

    __execute(f"{CC} {CCFLAGS} -I{IMGUI_PATH} -I./src/Engine -L./bin -lengine -limgui {' '.join(objs_files)} -o {BIN_DIR}/{OBJ_NAME}")
    __LastBuildTime.update()


def imgui(spec: str):
    IMGUI_BUILD_DIR = f"{IMGUI_PATH}/build"

    if not os.path.isdir(IMGUI_BUILD_DIR):
        os.makedirs(IMGUI_BUILD_DIR)

    src_files = [el[2:] for el in __get_files_recursive(f"{IMGUI_PATH}")]
    objs_files = [f"{IMGUI_BUILD_DIR[2:]}/{el.split(_)[-1].replace('.cpp', '.o')}" for el in src_files]

    for idx, el in enumerate(src_files):
        __execute(f"{CC} {CCFLAGS} -c {el} -o {objs_files[idx]}")

    extension = "dylib" if not os.name == "ot" else "dll"
    __execute(f"{CC} {DLLFLAGS} {CCFLAGS} -I{GLFW_PATH}/include {GLFW_LIB} {OPENGL_LIB} {' '.join(objs_files)} -o {BIN_DIR}/libimgui.{extension}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("action", type=str, default="all", nargs="?")
    parser.add_argument("spec", type=str, default="", nargs="?")
    args = parser.parse_args()
    funs = locals()
    if args.action in funs: 
        funs[args.action](args.spec)
    else: 
        logging.error(f"Action '{args.action}' doesn't declared")
