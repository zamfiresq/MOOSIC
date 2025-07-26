cmake_minimum_required(VERSION 3.24)
project(oop_project)

set(CMAKE_CXX_STANDARD 17)

# fisiere sursa
set(SOURCES
        main.cpp
        src/Artist.cpp
        src/Album.cpp
        src/Song.cpp
        src/User.cpp
        src/Playlist.cpp
        src/myString.cpp
        src/playlistFavorite.cpp
        src/Interfata.cpp
        src/Premium.cpp
        src/premiumUser.cpp
        src/Exceptions.cpp
        src/AgeGroup.cpp
        src/MusicPlayerManager.cpp
)

# executabil
add_executable(oop_project ${SOURCES})

# directorul cu headerele
target_include_directories(oop_project PRIVATE headers)