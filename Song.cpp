#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>
#include "Song.h"
using namespace std;

//default constructor:
Song::Song() {
  cout << '\0';
}

//ReadSongs reads the file to get the song info:
void Song::ReadSongs(Song SongList[], int& numSongs){
  int i = 0;
  ifstream inFile("songs.txt");
  if(inFile.is_open()){
    inFile.getline(SongList[i].songTitle, CAPACITY, ';');
    inFile.getline(SongList[i].artistName, CAPACITY, ';');
    inFile.getline(SongList[i].durMin, CAPACITY, ';');
    inFile.getline(SongList[i].durSec, CAPACITY, ';');
    inFile.getline(SongList[i].albumName, CAPACITY, '\n');
    i++;
    while (!inFile.eof()){
      inFile.getline(SongList[i].songTitle, CAPACITY, ';');
      inFile.getline(SongList[i].artistName, CAPACITY, ';');
      inFile.getline(SongList[i].durMin, CAPACITY, ';');
      inFile.getline(SongList[i].durSec, CAPACITY, ';');
      inFile.getline(SongList[i].albumName, CAPACITY, '\n');
      i++;
    }
    inFile.close();
    inFile.clear();
  }
  else {
    cout << "Couldnt open" << endl;
  }
  numSongs = i;
}
//SaveFile function saves any changes to the file:
void Song::SaveFile(Song SongList[], int songAmount){
  ofstream outFile("songs.txt", ios::out);
  int i = 0;
  if(outFile.is_open()){
    while (i < songAmount){
      outFile << SongList[i].songTitle << ";";
      outFile << SongList[i].artistName << ";";
      outFile << SongList[i].durMin << ";";
      outFile << SongList[i].durSec << ";";
      outFile << SongList[i].albumName << '\n';
      i++;
    }
    outFile.close();
    outFile.clear();
  }
  else {
    cout << "Could not open" << endl;
  }
}

void Song::ShuffleSongs(Song SongList[], int& songAmount){
  int i = 0;
  // opens order file and writes 'shuffle' to signal microservice
  ofstream outFile("order.txt", ios::out);
  if(outFile.is_open()){
    outFile << "shuffle";
    outFile.close();
    outFile.clear();
  }
    // if unable to open, prints error msg
  else {
    cout << "Could not open" << endl;
  }
  // sleeps for microservice to read txt file and shuffle
  std::this_thread::sleep_for(std::chrono::seconds(5));
  // program reads in the newly shuffled file 
  ifstream inFile("order.txt");
  if(inFile.is_open()){
    inFile.getline(SongList[i].songTitle, CAPACITY, ';');
    inFile.getline(SongList[i].artistName, CAPACITY, ';');
    inFile.getline(SongList[i].durMin, CAPACITY, ';');
    inFile.getline(SongList[i].durSec, CAPACITY, ';');
    inFile.getline(SongList[i].albumName, CAPACITY, '\n');
    i++;
    while (!inFile.eof()){
      inFile.getline(SongList[i].songTitle, CAPACITY, ';');
      inFile.getline(SongList[i].artistName, CAPACITY, ';');
      inFile.getline(SongList[i].durMin, CAPACITY, ';');
      inFile.getline(SongList[i].durSec, CAPACITY, ';');
      inFile.getline(SongList[i].albumName, CAPACITY, '\n');
      i++;
    }
    inFile.close();
    inFile.clear();
  }
  // if unable to open, prints error msg
  else {
    cout << "Couldnt open" << endl;
  }
  // program prints the contents of the newly shuffled playlist
  cout << '\n';
  cout << '\t' << "Title: " << '\t' << "Artist: " << '\t' << "Duration: " << '\t' << "Album" << endl;
  cout << "----------------------------------------------------------------" << endl;
  for (int i = 0; i < songAmount - 1; i++){
    cout << i << ". " << SongList[i].songTitle << '\t' << SongList[i].artistName << '\t' << SongList[i].durMin << ":" << SongList[i].durSec << '\t' << SongList[i].albumName << endl;
  }
  cout << '\n';
}

void Song::SortSongs(Song SongList[], int& songAmount){
  int i = 0;
  // opens order file and writes 'sort' to signal microservice
  ofstream outFile("order.txt", ios::out);
  if(outFile.is_open()){
    outFile << "sort";
    outFile.close();
    outFile.clear();
  }
    // if unable to open, prints error msg
  else {
    cout << "Could not open" << endl;
  }
  // sleeps for microservice to read txt file and shuffle
  std::this_thread::sleep_for(std::chrono::seconds(5));
  // program reads in the newly shuffled file 
  ifstream inFile("order.txt");
  if(inFile.is_open()){
    inFile.getline(SongList[i].songTitle, CAPACITY, ';');
    inFile.getline(SongList[i].artistName, CAPACITY, ';');
    inFile.getline(SongList[i].durMin, CAPACITY, ';');
    inFile.getline(SongList[i].durSec, CAPACITY, ';');
    inFile.getline(SongList[i].albumName, CAPACITY, '\n');
    i++;
    while (!inFile.eof()){
      inFile.getline(SongList[i].songTitle, CAPACITY, ';');
      inFile.getline(SongList[i].artistName, CAPACITY, ';');
      inFile.getline(SongList[i].durMin, CAPACITY, ';');
      inFile.getline(SongList[i].durSec, CAPACITY, ';');
      inFile.getline(SongList[i].albumName, CAPACITY, '\n');
      i++;
    }
    inFile.close();
    inFile.clear();
  }
  // if unable to open, prints error msg
  else {
    cout << "Couldnt open" << endl;
  }
  // program prints the contents of the newly shuffled playlist
  cout << '\n';
  cout << '\t' << "Title: " << '\t' << "Artist: " << '\t' << "Duration: " << '\t' << "Album" << endl;
  cout << "----------------------------------------------------------------" << endl;
  for (int i = 0; i < songAmount - 1; i++){
    cout << i << ". " << SongList[i].songTitle << '\t' << SongList[i].artistName << '\t' << SongList[i].durMin << ":" << SongList[i].durSec << '\t' << SongList[i].albumName << endl;
  }
  cout << '\n';
}

//PrintSongs prints the songs for the user to see:
void Song::PrintSongs(const Song SongList[], const int& songAmount){
  cout << '\n';
  cout << '\t' << "Title: " << '\t' << "Artist: " << '\t' << "Duration: " << '\t' << "Album" << endl;
  cout << "----------------------------------------------------------------" << endl;
  for (int i = 0; i < songAmount - 1; i++){
    cout << i << ". " << SongList[i].songTitle << '\t' << SongList[i].artistName << '\t' << SongList[i].durMin << ":" << SongList[i].durSec << '\t' << SongList[i].albumName << endl;
  }
  cout << '\n';
}
//InsertSong inserts a new song:
void Song::InsertSong(Song SongList[], int& songAmount){
  //incrementing songAmount because a song is being inserted:
  cin.ignore(200, '\n');
  cout << "Please enter the song title: " << endl;
  cin.getline(SongList[songAmount - 1].songTitle, CAPACITY, '\n');
  cout << "Please enter the artist's name: " << endl;
  cin.getline(SongList[songAmount - 1].artistName, CAPACITY, '\n');
  cout << "Please enter the duration separated by a colon ':': " << endl;
  cin.getline(SongList[songAmount - 1].durMin, CAPACITY, ':');
  cin.getline(SongList[songAmount - 1].durSec, CAPACITY, '\n');
  cout << "Please enter the album name: " << endl;
  cin.getline(SongList[songAmount - 1].albumName, CAPACITY, '\n');
  //calling saveFile function to output to the file and save:
  SaveFile(SongList, songAmount);
  songAmount++;
}
//RemoveSong removes a song by index:
void Song::RemoveSong(Song SongList[], int& songAmount){
  int index = 0;
  cout << "Select a song to delete: ";
  cin >> index;
  //if it's the last song in the list, it just removes the last line:
  if (index == songAmount - 1){
    songAmount = songAmount - 2;
    SaveFile(SongList, songAmount);
  }
  //else it replaces that song with the last song in the list and decrements:
  else if (index < songAmount - 1){
    strcpy(SongList[index].songTitle, SongList[songAmount - 2].songTitle);
    strcpy(SongList[index].artistName, SongList[songAmount - 2].artistName);
    strcpy(SongList[index].durMin, SongList[songAmount - 2].durMin);
    strcpy(SongList[index].durSec, SongList[songAmount - 2].durSec);
    strcpy(SongList[index].albumName, SongList[songAmount - 2].albumName);
    songAmount = songAmount - 2;
    SaveFile(SongList, songAmount);
  }
  else {
    cout << "Could not read" << endl;
  }
}
//SearchSong allows for the user to search by album/artist:
void Song::SearchSong(Song SongList[], int& songAmount){
  //declaring variables:
  int i = 0;
  int countSearch = 1;
  char userIn = ' ';
  char searchArtist[CAPACITY];
  char searchAlbum[CAPACITY];
  //asking user for artist/album:
  cout << '\t' << "To search by artist: [ Press a ] " << endl;
  cout << '\t' << "To search by album: [ Press b ] " << endl;
  cin >> userIn;
  if (userIn == 'a') {
    cout << '\t' << "Who would you like to search for? " << endl;
    cin.ignore(200, '\n');
    cin.getline(searchArtist, CAPACITY);
    //loop compares the input to the artistName in SongList[]:
    cout << '\n' << "----------------------------------------------------------------------" << endl;
    cout << "Search results for songs by " << searchArtist << ":" << endl;
    for (i = 0; i < strlen(searchArtist); i++){
      if (strcmp(searchArtist, SongList[i].artistName) == 0){
        cout << '\t' << countSearch << ". " << SongList[i].songTitle << " " << SongList[i].artistName << " " << SongList[i].durMin << ":" << SongList[i].durSec << " " << SongList[i].albumName << endl;
        countSearch++;
      }
    }
    cout << '\n' << "----------------------------------------------------------------------" << endl;
  }
  else {
    cout << '\t' << "What album would you like to search for?" << endl;
    cin.ignore(200, '\n');
    cin.getline(searchAlbum, CAPACITY);
    //loop compares the input to the albumName in SongList[]:
    cout << '\n' << "----------------------------------------------------------------------" << endl;
    cout << "Search results for songs from " << searchAlbum << ":" << endl;
    for (i = 0; i < strlen(searchAlbum); i++){
      if (strcmp(searchAlbum, SongList[i].albumName) == 0){
        cout << '\t' << countSearch << ". " << SongList[i].songTitle << " " << SongList[i].artistName << " " << SongList[i].durMin << ":" << SongList[i].durSec << " " << SongList[i].albumName << endl;
        countSearch++;
      }
    }
    cout << "----------------------------------------------------------------------" << endl;
  }
}
