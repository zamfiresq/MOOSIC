cmake_minimum_required(VERSION 3.24)
project(oop_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_project main.cpp src/Artist.cpp headers/Artist.h src/Album.cpp headers/Album.h src/Song.cpp headers/Song.h src/User.cpp headers/User.h src/Playlist.cpp headers/Playlist.h src/myString.cpp headers/myString.h)
