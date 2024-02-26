#!/usr/bin/python3
import argparse
import subprocess
import logging
import os
import datetime
import sys

logging.basicConfig(format="%(asctime)s - %(message)s", level=logging.INFO)

if os.name == 'nt': _ = "\\"
else: _ = "/"

class __LastBuildTime():
    build_time_file_name : str = "__build_time"
    __LAST_BUILD_TIME = None

    @classmethod
    def time(cls) -> str:
        if cls.__LAST_BUILD_TIME == None:
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
        with open(cls.build_time_file_name, "r+") as file:
            cls.__LAST_BUILD_TIME = file.read()
            file.close()

    @classmethod
    def __set_last_build_time(cls):
        with open(cls.build_time_file_name, "w+") as file:
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

OBJ_NAME = "main"                   if not os.name == "nt" else f"{BIN_DIR}/main"
GLEW_LIB = "-lGLEW"                 if not os.name == 'nt' else "-lglew32"
GLFW_LIB = "-lglfw"                 if not os.name == 'nt' else "-lglfw3"
OPENGL_LIB = "-framework OpenGL"    if not os.name == 'nt' else "-lopengl32"
SPDLOG_LIB = "-lspdlog"             if not os.name == 'nt' else ""

GLEW_PATH = f"{LIBS_DIR}/glew"
GLFW_PATH = f"{LIBS_DIR}/glfw"
GLM_PATH = f"{LIBS_DIR}/glm"
SPDLOG_PATH = f"{LIBS_DIR}/spdlog"

CCFLAGS += f"-I{GLEW_PATH}/include -I{GLFW_PATH}/include -I{GLM_PATH} -I{SPDLOG_PATH}/include"
LDFLAGS = f"-L{GLM_PATH} -L{SPDLOG_PATH}/src"
LDLIBS = f"{GLEW_LIB} {GLFW_LIB} {SPDLOG_LIB} -lm -lpthread {OPENGL_LIB}"

if os.name == 'nt': LDFLAGS += f" -L{BIN_DIR}"

def clear():
    for file in os.listdir(f"./{BUILD_DIR}"):
        os.remove(os.path.join(f"./{BUILD_DIR}", file))
        
    if os.path.isfile("main"):
        os.remove("main")
        
    if os.path.isfile("bin/main.exe"):
        os.remove("bin/main.exe")
        
    if os.path.isfile(f"{__LastBuildTime.build_time_file_name}"):
        os.remove(f"{__LastBuildTime.build_time_file_name}")
    
def all():
    exe_files = [el [2:] for el in __get_files(f"{ROOT_DIR}")]
    src_files = [el[2:] for el in __get_files_recursive(f"{SRC_DIR}")]
    objs_files = [f"{BUILD_DIR[2:]}/{el.split(_)[-1].replace('.cpp', '.o')}" for el in src_files]

    src_files += exe_files
    objs_files += [f"{BUILD_DIR[2:]}/{el.replace('.cpp', '.o')}" for el in exe_files]

    for idx, el in enumerate(src_files):
        if __modifid(f"./{el}") or not __exists(f"./{objs_files[idx]}"):
            __execute(f"{CC} {CCFLAGS} -c {el} -o {objs_files[idx]}")

    for el in exe_files:
        __execute(f"{CC} {CCFLAGS} {LDFLAGS} {LDLIBS} {' '.join(objs_files)} -o {OBJ_NAME}")



if __name__ == "__main__":
    if not os.path.isfile("__build_time"):
        logging.error("File __build_time non trovato")
        sys.exit(0)
        
    if not os.path.exists(f"{BUILD_DIR}"):
        logging.error(f"Cartella {BUILD_DIR} non trovato")
        sys.exit(0)
        
    if not os.path.exists(f"{BIN_DIR}"):
        logging.error(f"Cartella {BIN_DIR} non trovato")
        sys.exit(0)
        
    parser = argparse.ArgumentParser()
    parser.add_argument("action", type=str, default="all", nargs="?")
    args = parser.parse_args()
    funs = locals()
    if args.action in funs: funs[args.action]()
    else: logging.error(f"Action '{args.action}' doesn't declared")
    __LastBuildTime.update()

