#ifndef __STACK_H
#define __STACK_H


#include <string>

using namespace std;

const int MAX_SIZE = 20;

template <typename T>
class stack {
private:
    T data[MAX_SIZE];
    int size;

public:
    stack() { size = 0; };
    void push(T val){
        if(size>=MAX_SIZE) {
            size--;
            throw overflow_error("Called push on full stack.");
        }
        else {
//            cout << "\nsize: " << size << endl;
//            cout << "val: " << val << endl;
            data[size] = val;
            size++;
        }
    };
    void pop() {
        if(empty()) {
            throw out_of_range("Called pop on empty stack.");
        }
        else {
            //data[size-1] = NULL;
            size--;
        }
    };
    T top() {
        if(empty()) {
            throw underflow_error("Called top on empty stack.");
        }
        else {
        return data[size-1];
        }
    };
    bool empty() {
        if(size <= 0) {
            return true;
        }
        return false;
    };
};



#endif
