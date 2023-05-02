//
// Created by Alexandra Zamfirescu on 01.05.2023.
//

#ifndef OOP_PROJECT_INTERFATA_H
#define OOP_PROJECT_INTERFATA_H

#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"


//ABSTRACTIZARE
//pentru playlist
class InterfataPlaylist {
protected:
    virtual void play() = 0;
    virtual void pause() = 0;
public:
     virtual ~InterfataPlaylist();
};

class IPlaylist : public InterfataPlaylist {
public:
    void play() override;
    void pause() override;

};

//pentru song
class InterfataSong {
protected:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void afisare() = 0;

public:
    virtual ~InterfataSong();
};

class ISong : public InterfataSong {
public:
    void play() override;
    void pause() override;
    void afisare() override;
};


//CLASA ABSTRACTA
class absPlaylist{
protected:
    std::vector<Song> songs;
    int i;
    int nrSongs;
    virtual int nextSong(int i) = 0;

public:
    virtual ~absPlaylist();
};

class AbsPlaylist : public absPlaylist{
public:
    int nextSong(int i) override;
    void addSong(const Song& song);
};


#endif //OOP_PROJECT_INTERFATA_H