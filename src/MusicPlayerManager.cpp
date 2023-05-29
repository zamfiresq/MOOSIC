//
// Created by Alexandra Zamfirescu on 29.05.2023.
//

#include "../headers/MusicPlayerManager.h"
#include "../headers/Playlist.h"
#include "../headers/Song.h"


void MusicPlayerManager::volumPlus() {
    int volum1;
    std::cout << "Introduceți volumul curent: ";
    std::cin >> volum1;

    while (volum1 < 100 && volum1 > 0) {
        volum1 += 1;
        std::cout << "Volum crescut la: " << volum1 << "\n";
        std::cout << "Apăsați o tastă pentru a crește volumul sau 'q' pentru a ieși.\n";

        //de cate ori se va apasa o tasta, volumul va creste cu 1
        char input; // aici se va citi input-ul de la tastatura
        std::cin >> input;
        if (input == 'q') // daca input-ul este 'q', iese din while
            break;
    }
    std::cout << "Volumul este deja la maxim.\n";
}


void MusicPlayerManager::volumMinus() {
    int volum2;
    std::cout << "Introduceți volumul curent: ";
    std::cin >> volum2;

    while (volum2 > 0 && volum2 < 100) {
        volum2 -= 1;
        std::cout << "Volum scăzut la: " << volum2 << "\n";
        std::cout << "Apăsați o tastă pentru a scade volumul sau 'q' pentru a ieși.\n";

        //de cate ori se va apasa o tasta, volumul va scade cu 1
        char input; // aici se va citi input-ul de la tastatura
        std::cin >> input;
        if (input == 'q') // daca input-ul este 'q', iese din while
            break;
    }
    std::cout << "Volumul este deja minim8.\n";
}

void MusicPlayerManager::addSongToPlaylist(const Song& song, Playlist& playlist) {
    playlist.addSong(song);
}

void MusicPlayerManager::removeSongFromPlaylist(Song& song, Playlist& playlist) {
    playlist.removeSong(song);
}

void MusicPlayerManager::play() const {

    std::cout << "Playing " << "\n";
}

void MusicPlayerManager::pause() const {
    std::cout << "Paused " << "\n";
}

int MusicPlayerManager::next(int idx){
    std::vector<Song*> song;
    if(song.empty()){
        std::cout << "Playlist is empty.\n";
    return -1;
    }
    int nextSongIndex = (idx + 1) % song.size();
    std::cout << "Playing next " << song[nextSongIndex]->getTitle() << "\n";
    return nextSongIndex;
}

int MusicPlayerManager::previous(int idx){
    std::vector<Song*> song;
    if(song.empty()){
        std::cout << "Playlist is empty.\n";
        return -1;
    }
    int previousSongIndex = (idx - 1) % song.size();
    std::cout << "Playing previous " << song[previousSongIndex]->getTitle() << "\n";
    return previousSongIndex;
}

void MusicPlayerManager::repeatOne() {
    std::vector<Playlist*> playlist;
    Song* melodieCurenta;
    bool isRepeatOne = true;

    for(int i=0; i<playlist.size(); i++){
        if(isRepeatOne){
            std::cout << "Mod repetare activat pentru melodia curenta: " << melodieCurenta->getTitle() << "\n";
        } else {
            std::cout << "Mod repetare dezactivat" << "\n";
        }
        }
    }

void MusicPlayerManager::shuffle() {
    std::vector<Playlist*> playlist;
    std::random_device rd;                        //obtinem un numar random
    std::mt19937 generator(rd());                  // initializeaza generatorul cu valoarea random
    std::shuffle(playlist.begin(), playlist.end(), generator);  // amestecam melodiile din playlist

    std::cout << "Playlist-ul a fost amestecat cu succes!" << "\n";
}



MusicPlayerManager* MusicPlayerManager:: instance = nullptr;

