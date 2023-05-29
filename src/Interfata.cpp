//
// Created by Alexandra Zamfirescu on 01.05.2023.
//

#include "../headers/Interfata.h"

//partea de interfata
//playlist
InterfataPlaylist::~InterfataPlaylist()=default;

void IPlaylist::play() {
    std::cout << "Playing song\n";
}

void IPlaylist::pause() {
    std::cout << "Paused song\n";
}


//song
InterfataSong::~InterfataSong()=default;

void ISong::play() {
    std::cout << "Playing \n\n";
}

void ISong::pause() {
    std::cout << "Paused \n\n";
}

void ISong::afisare() {
    std::cout << "Afisare: \n\n";
}





//CLASA ABSTRACTA

absPlaylist::~absPlaylist()=default;

int AbsPlaylist::nextSong(int currentSongIndex) {
    if (songs.empty()) {
        std::cout << "Playlist is empty.\n";
        return -1;
    }

    int nextSongIndex = (currentSongIndex + 1) % songs.size();
    std::cout << "Playing next " << songs[nextSongIndex].getTitle() << "\n";
    return nextSongIndex;
}

void AbsPlaylist::addSong(const Song& song) {
    songs.push_back(song);
    nrSongs = songs.size();
}

void absPlaylist::addSong(const Song& song) {
    songs.push_back(song);
    nrSongs = songs.size();

}
