//
// Created by Alexandra Zamfirescu on 23.03.2023.
//


#ifndef OOP_PROJECT_PLAYLIST_H
#define OOP_PROJECT_PLAYLIST_H
#include <iostream>
#include <string>
#include<vector>
#include "Song.h"
#include "Album.h"

class Playlist {
    std::string title; //titlul playlist-ului
    std::vector<Song> songs; //vectorul de melodii
    int nrSongs; //numarul de melodii
    std::vector<Album> albums; //vectorul de albume
    int nrAlbums; //numarul de albume
    int duration;  //durata playlist-ului

public:
    //constructor fara parametri
    Playlist();
    //constructor cu parametri
    Playlist(const std::string& title, std::vector<Song>&songs, const int& nrSongs, std::vector<Album>&albums, const int& nrAlbums, const int& duration);
    //copy constructor
    Playlist(const Playlist &other);
    //destructor
    ~Playlist();


    //functie de afisare
    virtual void afisare() const;

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

//    //supraincarcarea operatorului ==
//    bool operator == (const Playlist &other) {
//        if(this -> title == other.title && this -> songs == other.songs && this -> nrSongs == other.nrSongs  && this -> nrAlbums == other.nrAlbums && this -> duration == other.duration && this -> albums == other.albums)
//            return true;
//        else
//            return false;
//    }
//
//    //supraincarcarea operatorului !=
//    bool operator != (const Playlist &other) {
//        if(this -> title != other.title || this -> nrSongs != other.nrSongs || this -> nrAlbums != other.nrAlbums || this -> duration != other.duration)
//            return true;
//        else
//            return false;
//    }

//supraincarcarea operatorului <<
    friend std::ostream& operator << (std::ostream& out, const Playlist& playlist);

    //getters
    std::string getTitle() const;
    std::vector<Song> getSongs() const;
    int getNrSongs() const;
    std::vector<Album> getAlbums() const;
    int getNrAlbums() const;
    int getDuration() const;

    //functii pentru adaugarea unei melodii in playlist
    void addSong(const std::vector<Song>& song);

    //functii pentru adaugarea unui album in playlist
    void addAlbum(const std::vector<Album> &album);

    //functii pentru stergerea unei melodii din playlist
    void removeSong(std::vector<Song> &song);

    //functii pentru stergerea unui album din playlist
    void removeAlbum(std::vector<Album> &album);

    //functii pentru modificarea numelui playlist-ului
    void changeTitle(const std::string& title);

    //functii pentru sortare
    void sort();

    //functii pentru cautare
    void search( const std::string& title);

    //alte functii utile pentru playlist
    void play(int i) const; //reda playlist-ul
    void pause(int i) const; //pune pauza
    int next(int i) const; //trec la urmatoarea melodie
    int previous(int i) const; //trec la melodia anterioara
    void repeat() const; //repeta playlist-ul
    int repeatOne(int i) const; //repeta melodia curenta
    void shuffle(); //reda melodii aleator
    void shuffleSongs();

    std::vector<Song>::iterator begin();
    std::vector<Song>::iterator end();

};



//mosteniri - le fac in fisiere separate pe calea "Playlist.h"

#endif //OOP_PROJECT_PLAYLIST_H
