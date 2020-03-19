#include "Student.h"
#include "IntSet.h"
#include <vector>
#include<iostream>

using namespace std;

int main(int argc,char* argv[1]) {
    
    
    if (argc < 2) {
        cerr << "Proper usage: " << argv[0] << " <input>." << endl;
        return 1;
    }

    ifstream ifs(argv[1]);
    if (!ifs.is_open()) {
        cerr << "Error: Unable to open \"" << argv[1] << "\"." << endl;
        return 1;
    }

    
    IntSet *stu = new IntSet(); //O(1)   //MY CODE

    vector<Student*> students;
    string first_name,last_name;
    int sid;
    while(ifs>>first_name) {
        ifs >> last_name >> sid;
        students.push_back(new Student(first_name+" "+last_name,sid));
        
        stu->insert(sid);   //O(1)       //MY CODE
    }

    int unique_students = 0;
    int comparisons = 0;
    //      N=number of students
    // Overall runtime complexity: O(N^2)
    // Overall space complexity: O(N)
    for (unsigned i = 0;i < students.size();++i) { // O(N^2)
        bool already_counted = false; // O(1)
        for (unsigned j = 0;j < i;++j) { // O(N)
            comparisons++; // O(1)
            if (*students.at(j) == *students.at(i)) {  // O(1)
                already_counted = true; // O(1)
            }
        }
        if (!already_counted) { unique_students++; } // O(1)
    }
    cout << "Unique students: " << unique_students << endl;
    cout << "\tComparisons made: " << comparisons << endl;

    /* Insert solution here */
    
    
    //in the areas noted "MY CODE" above, I inputed the data into my hash at the same time the naive sol does it
    
    
    cout << "Unique students: " << stu->size() << endl;
    cout << "\tComparisons made: " << stu->totCom() << endl;

    
    
    return 0;
}
