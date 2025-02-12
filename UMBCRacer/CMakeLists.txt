cmake_minimum_required(VERSION 3.23)
project(UMBCRacer)

set(CMAKE_CXX_STANDARD 14)

add_executable(UMBCRacer proj2.cpp PlayerProj.cpp PlayerProj.h player.cpp Race.cpp Track.cpp test.cpp)
