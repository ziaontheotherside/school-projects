/* File:      MusicPlayer.cpp
Author:       Zia Animashaun
Date:         11/01/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build an application that will allow the user to create a
music playlist from a large list of songs held in a catalog.
*/


#include "MusicPlayer.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Name: MusicPlayer - Default Constructor
//Precondition: None
//Postcondition: Dynamically creates a new MusicPlayer and populates m_filename FILE_NAME
MusicPlayer::MusicPlayer() {
    m_filename = FILE_NAME;
    m_playList = new Playlist();
}

//Name: ~MusicPlayer - Destructor
//Precondition: None
//Postcondition: Destructs all songs in the catalog and all songs in the playlist
MusicPlayer::~MusicPlayer() {
    delete m_playList;
    for(int i=0; i<m_songCatalog.size(); i++) {
        delete m_songCatalog[i];
    }
}

//Name: LoadCatalog(string filename)
//Precondition: Requires filename
//Postcondition: Loads the file of songs into the m_songCatalog (as song objects) using the DELIMITER
void MusicPlayer::LoadCatalog(string filename) {
    m_filename = filename;
    ifstream in(filename);
    string title, artist, junk;
    int year, rank;
    while(in) {
        getline(in, title, '|');
        getline(in, artist, '|');
        getline(in, junk, '|');
        year = stoi(junk);
        getline(in, junk, '\n');
        rank = stoi(junk);
        Song* song = new Song(title, artist, year, rank);
        m_songCatalog.push_back(song);
    }
}

//Name: MainMenu
//Precondition: None
//Postcondition: Manages the application and the menu. Calls until user chooses to quit.
void MusicPlayer::MainMenu() {
    bool ongoing = true;
    while(ongoing) {
        cout << "What would you like to do?" << endl;
        cout << "1. Display Songs by Year" << endl;
        cout << "2. Add Song" << endl;
        cout << "3. Display Playlist" << endl;
        cout << "4. Play Song" << endl;
        cout << "5. Quit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            DisplaySongs();
        } else if (choice == 2) {
            AddSong();
        } else if (choice == 3) {
            DisplayPlaylist();
        } else if (choice == 4) {
            PlaySong();
        } else if (choice == 5) {
            ongoing = false;
            return;
        } else {
            cout << "Invalid selection, please try again." << endl;
        }
    }
}

//Name: DisplaySongs
//Precondition: User enters year using constants above (2010-2021)
//Postcondition: Lists all songs (numbered) for that year by ranking
void MusicPlayer::DisplaySongs() {
    int year;
    bool valid = false;
    cout << "Which year would you like to display? (" << LOW_YEAR << "-" << HIGH_YEAR << ")" << endl;
    while(!valid) {
        cin >> year;
        if(year < LOW_YEAR || year > HIGH_YEAR) {
            cout << "Invalid year, please try again" << endl;
        }
        else valid=true;
    }
    for(int i=1; i<=100; i++) { //i is the rank/number
        //find the song of this rank from this year
        bool found = false;
        for(int j=0; j<m_songCatalog.size() && !found; j++) {
            if(m_songCatalog[j]->GetYear() == year && m_songCatalog[j]->GetRank() == i) {
                cout << j+1 << ". " << *(m_songCatalog[j]) << endl;
                found = true;
            }
        }
    }
}

//Name: AddSong
//Precondition: m_songCatalog is populated and m_playList exists
//Postcondition: Displays the songs for a specific year. Adds a song to the m_playList by dynamically allocating a new song based on the song in the catalog
//               and inserting it in the end.
//               May have duplicate songs on a playlist.
//               If the user chooses 2010, the user does not have to choose something from 2010 but it does need to be valid (between 1 - 1200)
void MusicPlayer::AddSong() {
    cout << "Choose the songs you would like to add to the playlist." << endl;
    DisplaySongs();
    cout << "Enter the number of the song you would like to add:" << endl;
    int songIndex;
    cin >> songIndex;
    if(songIndex < 1 || songIndex > m_songCatalog.size()) {
        cout << "Invalid song number, please try again." << endl;
        return;
    }
    Song* song = m_songCatalog[songIndex-1];
    m_playList->AddSong(song->GetTitle(), song->GetArtist(), song->GetYear(), song->GetRank());
}

//Name: DisplayPlaylist
//Precondition: None (can be empty)
//Postcondition: Displays the playlist or tells the user it is empty
void MusicPlayer::DisplayPlaylist() {
    if(m_playList->Size() < 1) {
        cout << "Your Playlist is empty." << endl;
        return;
    }
    cout << "Your Playlist:" << endl;
    for(int i=0; i<m_playList->Size(); i++) {
        cout << i+1 << ". " << *(m_playList->GetPlaylistDetails(i)) << endl;
    }
}

//Name: PlaySong
//Precondition: Playlist should be populated
//Postcondition: Allows the user to choose a song from the playlist to play.
//               Removes chosen song from playlist after "played"
void MusicPlayer::PlaySong() {
    DisplayPlaylist();
    cout << "Which song would you like to play?" << endl;
    int songIndex;
    cin >> songIndex;
    if(songIndex < 1 || songIndex > m_playList->Size()) {
        cout << "Invalid song number, please try again." << endl;
        return;
    }
    m_playList->PlayAt(songIndex-1);
}