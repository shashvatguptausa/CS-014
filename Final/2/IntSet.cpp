

#include <fstream>
#include <iostream>
#include "IntSet.h"

using namespace std;


//    friend std::ostream& operator<<(std::ostream&,const IntSet&);


IntSet::IntSet() {
    _capacity=1;
    _size=0;
    _table = new setRecord[_capacity];
    for(int i = 0; i < _capacity; i++) {
        //_table[i]=new setRecord();
    }
    _comparisons=0;
}

IntSet::IntSet(int n) {
    _capacity=n;
    _size=0;
    _table = new setRecord[_capacity];
    _comparisons=0;
}

// Returns the number of camparisons from the last operation performed
int IntSet::comparisons() {
    int tmp = _comparisons;
    _comparisons=0;
    return tmp;
}

int IntSet::totCom() {
    return comp;
}

size_t IntSet::size() const {
    return _size;
}
size_t IntSet::capacity() const {
    return _capacity;
}

//-----------------------------------------//

void IntSet::insert(int value) {
    
    //cout << "inserting val: " << value << endl;
    
    if(_capacity*.67<size()+1) {
        //        cout << "rehashing to size: " << _capacity*3 << " from: " << size()+1 << endl;
        
        rehash(_capacity*3);
        comp+=comparisons();
//        cout << "comparisons after rehashing: " << comp << endl;
    }
    
    if(count(value)==1) {
        cout << value << " already in hash" << endl;
        return;
    }
    else {
        _size++;
    }
    
    comp+=comparisons();
//    cout << "comparisons after counting: " << comp << endl;
    
    int hashIndex = hash(value);
    hashIndex = probe(hashIndex);
    if(hashIndex==-1) {
        cout << "no spots available" << endl;
    }
    else {
        _table[hashIndex].value=value;
        _table[hashIndex].status=Occupied;
        //cout << "inserted " << value << endl;
    }
    
    comp+=comparisons();
//    cout << "comparisons after inserting: " << comp << endl<<endl;
}

void IntSet::erase(int value) {
    
    if(empty()) {
        return;
    }
    
    if(count(value)==1) {
        _size--;
    }
    else {
        cout << value << " not in hash" << endl;
        return;
    }
    
    int key = hash(value);
    while (true) {
        if(key>=capacity()) {
            key=-1;
        }
        _comparisons++;
        if(key>=0 && _table[key].status==Occupied && _table[key].value==value) {
            _table[key].status=Empty;
            _table[key].value=0;
            return;
        }
        key++;
    }
    
}

void IntSet::rehash(size_t sz) {
    setRecord *tmp = _table;
    
    _table = new setRecord[sz];
    size_t pre = _capacity;
    _capacity=sz;
    _size=0;
    
    
    for(int i = 0; i < pre; i++) {
        if((tmp[i]).status==Occupied) {
            _comparisons++;
            insert((tmp[i]).value);
        }
    }
}

bool IntSet::empty() const {
    for(int i = 0; i < capacity(); i++) {
        if(_table[i].status==Occupied) {
            return false;
        }
    }
    return true;
}

// Returns 1 if the key passed in exists in the set and 0 otherwise.
int IntSet::count(int key) {
    int val = key;
    key = hash(key);
    int orig=key;
    bool first = true;
    while (true) {
        if(key==orig) {
            if(first) {
                first=false;
            }
            else {
                return 0;
            }
        }
        else if(key>=capacity()) {
            key=-1;
        }
        if(key>=0) {
            _comparisons++;
            if(_table[key].status==Occupied) {
                if(_table[key].value==val) {
                    return 1;
                }
            }
            else if(_table[key].status==Empty_since_start) {
                return 0;
            }
        }
        key++;
    }
    return 0;
}

//-----------------------------------------//

//finds next open slot
int IntSet::probe(int key)  {
    int orig=key;
    bool first = true;
    while (true) {
        if(key==orig) {
            if(first) {
                first=false;
            }
            else {
                return -1;
            }
        }
        if(key>=capacity()) {
            key=0;
        }
        if(_table[key].status!=Occupied) {
            return key;
        }
        key++;
    }
    
    return -1;
}

int IntSet::hash(int value,int key) const {
    return compression_map(hash_map(key+value));
}

int IntSet::hash_map(int key) const {
    return key*1234;
}
int IntSet::compression_map(int key) const {
    return key%_capacity;
}
