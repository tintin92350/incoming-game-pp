# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Project name
project(incoming)

# Output folders
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# External includes
include_directories("${PROJECT_SOURCE_DIR}")

# External libraries
link_directories("${PROJECT_LIB_DIR}")

# Executable
add_executable(incoming ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/Game.cpp ${PROJECT_SOURCE_DIR}/AssetManager.cpp ${PROJECT_SOURCE_DIR}/GSMenu.cpp ${PROJECT_SOURCE_DIR}/GSGame.cpp)

# Link libs
target_link_libraries(incoming sfml-graphics sfml-system sfml-window sfml-network)
