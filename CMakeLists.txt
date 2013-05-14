project( Pyro )

cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -Wall)

find_package(SDL)

include_directories(${SDL_INCLUDE_DIR})

add_executable( pyro main.cpp subsystem.cpp
  cmdargs/cmdargs.cpp
  filesystem/filesystem.cpp
  input/input.cpp
  log/log.cpp
  sdl/sdl.cpp
)
target_link_libraries( pyro ${SDL_LIBRARY})