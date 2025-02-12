/* File:      Playlist.cpp
Author:       Zia Animashaun
Date:         11/01/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build an application that will allow the user to create a
music playlist from a large list of songs held in a catalog.
*/


#include "Playlist.h"

// Name: Playlist() - Default Constructor
// Desc - Creates a new empty playlist
// Preconditions - None
// Postconditions - Sets everything to either nullptr or 0
Playlist::Playlist() {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

// Name: ~Playlist - Destructor
// Desc - Removes all of the songs from the playlist
// Preconditions - Playlist must have songs
// Postconditions - Playlist will be empty and m_head and m_tail will be nullptr. Size will be 0
Playlist::~Playlist() {
    Song* node = m_head;
    while(node != nullptr) {
        Song* next = node->GetNext();
        delete node;
        node = next;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

// Name: AddSong(string, string, int, int)
// Desc - Dynamically allocates new song using title, artist, year, and rank
// Preconditions - Playlist allocated
// Postconditions - New song inserted in end of list
void Playlist::AddSong(string title, string artist, int year, int rank) {
    Song* node = new Song(title, artist, year, rank);
    if(m_tail == nullptr) { //list is currently empty
        m_head = node;
        m_tail = node;
    }
    else {
        m_tail->SetNext(node);
        m_tail = node;
    }
    m_size++;
}

// Name: GetPlaylistDetails()
// Desc - Returns a song object from a specific location
// Preconditions - Playlist populated
// Postconditions - Returns the data (does not output it)
Song* Playlist::GetPlaylistDetails(int location) {
    Song* node = m_head;
    int pos = 0;
    while(node != nullptr) {
        if(pos == location) {
            return node;
        }
        node = node->GetNext();
        pos++;
    }
    return nullptr;
}

// Name: Size
// Desc - Returns the m_size
// Preconditions - Playlist starts at size 0
// Postconditions - Returns the size
int Playlist::Size() {
    return m_size;
}

// Name: PlayAt
// Desc - Passed the song that is to be played from the playlist
//       "Plays" a song by removing it from the playlist at a specific location
// Recommendations - Code this function last (dead last)
// Preconditions - Playlist has been populated
// Hint: Do not forget about removing from the front, middle, or end of the list
//       Could also remove the only node
// Postconditions - Playlist is reduced in size by one based on which song is played
void Playlist::PlayAt(int location) {
    Song* node = m_head, *prev = nullptr;
    int pos = 0;
    while(node != nullptr) {
        if(pos == location) {
            if(prev == nullptr) { //if prev doesn't exist, we must be at the head and need to update it
                m_head = node->GetNext();
            }
            else { //example: 1->2->3 deleting 2 means 1's next needs to be 3
                prev->SetNext(node->GetNext());
            }
            if(node->GetNext() == nullptr) { //if next doesn't exist, we must be at the tail and need to update it
                m_tail = prev;
            }
            delete node;
            m_size--;
            return;
        }
        prev = node;
        node = node->GetNext();
        pos++;
    }
}