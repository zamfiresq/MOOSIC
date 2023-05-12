//
// Created by Alexandra Zamfirescu on 26.04.2023.
//


#include "../headers/playlistFavorite.h"


playlistFavorite::playlistFavorite() {}

playlistFavorite::playlistFavorite(const std::string &title, std::vector<Song>&songs, const int &nrSongs, const int &duration, const int &nrArtists) : Playlist(title, songs, nrSongs, duration), nrArtists(nrArtists) {}

playlistFavorite::playlistFavorite(const playlistFavorite &other) : Playlist(other), nrArtists(other.nrArtists) {}


std::ostream &operator<<(std::ostream &os, const playlistFavorite &other){  //dynamic_cast
    os<< dynamic_cast<const Playlist&>(other); //conversie din playlistFavorite in Playlist
    other.afisare();

    return os;
}

void playlistFavorite::afisare() const {
    std::cout<<"Playlist-ul "<<this->getTitle()<<" contine "<<this->getNrSongs()<<" melodii."<<std::endl;
    std::cout<<"\n";

    for(int i = 0; i < getNrSongs(); i++)
        std::cout<< (this -> getSongs())[i]<<"\n";
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

    std::cout<<"Artistul preferat este: "<< artist <<"\n";

} //pe baza numarului de aparitii ale artistului, voi afisa artistul "preferat."

//getter
int playlistFavorite::getNrArtists() const {
    return nrArtists;
}