#include <iostream>
using namespace std;

#include "IntList.h"


int main() {
    
    IntList a;
    a.push_back(1);
    a.push_front(4);
    a.push_front(7);
    a.printReverse();
    cout << endl;
    a.pop_back();
    a.pop_front();
    a.pop_back();
    a.printReverse();
    cout << endl;
    if(a.empty()) {
        cout << "its empty :/" << endl;
    }
    cout << endl;
    a.push_front(4);
    a.push_front(5);
    cout << a;
    cout << endl;

    return 0;
}

