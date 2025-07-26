//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#include "../headers/Playlist.h"
#include "../headers/Exceptions.h"
#include "../headers/Interfata.h"
//#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>


Playlist::Playlist() {
    this -> title = "titluDefaultPlaylist";
    this -> nrSongs = 0;
    this -> duration = 0;
    this -> songs = {};
}

Playlist::Playlist(const std::string& title, std::vector<Song>&songs, const int& nrSongs, const int& duration){
    this->title = title;
    this->nrSongs = nrSongs;
    this->duration = duration;
    this->songs = songs;
}

//apeland constructorul de copiere, se apeleaza constructorul de copiere al clasei Song si Album
Playlist::Playlist(const Playlist &object){
        this->title = object.title;
        this->nrSongs = object.nrSongs;
        this->duration = object.duration;
        this->songs = object.songs;
    }

// constructor cu id si titlu
Playlist::Playlist(int id, const std::string& title) {
    this->id = id;
    this->title = title;
    this->nrSongs = 0;
    this->duration = 0;
    this->songs = {};
}


//apelam destructorul pentru a nu avea probleme cu alocarea memoriei
        Playlist::~Playlist() {}

//afisam playlist-ul
        void Playlist::afisare() const {
            std::cout << title << " " << nrSongs << " " << duration << "\n\n";

            if (nrSongs) {
                std::cout << "Melodii:\n";
                for (int i = 0; i < nrSongs; i++)
                    std::cout << i + 1 << ". " << songs[i] << "\n";
                std::cout << "\n";
            }
            std::cout << "\n";
        }


//supraincarcarea operatorului <<
        std::ostream &operator<<(std::ostream &out, const Playlist &playlist) {
            out << playlist.title << " " << playlist.nrSongs << " " << playlist.duration
                << "\n\n";

            if (playlist.nrSongs) {
                out << "Melodii:\n";
                for (int i = 0; i < playlist.nrSongs; i++)
                    out << i + 1 << ". " << playlist.songs[i] << "\n";
                out << "\n";
            }
            out << "\n";
            return out;
        }

//
void Playlist::addSong(const Song& song) {
        for (const auto &s: songs) {
            if (s.getTitle() == song.getTitle() && s.getArtistName() == song.getArtistName()) {
                //exceptie melodia exista deja
//                throw SongAlreadyExists(song);
                std::cout << "Melodia exista deja\n";
                return;
            }
        }
        songs.push_back(song);
        nrSongs++;
        duration += song.getDuration();
        std::cout << "'" << song.getTitle() << "'" << " was successfully added to your playlist.\n";
}



//adaugam un album in playlist
//void Playlist::addAlbum(const std::vector<Album>&albume) {
//    for(auto album : albume) {
//        std::vector<Song> melodii = album.getSongs();
//        songs.insert(songs.end(), melodii.begin(), melodii.end());
//        nrSongs = songs.size();
////        songs.insert(songs.end(), (album.getSongs()).begin(), (album.getSongs()).end());
//    }
//}
//
//
//stergem o melodie din playlist
void Playlist::removeSong(Song& song) {
    auto iterator = find((this->songs).begin(), (this->songs).end(), song);
    if (songs.empty() || iterator == songs.end()) {
        std::cout << "Melodia nu a fost gasita\n";
        return;
    }
    songs.erase(iterator);
    nrSongs--;
    std::cout << "'" << song.getTitle() << "'" << " was successfully removed from your playlist.\n";
}

//
////stergem un album din playlist
//        void Playlist::removeAlbum(std::vector<Album> &album) {
//            for(auto a : album) {



//returnam numele playlist-ului
        std::string Playlist::getTitle() const {
            return title;
        }

//returnam numarul de melodii din playlist
        int Playlist::getNrSongs() const {
            return nrSongs;
        }

//returnam durata playlist-ului
        int Playlist::getDuration() const {
            return duration;
        }

//returnam vectorul de melodii
        std::vector<Song>Playlist::getSongs() const {
            return songs;
        }

//retunam functia ce modifica numele playlist-ului
        void Playlist::changeTitle(const std::string &title) {
            this->title = title;
        }

//returnam functia pentru sortare
        void Playlist::sortAfterSongTitle() {
            sort((this->songs).begin(),(this->songs).end(),[](const Song &s1, const Song &s2){
                return s1.getTitle() < s2.getTitle();
            });
        }



void Playlist::sortAfterArtistName() {
    sort((this->songs).begin(),(this->songs).end(),[](const Song &a1, const Song &a2){
        return a1.getArtistName() < a2.getArtistName();
    });
}

//functia pentru cautare
        void Playlist::search(const std::string &title) {
            for (int i = 0; i < nrSongs; i++)
                if (songs[i].getTitle() == title) //daca melodia cautata este egala cu melodia din vectorul songs, o afisam
                    std::cout << songs[i] << "\n";
        }


//functii pentru play, pause, next, previous, repeat, repeat one, shuffle
//        void Playlist::play(int i) const {
//            std::cout << "Playing " << songs[i].getTitle() << "\n";
//        }
//
//        void Playlist::pause(int i) const {
//            std::cout << "Paused " << songs[i].getTitle() << "\n";
//        }
//
//        int Playlist::next(int i) const {
//            if (i + 1 > nrSongs)
//                i = -1;
//            std::cout << "Playing next " << songs[++i].getTitle() << "\n";
//            return i;
//        }
//
//        int Playlist::previous(int i) const {
//            if (i - 1 < 0)
//                i = nrSongs;
//            std::cout << "Playing previous " << songs[--i] << "\n";
//            return i;
//        }


        int Playlist::repeatOne(int i) const {
            if (i <= 0 || i > songs.size()) {
                std::cout << "Invalid index.\n";
                return -1;
            }
            std::cout << "Repeating " << songs[i - 1].getTitle() << "\n";
            return i - 1;
        }

//void Playlist::repeat()const {
//    std::cout << "Repeat " << title << "\n";
//}

//        void Playlist::shuffleSongs() {
////urmeaza un randomizer pentru a shuffle-ui melodiile din playlist
//            int i, j;
//            Song aux; //aux reprezinta o melodie auxiliara
//            for (i = 0; i < nrSongs; i++)
//                for (j = i + 1; j < nrSongs; j++) {
//                    int random = rand() % 2; //random va lua valori de la 0 la 1
//                    if (random == 1) {
//                        aux = songs[i];
//                        songs[i] = songs[j];
//                        songs[j] = aux;
//                    }
//                }
//        }
//
//        void Playlist::shuffle() {
//            std::cout << "Shuffling " << title << "\n";
//            shuffleSongs();
//        }


// Constructor that initializes only the title
Playlist::Playlist(const std::string& title) {
    this->title = title;
    this->nrSongs = 0;
    this->duration = 0;
    this->songs = {};
}