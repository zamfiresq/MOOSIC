//
// Created by Alexandra Zamfirescu on 26.04.2023.
//

#include "../headers/playlistFavorite.h"
#include<map>

playlistFavorite::playlistFavorite() {}

//Playlist(const std::string& title, std::vector<Song>&songs, const int& nrSongs, std::vector<Album>&albums, const int& nrAlbums, const int& duration);

playlistFavorite::playlistFavorite(const std::string &title, std::vector<Song>&songs, const int &nrSongs, const int &duration, const int &nrArtists) : Playlist(title, songs, nrSongs, duration), nrArtists(nrArtists) {}

playlistFavorite::playlistFavorite(const playlistFavorite &other) : Playlist(other), nrArtists(other.nrArtists) {}

std::ostream &operator<<(std::ostream &os, const playlistFavorite &other){
    os<< dynamic_cast<const Playlist&>(other); //conversie din playlistFavorite in Playlist
    other.afisare();

    return os;
}

void playlistFavorite::afisare() const {
    std::cout<<"Playlist-ul "<<this->getTitle()<<" contine "<<this->getNrSongs()<<" melodii."<<std::endl;
}

void playlistFavorite::favoriteArtist() {
    sortAfterArtistName();
    std::vector<Song> melodii = getSongs();
    int nrAp = 0;
    std::string artist;
    int cnt = 1;
    for(int i = 1; i < melodii.size(); i++){
        if(melodii[i] != melodii[i - 1]){
            if(cnt > nrAp){
                nrAp = cnt;
                artist = melodii[i - 1].getArtistName();
                cnt = 1;
            }
        } else {
            cnt++;
        }

    }
    std::cout<<"Artistul preferat este: "<<artist<<"\n";

} //pe baza numarului de aparitii ale artistului, voi afisa artistul "preferat" - de modificat



