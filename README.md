# OverCyde Engine (not official name)
OverCyde game engine made from scratch in c++ with OpenGL to support the deploy of OverCyde's game. 

## Installation

### Clonning
For firt clone the reposiory with submodule with:
```
git clone --recurse-submodules https://github.com/bigmat18/OverCyde.git
```
In the repo there are the .dll and .dylib of GLFW and GLEW libs and re submodules of spdlib, glm and stl.

### Building

#### Makefile
To build all project (engine and game)
```
make buid_all
```
Build only engine (this ceate .dylib or .dll):
```
make buid_engine
```
Build only game:
```
make buid_game
```

#### Python script
To build all project (engine and game)
```
python ./build.py engine && python ./build.py game 
```
Build only engine (this ceate .dylib or .dll):
```
python ./build.py engine
```
Build only game:
```
python ./build.py game
```