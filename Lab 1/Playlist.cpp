#include <iostream>
#include "Playlist.h"
using namespace std;

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

Playlist::Playlist() {
    head = nullptr;
    tail = nullptr;
}

Playlist::~Playlist() {
//    delete head;
//    delete tail;
}

PlaylistNode::PlaylistNode(string id, string sName, string aName, int length) {
    uniqueID = id;
    songName = sName;
    artistName = aName;
    songLength = length;
    nextNodePtr = nullptr;
}

PlaylistNode::~PlaylistNode() {
   // delete nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode*& pl) {
    this->SetNext(pl);
}

void PlaylistNode::SetNext(PlaylistNode*& pn) {
    if(pn == nullptr) {
        nextNodePtr = nullptr;
    }
    else {
    nextNodePtr = pn;
    }
}

string PlaylistNode::GetID() {
    if(this == nullptr) {
        return 0000;
    }
    return uniqueID;
}

string PlaylistNode::GetSongName() {
    if(this == nullptr) {
        return "nullSong";
    }
    return songName;
}

string PlaylistNode::GetArtistName() {
    if(this == nullptr) {
        return "nullName";
    }
    return artistName;
}

int PlaylistNode::GetSongLength() {
    if(this == nullptr) {
        return -3;
    }
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    if(this == nullptr || this->nextNodePtr == nullptr) {
        return nullptr;
    }
    return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}
