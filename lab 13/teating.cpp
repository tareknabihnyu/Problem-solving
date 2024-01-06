//============================================================================
// Name         : lab14.cpp
// Author       : Khalid Mengal
// Version      : 1.0
// Date Created : 04-05-2020
// Date Modified: 04-05-2020 
// Copyright    : All rights are reserved
// Description  : Sorting Algorithms (Selection Sort, Bubble Sort, Insertion Sort, Merge Sort, Quick Sort, Heap Sort)
//============================================================================

#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
#define SIZE 10
#define MAX 500

template <typename T> void print(T array[], int size)
{
    for(int i=0; i<size; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}


int main()
{
    int arr[5] = {1,2,3,4,5};
    // int* p = arr;
    // cout << *p << endl;
    // int * pp = p;
    // int temp = *p;
    // p++;
    // cout << *p << endl;
    // *pp = *p;
    // *p = temp;
    // cout << *p << endl; 
    // cout << *pp << endl; 
    // print(arr,5);

    int* p = &arr[4];
    int* pp = &arr[0];
    cout << p - &arr[0] << endl;
    
    return EXIT_SUCCESS;
}
//========================================================

