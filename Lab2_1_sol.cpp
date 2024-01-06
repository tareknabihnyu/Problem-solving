
//============================================================================
// Name         : lab2_1
// Author       : Tarek Nabih
// Version      : 1.0
// Date Created : 
// Date Modified: 
// Description  : Find Min. and Max. values from an Array passed to a function 
//                using pass-by reference. 
//============================================================================
#include<iostream>
#include<cstdlib>
using namespace std;

void findMinMax(int[],int, int&, int&);	//function declaration

int main(void)
{
  srand( time(NULL)); 
	//Declare variables
  int size, *arr, MAX(0), MIN(9999);
	//Prompt user for the array size
	cout << "please enter the array size: "; cin >> size;
  //Create dynamic array
  arr = new int[size];
	//Populate the array with random values
  for(int i = 0; i < size; i++){
    arr[i] = rand() % 101;
  }
	//Call function finMinMax()
  findMinMax(arr, size, MIN, MAX);
	//Print the values of array followed by min and max values
	for(int i = 0; i < size; i++){
    cout << "array[" << i << "] = " << arr[i] << endl; 
  }
  cout << "Min : " << MIN << endl << "Max : " << MAX << endl;
  //Do Necessary cleanup, e.g. delete dynamically allocated memory.
  delete [] arr;
	return EXIT_SUCCESS;
}

//Function Definition
void findMinMax(int array[], int arraySize, int& min, int& max)
{
    //define max and min
    max = array[0];
    min = array[0];

	for(int i = 0; i < arraySize; i++){
    if(array[i] > max){ //finding the maximum number
      max = array[i];
    }
    if(array[i] < min){ //finding the minimum number
      min = array[i];
    }

  }
}
