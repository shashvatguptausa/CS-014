#include <iostream>
using namespace std;

#include "Playlist.h"

void PrintMenu(string title) {
    cout << title << " PLAYLIST MENU\na - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit\n\nChoose an option:" << endl;
}


int main() {
    
    string title;
    string choice;
    
    cout << "Enter playlist's title:\n" << endl;
    
    getline(cin, title);
    
    PrintMenu(title);
    getline(cin, choice);
    
    Playlist pl;
    
    while(choice!="q") {
        
        if(choice=="a") {
            string id = "id";
            string sName = "sName";
            string aName = "aName";
            int length = -1;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, id);
            cout << "Enter song's name:" << endl;
            getline(cin, sName);
            cout << "Enter artist's name:" << endl;
            getline(cin, aName);
            cout << "Enter song's length (in seconds):";
            cin >> length;
            cin.ignore();
            
            PlaylistNode* tmp = new PlaylistNode(id,sName,aName,length);
            if(pl.head == nullptr) {
                pl.head = tmp;
                pl.tail = tmp;
            }
            else {
                PlaylistNode* current = pl.head;
                bool no = true;
                while(current!=nullptr && no) {
                    if(current->GetNext() == nullptr) {
                        current->InsertAfter(tmp);
                        pl.tail = tmp;
                        no = false;
                    }
                    current = current->GetNext();
                }
            }
            cout << "\n" << endl;
        }
        else if(choice=="d") {
            string id = "";
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, id);
            string tmp = "tmp";
            
            PlaylistNode* current = pl.head;
            while(current!=nullptr&&current->GetNext()!=nullptr) {
                if((current->GetNext())->GetID() == id) {
                    tmp = (current->GetNext())->GetSongName();
                    PlaylistNode* tmp2 = (current->GetNext())->GetNext();
                    current->SetNext( tmp2 );
                }
                current = current->GetNext();
            }
            
            cout << "\"" << tmp << "\"" << " removed.\n" << endl;
        }
        else if(choice=="c") {
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            int cur = -1;
            cin >> cur;
            cout << "Enter new position for song:" << endl;
            int npos = -2;
            cin >> npos;
            
            if(cur < npos) {
                if(cur==1) {
                    PlaylistNode* temp = pl.head;
                    pl.head = pl.head->GetNext();
                    
                    PlaylistNode* current = pl.head;
                    for(int i = 0; i < npos-2; i++) {
                        current = current->GetNext();
                    }
                    
                    PlaylistNode* suptmp = current->GetNext();
                    
                    temp->SetNext(suptmp);
                    current->SetNext(temp);
                    
                    if(temp->GetNext() == nullptr) {
                        pl.tail = temp;
                    }
                    cout << "\""<<temp->GetSongName()<<"\" " << "moved to position " << npos << "\n" << endl;
                    
                }
                else {
                    //cout << "\\\\\\\\\\\"head: "<<pl.head->GetSongName()<<"\\\\\\\\\" " << endl;
                    PlaylistNode* current = pl.head;
                    for(int i = 0; i < cur-2; i++) {
                        current = current->GetNext();
                    }
                    PlaylistNode* temp = current->GetNext();
                    //cout << "\n\\\\\\\\\\\""<<temp->GetSongName()<<"\\\\\\\\\" " << endl;
                    PlaylistNode* suptmp = current->GetNext()->GetNext();
                    current->SetNext(suptmp);
                    
                    current = pl.head;
                    for(int i = 0; i < npos-2; i++) {
                        current = current->GetNext();
                    }
                    
                    PlaylistNode* xd = current->GetNext();
                    
                    temp->SetNext(xd);
                    current->SetNext(temp);
                    
                    if(temp->GetNext() == nullptr) {
                        pl.tail = temp;
                    }
                    cout << "\""<<temp->GetSongName()<<"\" " << "moved to position " << npos << "\n" << endl;
                    
                }
            }
            else if(npos<cur) {
                //cout << "\\\\\\\\\\\"head: "<<pl.head->GetSongName()<<"\\\\\\\\\" " << endl;
                
                PlaylistNode* current = pl.head;
                for(int i = 0; i < cur-2; i++) {
                    current = current->GetNext();
                }
                PlaylistNode* temp = current->GetNext();
                //cout << "\n\\\\\\\\\\\""<<temp->GetSongName()<<"\\\\\\\\\" " << endl;
                PlaylistNode* suptmp = temp->GetNext();
                //cout << "\nsuptmp: \\\\\\\\\\\""<<suptmp->GetSongName()<<"\\\\\\\\\" " << endl;
                                
                current->SetNext(suptmp);
                if(npos == 1) {
                    temp->SetNext(pl.head);
                    pl.head = temp;
                    current = pl.head;
                    
                    for(int i = 0; i < cur-1; i++) {
                        current = current->GetNext();
                        cout << "\ncurrent: \\\\\\\\\\\""<<current->GetSongName()<<"\\\\\\\\\" " << endl;
                        
                    }
                    current->SetNext(suptmp);
                }
                else {
                    current = pl.head;
                    for(int i = 0; i < npos-2; i++) {
                        current = current->GetNext();
                    }
                }
                
                
                PlaylistNode* xd = current->GetNext();
                if(npos != 1) {
                    temp->SetNext(xd);
                    current->SetNext(temp);
                }
                
                if(temp->GetNext() == nullptr) {
                    pl.tail = temp;
                }
                cout << "\""<<temp->GetSongName()<<"\" " << "moved to position " << npos << "\n" << endl;
            }
            
            
            
            
            cin.ignore();
        }
        else if(choice=="s") {
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            string artName = "";
            int counter = 0;
            //cin.ignore();
            getline(cin,artName);
            
            //cout << "ARTNAME: " << artName << endl;
            cout << endl;
            PlaylistNode* current = pl.head;
            
            while (current!=nullptr) {
                counter++;
                if(current->GetArtistName() == artName) {
                    cout << counter << "." << endl;
                    current->PrintPlaylistNode();
                    cout << endl;
                }
                current = current->GetNext();
            }
        }
        else if(choice=="t") {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            int tot = 0;
            PlaylistNode* current = pl.head;

            while (current!=nullptr) {
                tot+=current->GetSongLength();
                current = current->GetNext();
            }
            cout << "Total time: " << tot << " seconds\n" << endl;
        }
        else if(choice=="o") {
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            int spot = 0;
            if(pl.head == nullptr)
            {
                cout << "Playlist is empty\n" << endl;
            }
            else {
                PlaylistNode* current = pl.head;
                while(current!=nullptr) {
                    spot++;
                    cout << spot << "." << endl;
                    current->PrintPlaylistNode();
                    cout << endl;
                    current = current->GetNext();
                    if(spot>4) {
                        current=nullptr;
                    }
                }
            }
        }
        PrintMenu(title);
        getline(cin, choice);
    }
    
    return 0;
}

