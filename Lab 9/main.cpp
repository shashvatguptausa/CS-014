//
//  main.cpp
//  Test
//
//  Created by Shashvat Gupta on 3/5/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

const int NUMBERS_SIZE = 100;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds


int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

void printA(int numbers[]) {
    for(int i = 0; i < NUMBERS_SIZE-1; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

//----------------------------------------------------//


int quickPart(int numbers[], int i, int k, int pivot) {
    int l = 0;
    int h = 0;
    int temp = 0;
    bool done = false;
              
    l = i;
    h = k;
       
       while (!done) {
           
          while (numbers[l] < pivot)
              ++l;
          while (pivot < numbers[h])
              --h;
          
          if (l >= h)
              done = true;
          else {
            //swap
              temp = numbers[l];
              numbers[l] = numbers[h];
              numbers[h] = temp;
             
              ++l;
              --h;
          }
       }
       
    return h;
    }


void Quicksort_midpoint(int numbers[], int i, int k) {
    int j = 0;
    if (i >= k)
        return;
    
    int pivot = numbers[ (i + (k - i) / 2)];

    j = quickPart(numbers, i, k, pivot);           //last of small
    
    Quicksort_midpoint(numbers, i, j);      //small
    Quicksort_midpoint(numbers, j + 1, k);  //large
}

//----------------------------------------------------//

void swap(int numbers[], int dex1, int dex2) {
  int temp = numbers[dex1];
  numbers[dex1] = numbers[dex2];
  numbers[dex2] = temp;
}

 int medianOf3(int numbers[], int left, int right) {
  int center = (left + right) / 2;
  // order left & center
  if (numbers[left] > numbers[center])
    swap(numbers, left, center);
  // order left & right
  if (numbers[left] > numbers[right])
    swap(numbers, left, right);
  // order center & right
  if (numbers[center] > numbers[right])
    swap(numbers, center, right);

  swap(numbers, center, right - 1); // put pivot on right
  return numbers[right - 1]; // return median value
}

 

void Quicksort_medianOfThree(int numbers[], int i, int k) {
    
    if(k<=i)
        return;
    
    int median = medianOf3(numbers, i, k);
    int j = quickPart(numbers, i, k, median);
    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j + 1, k);

}

//----------------------------------------------------//


void InsertionSort(int numbers[], int numbersSize) {
    
    for(int i = 0; i < numbersSize; i++) {
        for(int j = i; j > 0; j--) {
            if(numbers[j]<numbers[j-1]) {
                swap(numbers,j-1,j);
            }
        }
    }
}

//----------------------------------------------------//

int main() {
    
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    
    fillArrays(arr1, arr2, arr3);
    
    cout << "Before:" << endl;
    printA(arr3);
    
    clock_t Start1 = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    clock_t End1 = clock();
    unsigned long elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS;
    
    clock_t Start2 = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    clock_t End2 = clock();
    unsigned long elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS;
    
    clock_t Start3 = clock();
    InsertionSort(arr3, NUMBERS_SIZE-1);
    clock_t End3 = clock();
    unsigned long elapsedTime3 = (End3 - Start3)/CLOCKS_PER_MS;
    
    cout << "\n**Elapsed time:**\n\nQuicksort_midpoint: " << elapsedTime1 << "ms\nQuicksort_medianOfThree: " << elapsedTime2 << "ms\nInsertionSort: " << elapsedTime3 <<  "ms\n" << endl;

    cout << "Arr 1:" << endl;
    printA(arr1);
    
    cout << "Arr 2:" << endl;
    printA(arr2);
    
    cout << "Arr 3:" << endl;
    printA(arr3);
}


//----------------------------------------------------//

