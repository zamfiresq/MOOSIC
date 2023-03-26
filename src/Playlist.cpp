//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#include "../headers/Playlist.h"


Playlist::Playlist() {
    this -> title = "numeObisnuit";
    this -> nrSongs = 0;
    this -> songs = nullptr;
    this -> nrAlbums = 0;
    this -> albums = nullptr;
    this -> duration = 0;
}

[[maybe_unused]] Playlist::Playlist(const myString& title, Song *songs, const int& nrSongs, Album *albums, const int& nrAlbums, const int& duration){
    this -> title = title;
    this -> nrSongs = nrSongs;
    this -> nrAlbums = nrAlbums;
    this -> duration = duration;

    if (nrSongs > 0 && songs != nullptr) {
        this -> songs = new Song[nrSongs];

        for (int i = 0; i < nrSongs; i++)
            (this -> songs)[i] = songs[i];
    } else {
        this -> nrSongs = 0;
        this -> songs = nullptr;
    }

    if (nrAlbums > 0 && albums != nullptr) {
        this -> albums = new Album[nrAlbums];

        for (int i = 0; i < nrAlbums; i++)
            (this -> albums)[i] = albums[i];
    } else {
        this -> nrAlbums = 0;
        this -> albums = nullptr;
    }
}

//apeland constructorul de copiere, se apeleaza constructorul de copiere al clasei Song si Album
Playlist::Playlist(const Playlist &object){
    this -> title = object.title;
    this -> nrSongs = object.nrSongs;
    this -> nrAlbums = object.nrAlbums;
    this -> duration = object.duration;

    if (object.nrSongs > 0) {
        this -> songs = new Song[object.nrSongs];

        for (int i = 0; i < object.nrSongs; i++)
            this -> songs[i] = object.songs[i];
    } else {
        this -> nrSongs = 0;
        this -> songs = nullptr;
    }

    if (object.nrAlbums > 0) {
        this -> albums = new Album[object.nrAlbums];

        for (int i = 0; i < object.nrAlbums; i++)
            this -> albums[i] = object.albums[i];
    } else {
        this -> nrAlbums = 0;
        this -> albums = nullptr;
    }
}

//apelam destructorul pentru a nu avea probleme cu alocarea memoriei
Playlist::~Playlist() {
    if (songs != nullptr)
        delete []songs;
    if (albums != nullptr)
        delete []albums;
}

//afisam playlist-ul
void Playlist::afisare() const {
    std::cout << title << " " << nrSongs << " " << nrAlbums << " " << duration << "\n";

    for(int i = 0; i < nrSongs; i++)
         std::cout<< songs[i] << " ";
    std::cout << "\n";

    for(int i = 0; i < nrAlbums; i++)
        std::cout << albums[i] << " ";
    std::cout << "\n";
}

//adaugam o melodie in playlist
void Playlist::addSong(const Song& song) {
    Song *mel = new Song[nrSongs + 1]; //mel reprezinta un vector de melodii cu nrSongs +1 melodii
    for (int i = 0; i < nrSongs; i++)
        mel[i] = songs[i]; //copiem toate melodiile din vectorul songs in mel

    mel[nrSongs] = song; //adaugam melodia noua in vectorul mel
    nrSongs++;

    if (songs != nullptr) //daca vectorul songs nu este gol, il vom sterge
        delete []songs;

    songs = mel;
}

//adaugam un album in playlist
void Playlist::addAlbum(const Album& album) {
    Album *album1 = new Album[nrAlbums + 1]; //album1 reprezinta un vector de albume cu nrAlbums +1 albume
    for (int i = 0; i < nrAlbums; i++)
        album1[i] = albums[i]; //copiem toate albumele din vectorul albums in album1

    album1[nrAlbums] = album; //adaugam albumul nou in vectorul album1
    nrAlbums++;

    if (albums != nullptr) //daca vectorul albums nu este gol, il vom sterge
        delete []albums;

    albums = album1; //daca melodia din vectorul songs nu este egala cu melodia pe care vrem sa o stergem, o copiem in album1
}


//stergem o melodie din playlist
void Playlist::removeSong(Song &song) {
    Song *mel = new Song[nrSongs - 1]; //mel reprezinta un vector de melodii cu nrSongs -1 melodii
    int j = 0;
    for (int i = 0; i < nrSongs; i++) { //daca melodia din vectorul songs nu este egala cu melodia pe care vrem sa o stergem, o copiem in mel
        if (songs[i] != song) {
            mel[j] = songs[i];
            j++;
        }
    }
    nrSongs--;

    if (songs != nullptr) //daca vectorul songs nu este gol, il vom sterge
        delete[]songs;

    songs = mel;
}

//stergem un album din playlist
void Playlist::removeAlbum(Album &album) {
    Album *album1 = new Album[nrAlbums - 1]; //album1 reprezinta un vector de albume cu nrAlbums -1 albume
    int j = 0;
    for (int i = 0; i < nrAlbums; i++) { //daca albumul din vectorul albums nu este egal cu albumul pe care vrem sa il stergem, il copiem in album1
        if ( albums[i] != album) {
            album1[j] = albums[i];
            j++;
        }
    }
    nrAlbums--;

    if (albums != nullptr) //daca vectorul albums nu este gol, il vom sterge
        delete[]albums;

    albums = album1;
}

//returnam numele playlist-ului
myString Playlist::getTitle() const {
    return title;
}

//returnam numarul de melodii din playlist
int Playlist::getNrSongs() const {
    return nrSongs;
}

//returnam numarul de albume din playlist
int Playlist::getNrAlbums() const {
    return nrAlbums;
}

//returnam durata playlist-ului
int Playlist::getDuration() const {
    return duration;
}

//returnam vectorul de melodii
Song* Playlist::getSongs() const {
    return songs;
}

//returnam vectorul de albume
Album* Playlist::getAlbums() const {
    return albums;
}

//retunam functia ce modifica numele playlist-ului
void Playlist::changeTitle(const myString &title) {
    this -> title = title;
}

//returnam functia pentru sortare
void Playlist::sort(const myString& title){
    int i, j;
    Song aux; //aux reprezinta o melodie auxiliara
    for (i = 0; i < nrSongs; i++)
         for(j = i + 1; j < nrSongs; j++)
            if (songs[i] == songs[j]) { //daca melodiile sunt egale, le interschimbam
                aux = songs[i];
                songs[i] = songs[j];
                songs[j] = aux;
            }
    }

//functia pentru cautare
void Playlist::search(const myString &title) {
    for (int i = 0; i < nrSongs; i++)
        if (songs[i].getTitle() == title) //daca melodia cautata este egala cu melodia din vectorul songs, o afisam
            std::cout << songs[i] << "\n";
}


//functii pentru play, pause, next, previous, repeat, repeat one, shuffle
void Playlist::play()const {
    std::cout << "Playing " << title << "\n";
}

void Playlist::pause()const {
    std::cout << "Paused " << title << "\n";
}

void Playlist::next()const {
    std::cout << "Next " << title << "\n";
}

void Playlist::previous()const {
    std::cout << "Previous " << title << "\n";
}

void Playlist::repeat()const {
    std::cout << "Repeat " << title << "\n";
}

void Playlist::repeatOne()const {
    std::cout << "Repeat one " << title << "\n";
}

void Playlist::shuffle()const {
    std::cout << "Shuffle " << title << "\n";
}




