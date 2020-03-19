#include "HashTable.h"
#include "WordEntry.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
    size=s;
  //  size = 4;
    hashTable = new list<WordEntry>[size];
    
    for(int i = 0; i < size; i++) {
        list<WordEntry> *tmp = new list<WordEntry>;
        tmp->push_back(WordEntry("",-1));
        hashTable[i]=*tmp;
    }
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    int seed = 4;
    int hash = 0;
    for(int i = 0; i < s.length(); i++)
    {
       hash = (hash * seed) + s[i];
    }
    if(hash<0)
        hash*=-1;
    return hash%size;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
    int pos = computeHash(s);
    
    for (std::list<WordEntry>::iterator it = (hashTable[pos]).begin(); it != hashTable[pos].end(); it++) {
        if(it->word==s) {
            it->addNewAppearance(score);
            return;
        }
    }
    
    if(hashTable[pos].begin()->word=="") {
        cout << "empty at " << pos << endl;
    }
    
    hashTable[pos].push_back(WordEntry(s,score));
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    int pos = computeHash(s);
    
    for (std::list<WordEntry>::iterator it = (hashTable[pos]).begin(); it != hashTable[pos].end(); it++) {
        if(it->word==s) {
            return it->getAverage();
        }
    }
    
    return 2.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
    int pos = computeHash(s);
    
    for (std::list<WordEntry>::iterator it = (hashTable[pos]).begin(); it != hashTable[pos].end(); it++) {
        if(it->word==s) {
            return true;
        }
    }
    
    return false;
}

