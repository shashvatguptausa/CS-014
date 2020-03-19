#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

class PlaylistNode;

struct Playlist {
    public:
       Playlist();
       ~Playlist();
       PlaylistNode* head;
       PlaylistNode* tail;
};

class PlaylistNode {
    
 private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;

 public:
	PlaylistNode();
    PlaylistNode(string id, string sName, string aName, int length);
	~PlaylistNode();
    
    void InsertAfter(PlaylistNode*&);
    void SetNext(PlaylistNode*&);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
};



#endif

