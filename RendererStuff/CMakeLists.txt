cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -Wall -std=c++14")

option(DEBUG_BUILD "Builds a debug executable" OFF)

project(render)


file(GLOB SOURCES src/*.cpp src/*.c src/*.h src/*.hpp src/vendor/stb_image/*.cpp src/vendor/imgui/*.cpp)


if (DEBUG_BUILD)
add_definitions(-D_DEBUG)
endif (DEBUG_BUILD)


add_executable( ${PROJECT_NAME} ${SOURCES} )

target_include_directories(${PROJECT_NAME} PRIVATE src/vendor/)

include_directories(vendor/)
target_link_libraries(${PROJECT_NAME} GLEW glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt pthread dl)
