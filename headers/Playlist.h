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
    void afis() const;

    //getters
    std::string getTitle() const;
    Song* getSongs() const;
    int getNrSongs() const;
    Album* getAlbums() const;
    int getNrAlbums() const;
    int getDuration() const;

    //functii pentru adaugarea unei melodii in playlist
    void addSong(const Song& song);
    void addSong(const std::string& title, Song *songs, const int& nrSongs, Album *albums, const int& nrAlbums, const int& duration);

    //functii pentru adaugarea unui album in playlist
    void addAlbum(const Album& album);
    void addAlbum(const std::string& title, Song *songs, const int& nrSongs, Album *albums, const int& nrAlbums, const int& duration);

    //functii pentru stergerea unei melodii din playlist
    void removeSong(Song song);
    void removeSong(const std::string& title, Song *songs, const int& nrSongs, Album *albums, const int& nrAlbums, const int& duration);

    //functii pentru stergerea unui album din playlist
    void removeAlbum(const Album& album);
    void removeAlbum(const std::string& title, Song *songs, const int& nrSongs, Album *albums, const int& nrAlbums, const int& duration);

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

    //supraincarcare operator de atribuire
        Playlist& operator = (const Playlist& other);
    //supraincarcare operator de afisare
        friend std::ostream& operator << (std::ostream& out, const Playlist& playlist);
    //operator !=
        friend bool &operator != (const Playlist& playlist1, const Playlist& playlist2);
};


//operatorul != pentru a verifica daca doua playlist-uri sunt diferite
bool Playlist &operator != (const Playlist& playlist) const {
    if (this -> title != playlist.title)
        return true;
    if (this -> nrSongs != playlist.nrSongs)
        return true;
    if (this -> nrAlbums != playlist.nrAlbums)
        return true;
    if (this -> duration != playlist.duration)
        return true;

    for (int i = 0; i < this -> nrSongs; i++) //verificam daca toate melodile din playlist sunt egale
        if (this -> songs[i] != playlist.songs[i])
            return true;

    for (int i = 0; i < this -> nrAlbums; i++)
        if (this -> albums[i] != playlist.albums[i])
            return true;

    return false; //daca playlist-urile sunt egale, returnam false
}

//supraincarcam operatorul de afisare
std::ostream& operator<<(std::ostream& out, const class Playlist& playlist) {
    out << playlist.title << " " << playlist.nrSongs << " " << playlist.nrAlbums << " " << playlist.duration << "\n";

    for(int i = 0; i < playlist.nrSongs; i++)
        out<< playlist.songs[i] << " ";
    out << "\n";
}

//operatorul = pentru a copia un playlist in altul
Playlist &operator=(const Playlist& playlist) {
    if (this != &playlist) {
        this -> title = playlist.title;
        this -> nrSongs = playlist.nrSongs;
        this -> nrAlbums = playlist.nrAlbums;
        this -> duration = playlist.duration;

        if (playlist.nrSongs > 0) {
            this -> songs = new Song[playlist.nrSongs];

            for (int i = 0; i < playlist.nrSongs; i++)
                this -> songs[i] = playlist.songs[i];
        } else {
            this -> nrSongs = 0;
            this -> songs = nullptr;
        }

        if (playlist.nrAlbums > 0) {
            this -> albums = new Album[playlist.nrAlbums];

            for (int i = 0; i < playlist.nrAlbums; i++)
                this -> albums[i] = playlist.albums[i];
        } else {
            this -> nrAlbums = 0;
            this -> albums = nullptr;
        }
    }

    return *this;
}

void removeAlbum(Album album);

#endif //OOP_PROJECT_PLAYLIST_H
