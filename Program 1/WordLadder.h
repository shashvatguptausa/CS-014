//
//  WordLadder.hpp
//  Test
//
//  Created by Shashvat Gupta on 1/25/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef WordLadder_h
#define WordLadder_h

#include <stdio.h>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class WordLadder {

  private:
    list<string> dict;        //list of possible words in ladder

  public:
    
    WordLadder(const string &);

    /* Passes in two 5-letter words and the name of an output file.
       Outputs to this file a word ladder that starts from the first word passed in
       and ends with the second word passed in.
       If either word passed in does not exist in the dictionary (dict),
       this function should output an error message and return.
       Otherwise, this function outputs to the file the word ladder it finds or outputs
       to the file, the message, "No Word Ladder Found."
    */
    void outputLadder(const string &start, const string &end, const string &outputFile);
    
private:
    bool oneLetter(string word,string word2);
};


#endif /* WordLadder_h */
