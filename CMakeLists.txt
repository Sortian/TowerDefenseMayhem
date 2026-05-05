cmake_minimum_required(VERSION 3.10)
project(MyGame CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. Tell CMake where to look for your header (.h) files
include_directories(header)

# 2. Gather all source (.cpp) files from the 'source' folder
file(GLOB SOURCES "source/*.cpp")

# 3. Create the executable using the gathered sources
add_executable(game ${SOURCES})

# 4. Find the Raylib package on your Linux system
find_package(raylib REQUIRED)

# 5. Link Raylib to your executable
target_link_libraries(game PRIVATE raylib)

# 6. Copy the assets folder to the build directory so the executable can find it
add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
)