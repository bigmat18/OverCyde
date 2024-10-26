set(IMGUI_DIR "${PROJECT_SOURCE_DIR}/libs/imgui")

file(GLOB CPP_SOURCES "${IMGUI_DIR}/*.cpp")
add_library(imgui ${CPP_SOURCES})
target_include_directories(imgui PUBLIC ${IMGUI_DIR})
target_link_libraries(imgui PUBLIC glfw)