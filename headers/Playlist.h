//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#ifndef OOP_PROJECT_PLAYLIST_H
#define OOP_PROJECT_PLAYLIST_H
#include <iostream>
#include "myString.h"
#include "Song.h"
#include "Album.h"


class Playlist {
    myString title; //titlul playlist-ului
    Song *songs; //vectorul de melodii
    int nrSongs; //numarul de melodii
    Album *albums; //vectorul de albume
    int nrAlbums; //numarul de albume
    int duration;  //durata playlist-ului

public:
    //constructor fara parametri
    Playlist();
    //constructor cu parametri
    Playlist(const myString& title, Song *songs, const int& nrSongs, Album *albums, const int& nrAlbums, const int& duration);
    //copy constructor
    Playlist(const Playlist &other);
    //destructor
    ~Playlist();

    //functie de afisare
    void afisare() const;

    //supraincarcarea operatorului =
    Playlist& operator = (const Playlist &other) {
        this -> title = other.title;
        this -> songs = other.songs;
        this -> nrSongs = other.nrSongs;
        this -> albums = other.albums;
        this -> nrAlbums = other.nrAlbums;
        this -> duration = other.duration;
        return *this;
    }
    //supraincarcarea operatorului ==
    bool operator == (const Playlist &other) {
        if(this -> title == other.title && this -> nrSongs == other.nrSongs && this -> nrAlbums == other.nrAlbums && this -> duration == other.duration)
            return true;
        else
            return false;
    }

    //supraincarcarea operatorului !=
    bool operator != (const Playlist &other) {
        if(this -> title != other.title || this -> nrSongs != other.nrSongs || this -> nrAlbums != other.nrAlbums || this -> duration != other.duration)
            return true;
        else
            return false;
    }

//supraincarcarea operatorului <<
    friend std::ostream& operator << (std::ostream& out, const Playlist& playlist);

    //getters
    myString getTitle() const;
    Song* getSongs() const;
    int getNrSongs() const;
    Album* getAlbums() const;
    int getNrAlbums() const;
    int getDuration() const;

    //functii pentru adaugarea unei melodii in playlist
    void addSong(const Song& song);

    //functii pentru adaugarea unui album in playlist
    void addAlbum(const Album &album);

    //functii pentru stergerea unei melodii din playlist
    void removeSong(Song &song);

    //functii pentru stergerea unui album din playlist
    void removeAlbum(Album &album);

    //functii pentru modificarea numelui playlist-ului
    void changeTitle(const myString& title);

    //functii pentru sortare
    void sort();

    //functii pentru cautare
    void search( const myString& title);

    //alte functii utile pentru playlist
    void play(int i) const; //reda playlist-ul
    void pause(int i) const; //pune pauza
    int next(int i) const; //trec la urmatoarea melodie
    int previous(int i) const; //trec la melodia anterioara
    void repeat() const; //repeta playlist-ul
    int repeatOne(int i) const; //repeta melodia curenta
    void shuffle(); //reda melodii aleator
    void shuffleSongs();
};

#endif //OOP_PROJECT_PLAYLIST_H
