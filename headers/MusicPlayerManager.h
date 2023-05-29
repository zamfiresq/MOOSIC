#ifndef OOP_PROJECT_MUSICPLAYERMANAGER_H
#define OOP_PROJECT_MUSICPLAYERMANAGER_H
#include <iostream>
#include <string>
#include "Playlist.h"
#include "Song.h"
#include <algorithm>
#include <random>



class MusicPlayerManager {
private:
    static MusicPlayerManager* instance; //singleton

    MusicPlayerManager(){}//constructor privat fara parametri
    MusicPlayerManager(const MusicPlayerManager& other) = delete; //copy constructor
    MusicPlayerManager& operator=(const MusicPlayerManager& other) = delete; //operator =

public:
    static MusicPlayerManager* getInstance(){
        if (instance == nullptr){
            instance = new MusicPlayerManager();
        }
        return instance;
    }

    ~MusicPlayerManager() {};


    void deleteInstance(){
        if(instance != nullptr){
            delete instance;
            instance = nullptr;
        }
    }

    void volumPlus();
    void volumMinus();
    void addSongToPlaylist(const Song& song, Playlist& playlist);
    void removeSongFromPlaylist(Song& song, Playlist& playlist);
    void play() const;
    void pause() const;
    int next(int idx);
    int previous(int idx);
    void repeatOne();
    void shuffle();


};


#endif //OOP_PROJECT_MUSICPLAYERMANAGER_H
