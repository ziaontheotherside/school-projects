cmake_minimum_required(VERSION 3.23)
project(MusicPlayer)

set(CMAKE_CXX_STANDARD 14)

add_executable(MusicPlayer MusicPlayer.cpp Song.cpp Playlist.cpp proj3.cpp)
