cmake_minimum_required(VERSION 3.23)
project(UMBC_Starcraft_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(UMBC_Starcraft_4 proj4.cpp Area.cpp Battlecruiser.cpp Entity.cpp Game.cpp Ghost.cpp Hydralisk.cpp Marine.cpp Mutalisk.cpp Terran.cpp Zerg.cpp Zergling.cpp)
