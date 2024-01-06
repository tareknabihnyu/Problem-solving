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
#include<cmath>
using namespace std;
#define SIZE 10
#define MAX 500
template <typename T> void selection_sort(T array[], int n);
template <typename T> void bubble_sort(T array[], int n);
template <typename T> void insertion_sort(T array[], int n);
template <typename T> void merge_sort(T array[], int left, int right);
template <typename T> void merge(T array[], int left, int right, int mid);
template <typename T> int partition(T array[], int left, int right);
template <typename T> void quick_sort(T array[], int left, int right);
template <typename T> void print(T array[], int size);
int main()
{
    int array[SIZE];
    srand(time(NULL));    
    for(int i=0; i<SIZE;i++) array[i] = rand()%MAX;
    
    int start = clock();
    selection_sort(array,SIZE);
    int stop = clock ();
    print(array,SIZE);
    cout<<"Selection Sort took: "<<float(stop - start )/  CLOCKS_PER_SEC*1000<<" milliseconds"<<endl;
    random_shuffle(array,array+SIZE);

    start = clock();
    bubble_sort(array,SIZE);
    stop = clock ();
    print(array,SIZE);
    cout<<"Bubble Sort took: "<<float(stop - start )/  CLOCKS_PER_SEC*1000<<" milliseconds"<<endl;
    random_shuffle(array,array+SIZE);

    start = clock();
    insertion_sort(array,SIZE);
    stop = clock ();
    print(array,SIZE);
    cout<<"Insertion Sort took: "<<float(stop - start )/  CLOCKS_PER_SEC*1000<<" milliseconds"<<endl;
    random_shuffle(array,array+SIZE);

    start = clock();
    merge_sort(array,0,SIZE-1);
    stop = clock ();
    print(array,SIZE);
    cout<<"Merge Sort took: "<<float(stop - start )/  CLOCKS_PER_SEC*1000<<" milliseconds"<<endl;
    random_shuffle(array,array+SIZE);

    start = clock();
    quick_sort(array,0,SIZE-1);
    stop = clock ();
    print(array,SIZE);
    cout<<"Quick Sort took: "<<float(stop - start )/  CLOCKS_PER_SEC*1000<<" milliseconds"<<endl;

    return EXIT_SUCCESS;
}
//========================================================
template <typename T> void print(T array[], int size)
{
    for(int i=0; i<size; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

template <typename T> void bubble_sort(T array[], int n){
    for (int y = 0; y < n; ++y) {
        for (int i = 0; i < (n-1) - y; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    
}

template <typename T> void insertion_sort(T array[], int n){
    for(int i = 1; i < n; i++){
        int ii = i; int z = i-1;
        while(array[ii] < array[z] && z > 0){
            swap(array[ii] , array[z]);
            z--;ii--;
        }
    }
}

template <typename T> void selection_sort(T array[], int n){
    for(int i = 0; i < n-1; i++){
        int*ptr = &array[i];
        int*p; 
        p = ptr; 
        ptr++;
        for(int z = i+1; z < n; z++){
            if(*ptr < *p) {
                p = ptr;
            }
            ptr++;
        }
        if(p != NULL) swap(array[i],array[(p - &array[0])]);
    }
}



template <typename T> void part(T array[], int left, int right){
    int count(0);
    for(int i = left; i <= right;i++){
        cout << array[i] << ":";
    }
    cout << endl;
}

template <typename T> void quick_sort(T array[], int left, int right){
    // part(array,left, right);
    int *ptr = &array[left];
    int* p = NULL;
    int mid;
    for(int i = left ; i <=right; i++){
        if(ptr == &array[right]){
            if(p != NULL){
                int temp = *p;
                *p = *ptr;
                *ptr = temp;
            }else{
                p = &array[right];
            }
            break;
        }
        if(p == NULL){
            if(*ptr <= array[right]){
                ptr++; continue;
            }else if(*ptr > array[right]){
                p = ptr; ptr++; continue;
            }
        }else{
            if(*ptr > array[right]){
                ptr++; continue;
            }else if(*ptr < array[right]){
                int temp = *p;
                *p = *ptr;
                *ptr = temp;
                p++; ptr++;
            }
        }
    }    
    // part(array,left, right);
    // cout << endl;

    
    // cout << "LL" << left <<"|"<< (p - &array[0])-1 << endl;
    if(partition(array,left, (p - &array[0])-1)>2 && (p - &array[0])-1 > -1){
        // cout << ">>" << left << "|||" << 
        // cout << "LL" << left <<"|"<< (p - &array[0])-1 << endl;
        quick_sort(array,left, (p - &array[0])-1);
    }

    // cout << "RR" << (p - &array[0])+1 << "|" << right << endl;
    if(partition(array,(p - &array[0])+1, right ) > 2 && (p - &array[0])+1 > -1){
        // cout << "RR" << (p - &array[0])+1 << "|" << right << endl;
        quick_sort(array,(p - &array[0])+1, right );
    }
}


template <typename T> int partition(T array[], int left, int right){
    int count(0);
    for(int i = left; i <= right;i++){
        count++;
    }
    if (count == 2){
        if(array[left] > array[right]){
            swap(array[left] , array[right]);
        }
    }
    return count;
}


template <typename T> void merge_sort(T array[], int left, int right){
    int mid = ((left + right + 1 ) / 2);

    // cout << left << "|" << mid << "|" << right << endl;

    if(right != left){
        merge_sort(array,left,mid-1);
        merge_sort(array,mid,right);
        merge(array,left,right,mid);
    }

    





}

template <typename T> void merge(T array[], int left, int right, int mid){
    int leftpart = left;
    int finalleft = mid-1;
    int rightpart = mid;
    int finalright = right;
    
    int *arr = new int[right-left+1];

    if(right == mid){
        if(array[mid] < array[left]){
            swap(array[mid] , array[left]);
        }
        return;
    }

    for(int i = 0; i < right-left+1 ; i++){
        if(leftpart > finalleft ){
            while(i < right-left+1 && rightpart <= finalright){
                arr[i] = array[rightpart];
                // cout <<"|>" << array[rightpart] << endl;
                rightpart++; i++;
            }
        }else if(rightpart > finalright){
            while(i < right-left+1 && leftpart <= finalleft){
                arr[i] = array[leftpart];
                // cout <<"||>" << array[leftpart] << endl;
                leftpart++; i++;
            }
        }else if(array[rightpart] > array[leftpart]){
            // cout <<"||" << array[leftpart] << endl;
            arr[i] = array[leftpart];
            leftpart++;
        }else if(array[rightpart] < array[leftpart]){
            // cout <<"|" << array[rightpart] << endl;
            arr[i] = array[rightpart];
            rightpart++;
        }

    }
    int z(0);
    for(int i = left; i <= right; i++){
        array[i] = arr[z]; z++;
    }
    delete [] arr;

    // cout << "^^^^^^^^^^^^^" << endl;
    // part(array,left,mid-1); part(array,mid,right);
    // cout << z << ">>";print(arr,right-left+1);
    // cout << "^^^^^^^^^^^^^" << endl;
}



