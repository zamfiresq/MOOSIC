//
// Created by Alexandra Zamfirescu on 26.04.2023.
//

#ifndef OOP_PROJECT_PLAYLISTFAVORITE_H
#define OOP_PROJECT_PLAYLISTFAVORITE_H
#include "../headers/Playlist.h"
#include "../headers/Artist.h"
#include<string>


//mostenire
class playlistFavorite : public Playlist{
private:
    int nrArtists; //numarul artistilor
public:
    void afisare() const; //functie de afisare

    //constructor fara parametri
    playlistFavorite();

    //constructor cu parametri
    playlistFavorite(const std::string& title, std::vector<Song>&songs, const int& nrSongs, const int& duration, const int& nrArtists);

    //copy constructor
    playlistFavorite(const playlistFavorite &other);


    //functionalitati
    void favoriteArtist(); //pe baza numarului de aparitii ale artistului, voi afisa artistul "preferat"

    friend std::ostream &operator<<(std::ostream &os, const playlistFavorite &other); //supraincarcarea operatorului <<

    //getter
    int getNrArtists() const;
};


#endif //OOP_PROJECT_PLAYLISTFAVORITE_H
