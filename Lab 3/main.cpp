#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
void print(const vector<T> &test) {
    for(unsigned i = 0; i < test.size(); i++) {
        cout << test.at(i) << " ";
    }
    cout << endl;
}

template <typename T>
void swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}
template <typename T>

unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned small = (index);
    //cout << "small: " << small << endl;
    for(unsigned i = index; i < vals.size(); i++) {
        if((T)vals.at(i) < vals.at(small)) {
            small = (i);
           //cout << "new small: " << small << endl;
        }
    }
    //cout << "returning small: " << small << endl;
    return small;
}

template <typename T>

void selection_sort(vector<T> &vals) {
    
    if(vals.size()<=1) {
        return;
    }
    for(unsigned i = 0; i < vals.size()-1; i++) {
        //cout << "\ntrial #" << i+1 << endl;
        swap(&vals[ min_index(vals, i) ],&vals[i]);
        //print(vals);

    }
}

template <typename T>

T getElement(vector<T> vals, int index) {
    if((unsigned)index>vals.size())
        throw out_of_range("out of range exception occured");
    
    return vals.at(index);
}


vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main() {
   
    vector<int> test;
    test.push_back(1);
    test.push_back(4);
    test.push_back(-1);
    test.push_back(-9);
    test.push_back(0);

    //print(test);

    
    selection_sort(test);
    
    
    print(test);
   
    
    //--------------------
    /*
    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
    }
*/
    return 0;
}

