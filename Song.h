#ifndef SONGS_H
#define SONGS_H
#include "main.h"

const int CAPACITY = 50;
const int NAME_CAP = 20;

//declaring Song class:
class Song {
  public:
    Song();
    void ReadSongs(Song SongList[], int& newSongs);
    void PrintSongs(const Song SongList[], const int& songAmount);
    void ShuffleSongs(Song SongList[], int& songAmount);
    void SortSongs(Song SongList[], int& songAmount);
    void InsertSong(Song SongList[], int& songAmount);
    void RemoveSong(Song SongList[], int& songAmount);
    void SearchSong(Song SongList[], int& songAmount);
    void SaveFile(Song SongList[], int num);
  private:
    char songTitle[CAPACITY];
    char artistName[CAPACITY];
    char albumName[CAPACITY];
    char durMin[CAPACITY];
    char durSec[CAPACITY];
};


#endif
