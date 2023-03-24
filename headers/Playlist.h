//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#ifndef OOP_PROJECT_PLAYLIST_H
#define OOP_PROJECT_PLAYLIST_H
#include <iostream>
#include "Song.h"
#include "Album.h"

class Playlist {
    std::string title;
    Song *songs;
    int nrSongs;
    Album *albums;
    int nrAlbums;
    int duration;

public:
    //constructor fara parametri
    Playlist();
    //constructor cu parametri
    Playlist(const std::string& title, Song *songs, const int& nrSongs, Album *albums, const int& nrAlbums, const int& duration);
    //copy constructor
    Playlist(const Playlist &other);
    //destructor
    ~Playlist();

    //functie de afisare
    void afisare() const;

    //getters
    std::string getTitle() const;
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
    void changeTitle(const std::string& title);

    //functii pentru sortare
    void sort( const std::string& title);

    //functii pentru cautare
    void search( const std::string& title);

    //alte functii utile pentru playlist
    void play() const;
    void pause() const;
    void next() const;
    void previous() const;
    void repeat() const;
    void repeatOne() const;
    void shuffle() const;

//    //supraincarcare operator de atribuire
//    Playlist& operator = (const Playlist& other);
//
//    //supraincarcare operator de afisare
//    friend std::ostream& operator << (std::ostream &out, const Playlist& playlist);
//
//
////supraincarcam operatorul de afisare
//    std::ostream& operator<<(std::ostream& out, const Playlist &playlist) {
//        out << playlist.title << " " << playlist.nrSongs << " " << playlist.nrAlbums << " " << playlist.duration << "\n";
//
//        for(int i = 0; i < playlist.nrSongs; i++)
//            out<< playlist.songs[i] << " ";
//        out << "\n";
//    }
//
////operatorul = pentru a copia un playlist in altul
//    Playlist& operator = (const Playlist playlist) {
//        if (this != &playlist) {
//            this -> title = playlist.title;
//            this -> nrSongs = playlist.nrSongs;
//            this -> nrAlbums = playlist.nrAlbums;
//            this -> duration = playlist.duration;
//
//            if (playlist.nrSongs > 0) {
//                this -> songs = new Song[playlist.nrSongs];
//
//                for (int i = 0; i < playlist.nrSongs; i++)
//                    this -> songs[i] = playlist.songs[i];
//            } else {
//                this -> nrSongs = 0;
//                this -> songs = nullptr;
//            }
//
//            if (playlist.nrAlbums > 0) {
//                this -> albums = new Album[playlist.nrAlbums];
//
//                for (int i = 0; i < playlist.nrAlbums; i++)
//                    this -> albums[i] = playlist.albums[i];
//            } else {
//                this -> nrAlbums = 0;
//                this -> albums = nullptr;
//            }
//        }
//
//        return *this;
//};

};

#endif //OOP_PROJECT_PLAYLIST_H
