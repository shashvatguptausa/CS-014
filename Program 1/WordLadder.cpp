//
//  WordLadder.cpp
//  Test
//
//  Created by Shashvat Gupta on 1/25/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include "WordLadder.h"


using namespace std;

WordLadder::WordLadder(const string &in) {
    
    ifstream inFS;
    inFS.open(in);
        
    
    if(!(inFS.is_open())) {
        cout << "FILE DOES NOT EXIST" << endl;
        return;
    }
    string word = "";
    while(inFS>>word) {
        if(word.length() != 5) {
            cout << "Word in dictionary not equal to 5" << endl;
            inFS.close();
            return;
        }
        dict.push_back(word);
        //cout << "word: " << word << endl;
    }
    inFS.close();
}

bool WordLadder::oneLetter(string word, string word2) {
    int off = 0;
    if(word2.length()!=word.length()) {
        return false;
    }
    for(unsigned i = 0; i < 5; i++) {
        if(word.at(i) != word2.at(i)) {
            off++;
        }
    }
    if(off==1) {
        return true;
    }
    return false;
}


void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
//    dict.push_back("abaca");
//    dict.push_back("abaci");
//    dict.push_back("aback");
//    dict.push_back("abase");
//    dict.push_back("abash");
    
    //for testing^

    
    if(start == end) {
        ofstream oFile(outputFile);
        oFile << start;
        oFile.close();
        return;
    }

        stack<string> firstW;
        firstW.push(start);
        
        queue<stack<string>> q;
        q.push(firstW);
        
        while (q.empty() == false) {
            string word = (q.front()).top();
            for(list<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
                
                if(oneLetter(word, (*it) )) {
                    
                    stack<string> tmp = q.front();
                    tmp.push(*it);
                    if(*it == end) {
                        //
                        stack<string> out;
                        //cout << "wordLadder complete" << endl;
                        ofstream oFile(outputFile);
                        while(q.front().empty() == false) {
                            out.push(q.front().top());
                            q.front().pop();
                        }
                        while(out.empty() == false) {
                            oFile << (out.top()) << endl;
                            out.pop();
                        }
                        oFile << *it;
                        oFile.close();
                        
                        return;
                    } //if not end
                    else {
                        q.push(tmp);
                        //dict.remove(*it);
                        it = dict.erase(it);
                        it--;
                    }
                }
            }
        q.pop();
    }
    
    ofstream oFile(outputFile);
    oFile << "No Word Ladder Found.";
    oFile.close();
}
/*
 create a Stack containing just the first word in the ladder
 enqueue this Stack on to a Queue of Stacks
 while this Queue of Stacks is not empty
 get the word on top of the front Stack of this Queue
 for each word in the dictionary
 if the word is off by just one letter from the top word
 create a new Stack that is a copy of the front Stack and push on this off-by-one word found
 if this off-by-one word is the end word of the ladder, this new Stack contains the entire word ladder. You are done!
 otherwise, enqueue this new Stack and remove this word from the dictionary
 dequeue this front stack
 if the Queue is empty and you didn't find the word ladder, a word ladder does not exist for these 2 words

 */


/* Passes in two 5-letter words and the name of an output file.
 Outputs to this file a word ladder that starts from the first word passed in
 and ends with the second word passed in.
 If either word passed in does not exist in the dictionary (dict),
 this function should output an error message and return.
 Otherwise, this function outputs to the file the word ladder it finds or outputs
 to the file, the message, "No Word Ladder Found."
 */
