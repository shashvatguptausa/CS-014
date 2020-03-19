#include "Patient.h"

#include <iostream>
#include <utility>

#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

// Describe any additional functions that are needed for part III

int main(int argc,char* argv[]) {
    if (argc < 2) {
        cerr << "Proper usage: " << argv[0] << " <patients_file>." << endl;
        return 1;
    }

    ifstream ifs(argv[1]);
    if (!ifs.is_open()) {
        cerr << "Error: Unable to open " << argv[1] << endl;
        return 1;
    }


    
    map<int,int> intake_times;  //map, pairs can be made time; quick access and in order
    unordered_map<int, Patient*> patients; //unordered map as unique ids can be used to quickly access patients
    //priority_queue<Patient*, vector<Patient*>, SortedUrgencies> patient_urgencies;
    // a priority queue should be implemented as it can loosly sort the Patients by urgency
    
    //SortedUrgencies should be a struct that functions as a custom comparitor between patients.
    //It should consider High>Medium>Low.

    
    
    string first_name, last_name;
    int intake_time,urgency,id;
    
    //  N=Number of Patients
    // Overall runtime complexity: O(Nlog(N))
    // Overall space complexity: O(N)
    while (ifs >> id) {     //O(Nlog(N))
        ifs >> first_name >> last_name >> intake_time >> urgency; // O(1)
        Patient *patient_record = new Patient(id,first_name + " " + last_name); // O(1)
        patient_record->urgency(urgency); // O(1)

        intake_times.insert(make_pair(intake_time,id)); // O(log(N))
        patients.insert(make_pair(id,patient_record)); // O(1)
        // patient_urgencies.push_back(patient_record) // O(log(N))
        
    }  

    // Output Patients sorted by oldest intake_time (smallest) to newest intake_time (largest) (Implement)
    cout << "Sorted by intake times: " << endl;
    
    map<int,int>::iterator it;
    for(it = intake_times.begin();it!=intake_times.end();it++) {    // O(N)
        cout << *(patients.at(it->second)) << endl; //O(1)
    }
    
    // Output Patients ID's sorted by most urgent to least urgent
    // In commenst describe how this would work.
    
    //The code should simply print and pop of the top of the priority queue as it should be the highest priority through loose comparisons
    
    /*
     
     while( the priority queue is not empty ) {
     
     print top Patient
     pop Patient off of the priority queue
     
     }
     
     */

    return 0;
}
