#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    
}

void IntList::push_front(int value) {
    IntNode *val = new IntNode(value);
    
    if(empty()) {
        head = val;
        tail = val;
    }
    else {
        head->prev = val;
        val->next = head;
        head = val;
    }
}

void IntList::pop_front() {
    if(empty()) {
        //cout << "**nothing in list to pop_front!**" << endl;
    }
    else {
        head = head->next;
        if(head != NULL) {
        if(head->prev!=nullptr)
        head->prev = nullptr;
        }
        else {
            tail = nullptr;
            head = nullptr;
        }
    }
}

void IntList::push_back(int value) {
    IntNode *val = new IntNode(value);
    
    if(head == nullptr) {
        head = val;
        tail = val;
    }
    else {
        tail->next = val;
        val->prev = tail;
        tail = val;
    }
}

void IntList::pop_back() {
    if(empty()) {
        //cout << "**nothing in list to pop_back!**" << endl;
    }
    else {
        tail = tail->prev;
        //cout << "taildata: " << tail->data;
        if(tail!=NULL){
        if(tail->next!=nullptr)
        tail->next = nullptr;
        }
        else {
            tail = nullptr;
            head = nullptr;
        }
    }
}

bool IntList::empty() const {
    if(head == nullptr) {
        return true;
    }
    return false;
}


void IntList::printReverse() const {
    IntNode *cur = tail;
    while (cur != nullptr) {
        if(cur->prev == nullptr) {
            cout << cur->data;
        }
        else {
        cout << cur->data << " ";
        }
        cur = cur->prev;
    }
}

 ostream& operator<<(ostream &out, const IntList &rhs) {
     IntNode *cur = rhs.head;
     while (cur != nullptr) {
     if(cur->next == nullptr) {
         out << cur->data;
     }
     else {
         out << cur->data << " ";
     }
         cur = cur->next;
    }
     return out;

}

/*
friend ostream & operator<<(ostream &out, const IntList &rhs): A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. This function does NOT send to the stream a newline or space at the end.
*/
