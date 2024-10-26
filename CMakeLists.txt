cmake_minimum_required(VERSION 3.7)

if(${CMAKE_VERSION} VERSION_LESS 3.29)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.29)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(LIBS_FOLDER ${PROJECT_SOURCE_DIR}/libs)

project(overcyde-engine)
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/glm)
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/spdlog)
#add_subdirectory(${PROJECT_SOURCE_DIR}/libs/glew/build/cmake)

# file(GLOB_RECURSE SOURCES "src/Engine/*")
# add_library(overcyde-engine ${SOURCES})
# target_include_directories(overcyde-engine PUBLIC include)
# target_link_libraries(overcyde-engine PUBLIC glfw glm spdlog)

file(GLOB CPP_SOURCES "${CMAKE_SOURCE_DIR}/examples/*.cpp")
add_executable(main ${CPP_SOURCES})
target_link_libraries(main PUBLIC)