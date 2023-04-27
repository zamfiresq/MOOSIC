//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#include "../headers/Playlist.h"


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

//    if (object.nrSongs > 0) {
//        this -> songs = new Song[object.nrSongs];
//
//        for (int i = 0; i < object.nrSongs; i++)
//            this -> songs[i] = object.songs[i];
//    } else {
//        this -> nrSongs = 0;
//        this -> songs = nullptr;
//    }
//
//    if (object.nrAlbums > 0) {
//        this -> albums = new Album[object.nrAlbums];
//
//        for (int i = 0; i < object.nrAlbums; i++)
//            this -> albums[i] = object.albums[i];
//    } else {
//        this -> nrAlbums = 0;
//        this -> albums = nullptr;
//    }
//} //am comentat secventele de cod unde am alocat dinamic manual


//apelam destructorul pentru a nu avea probleme cu alocarea memoriei
        Playlist::~Playlist() {}
            //comentez alocarile dinamice facute manual
//    if (songs != nullptr)
//        delete []songs;
//    if (albums != nullptr)
//        delete []albums;


//afisam playlist-ul
        void Playlist::afisare() const {
            std::cout << title << " " << nrSongs << " " << duration << "\n\n";

            if (nrSongs) {
                std::cout << "Melodii:\n";
                for (int i = 0; i < nrSongs; i++)
                    std::cout << i + 1 << ". " << songs[i];
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
                    out << i + 1 << ". " << playlist.songs[i];
                out << "\n";
            }
            out << "\n";
            return out;
        }

//
////adaugam o melodie in playlist
//        void Playlist::addSong(const std::vector<Song> &song) {
//            Song *mel = new Song[nrSongs + 1]; //mel reprezinta un vector de melodii cu nrSongs +1 melodii
//            for (int i = 0; i < nrSongs; i++)
//                mel[i] = songs[i]; //copiem toate melodiile din vectorul songs in mel
//
//            mel[nrSongs] = song; //adaugam melodia noua in vectorul mel
//            nrSongs++;
//
////            if (songs != nullptr) //daca vectorul songs nu este gol, il vom sterge
////                delete[]songs;
////            songs = new Song[nrSongs];
//
//            for (int i = 0; i < nrSongs; i++)
//                songs[i] = mel[i];
//        }
//
//adaugam un album in playlist
void Playlist::addAlbum(const std::vector<Album>&albume) {
    for(auto album : albume) {
        std::vector<Song> melodii = album.getSongs();
        songs.insert(songs.end(), melodii.begin(), melodii.end());
        nrSongs = songs.size();
//        songs.insert(songs.end(), (album.getSongs()).begin(), (album.getSongs()).end());
    }
}
//
//
////stergem o melodie din playlist
//        void Playlist::removeSong(std::vector<Song> &song) {
//            std::vector<Song>mel = {nrSongs - 1}; //mel reprezinta un vector de melodii cu nrSongs -1 melodii
//            int j = 0;
//            for (int i = 0; i <nrSongs; i++) //daca melodia din vectorul songs nu este egala cu melodia pe care vrem sa o stergem, o copiem in mel
//                if (songs[i] != song)
//                    mel[j++] = songs[i];
//            nrSongs--;
//
////            if (songs != nullptr) //daca vectorul songs nu este gol, il vom sterge
////                delete[]songs;
////            songs = new Song[nrSongs];
//
//            for (int i = 0; i < nrSongs; i++)
//                songs[i] = mel[i];
//        }
//
////stergem un album din playlist
//        void Playlist::removeAlbum(std::vector<Album> &album) {
//            std::vector<Album> *album1 = {nrAlbums - 1}; //album1 reprezinta un vector de albume cu nrAlbums -1 albume
//            int j = 0;
//            for (int i = 0; i <nrAlbums; i++) //daca albumul din vectorul albums nu este egal cu albumul pe care vrem sa il stergem, il copiem in album1
//                if (albums[i] != album)
//                    album1[j++] = albums[i];
//            nrAlbums--;
//
////            if (albums != nullptr) //daca vectorul albums nu este gol, il vom sterge
////                delete[]albums;
////            albums = new Album[nrAlbums];
//
//            for (int i = 0; i < nrAlbums; i++)
//                albums[i] = album1[i];
//        }

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
        void Playlist::sort() {
            int i, j;
            Song aux; //aux reprezinta o melodie auxiliara
            for (i = 0; i < nrSongs; i++)
                for (j = i + 1; j < nrSongs; j++) {
                    std::string titluI = songs[i].getTitle();
                    std::string titluJ = songs[j].getTitle();
                    if (titluI > titluJ) {
                        aux = songs[i];
                        songs[i] = songs[j];
                        songs[j] = aux;
                    }
                }
        }

//functia pentru cautare
        void Playlist::search(const std::string &title) {
            for (int i = 0; i < nrSongs; i++)
                if (songs[i].getTitle() ==
                    title) //daca melodia cautata este egala cu melodia din vectorul songs, o afisam
                    std::cout << songs[i] << "\n";
        }


//functii pentru play, pause, next, previous, repeat, repeat one, shuffle
        void Playlist::play(int i) const {
            std::cout << "Playing " << songs[i].getTitle() << "\n";
        }

        void Playlist::pause(int i) const {
            std::cout << "Paused " << songs[i].getTitle() << "\n";
        }

        int Playlist::next(int i) const {
            if (i + 1 > nrSongs)
                i = -1;
            std::cout << "Playing next " << songs[++i].getTitle() << "\n";
            return i;
        }

        int Playlist::previous(int i) const {
            if (i - 1 < 0)
                i = nrSongs;
            std::cout << "Playing previous " << songs[--i] << "\n";
            return i;
        }


        int Playlist::repeatOne(int i) const {
            std::cout << "Repeating " << songs[--i].getTitle() << "\n";
            return i;
        }

//void Playlist::repeat()const {
//    std::cout << "Repeat " << title << "\n";
//}

        void Playlist::shuffleSongs() {
//urmeaza un randomizer pentru a shuffle-ui melodiile din playlist
            int i, j;
            Song aux; //aux reprezinta o melodie auxiliara
            for (i = 0; i < nrSongs; i++)
                for (j = i + 1; j < nrSongs; j++) {
                    int random = rand() % 2; //random va lua valori de la 0 la 1
                    if (random == 1) {
                        aux = songs[i];
                        songs[i] = songs[j];
                        songs[j] = aux;
                    }
                }
        }

        void Playlist::shuffle() {
            std::cout << "Shuffling " << title << "\n";
            shuffleSongs();
        }



        std::vector<Song>::iterator Playlist::begin() { //iteratorul pentru vectorul de melodii
            return songs.begin();
        }

        std::vector<Song>::iterator Playlist::end() { //iteratorul pentru vectorul de melodii
            return songs.end();
        }
