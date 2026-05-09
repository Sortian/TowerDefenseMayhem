cmake_minimum_required(VERSION 3.10)
project(MyGame CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tell CMake where to look for your header (.h) files
include_directories(header)

# Explicitly list all source files
add_executable(game_executable
    main.cpp
    source/game.cpp
    source/grid.cpp
    source/enemy.cpp
    source/resourceManager.cpp
)

# Find and link Raylib
find_package(raylib REQUIRED)
target_link_libraries(game_executable PRIVATE raylib)

# Copy the assets folder to the build directory
add_custom_command(TARGET game_executable POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
)