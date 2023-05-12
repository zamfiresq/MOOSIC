//
// Created by Alexandra Zamfirescu on 02.05.2023.
//

#ifndef OOP_PROJECT_EXCEPTIONS_H
#define OOP_PROJECT_EXCEPTIONS_H

#include <stdexcept>
#include <string>
#include <iostream>
#include "Playlist.h"
#include "Song.h"




class errorInput : public std::runtime_error {
    using std::runtime_error::runtime_error;
};





//clasa pentru card invalid
class invalid_credit_card : public errorInput {
public:
    explicit invalid_credit_card(const std::string& message);
};

void efectuare_plata(const std::string& numar_card);







//exceptie pentru melodie deja existenta in playlist
class SongAlreadyExists : public errorInput {
public:
    explicit SongAlreadyExists(const Song* song);

    std::string songName;
};


////nu s a gasit artistul
//class ArtistNotFound : public errorInput {
//public:
//    explicit ArtistNotFound(const std::string& artistName);
//
//    const std::string& getArtistName() const{
//        return artistName;
//    }
//
//private:
//    std::string artistName;
//};
//
//void searchArtist(const std::string& artistName);

#endif //OOP_PROJECT_EXCEPTIONS_H
