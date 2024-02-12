cmake_minimum_required (VERSION 3.26)
project (my_raylib_game)
set (CMAKE_C_STANDARD 99)

# Finding Raylib
find_package(raylib 2.5.0 REQUIRED) # Requires at least version 2.5.0

# Add list of source files here, or use `file`
add_executable(my_raylib_game main.cpp)

# Link raylib to your project
target_link_libraries(my_raylib_game raylib)
