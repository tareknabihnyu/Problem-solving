//============================================================================
// Name         : MyVector.cpp
// Author       : Khalid Mengal
// Version      : 1.0
// Date Created : 16-03-2019
// Date Modified: 21-10-2021 
// Copyright    : All rights are reserved
// Description  : Vector implmentation in C++
//============================================================================
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<stdexcept>
#include<sstream>

using namespace std;
template <typename T>
class MyVector
{
	private:
		T *data;						//pointer to int(array) to store elements
		int v_size;						//current size of vector (number of elements in vector)
		int v_capacity;					//capacity of vector
	public:
		MyVector();						//No argument constructor
		MyVector(int cap);				//One Argument Constructor
		~MyVector();	
		void reserve(int N) {
			if (v_capacity >= N) return;
			T* B = new T[N]; // resize the array
			for (int j = 0; j < v_capacity; j++) // copy contents to new array
				B[j] = data[j];
			if (data != NULL) delete [ ] data; // discard old array
			data = B; // make B the new array
			v_capacity = N; 
		}
		void push_back(T element);		//Add an element at the end of vector
		void insert(int index, T element); //Add an element at the index 
		void erase(int index);			//Removes an element from the index
		T& at(int index); 				//return reference of the element at index
		const T& front();				//Returns reference of the first element in the vector
		const T& back();				//Returns reference of the Last element in the vector
		int size() const;				//Return current size of vector
		int capacity() const;			//Return capacity of vector
		bool empty() const; 			//Rturn true if the vector is empty, False otherwise
		void shrink_to_fit();			//Reduce vector capacity to fit its size
		void display();
};


#ifndef _WIN32
//======================================
template <typename T>
void MyVector<T>::display()
{
	cout<<"╔════";
	for(int i=0; i<v_capacity-1; i++)
		cout<<"╦════";	
	cout<<"╗ size = "<<v_size<<endl;
	
	for(int i=0; i<v_capacity; i++)
	{
		if(i<v_size)
			cout<<"║"<<setw(4)<<data[i];
		else
			cout<<"║"<<setw(4)<<" ";		
	}
	if(v_size==0) cout<<"║    ";
	cout<<"║"<<endl<<"╚════";
	for(int i=0; i<v_capacity-1; i++)
		cout<<"╩════";
	cout<<"╝ capacity = "<<v_capacity<<endl;	
}
//======================================
#else
template <typename T>
void MyVector<T>::display()
{
	cout<<"+";
	for(int i=0; i<v_capacity; i++)
		cout<<"---+";	
	cout<<" size = "<<v_size<<endl;
	
	for(int i=0; i<v_capacity; i++)
	{
		if(i<v_size)
			cout<<"|"<<setw(3)<<data[i];
		else
			cout<<"|"<<"   ";		
	}
	cout<<"|"<<endl<<"+";
	for(int i=0; i<v_capacity; i++)
		cout<<"---+";
	cout<<" capacity = "<<v_capacity<<endl;	
}
#endif




template <typename T>
MyVector<T>::MyVector(){
	v_size = 0;
	v_capacity = 1;
	data = new T[v_capacity];
}

template <typename T>
MyVector<T>::MyVector(int cap){
	v_size = 0;
	v_capacity = 1;
	data = new T[cap];
}

template <typename T>
MyVector<T>::~MyVector(){
	delete [] data;
}

template <typename T>
void MyVector<T>::push_back(T element){
	if (v_size == v_capacity) {
            T* temp = new T[2 * v_capacity];
 
            
            for (int i = 0; i < v_capacity; i++) {
                temp[i] = data[i];
            }
 
        
            delete[] data;
            v_capacity *= 2;
            data = temp;
        }
 
        // Inserting data
	data[v_size] = element;
	v_size++;
}

template <typename T>
void MyVector<T>::insert(int index, T element){
	if (v_size >= v_capacity) 
		reserve( max(1, 2 * v_capacity) ); 
	for (int j = v_size - 1; j >= index; j--) 
		data[j+1] = data[j];
	data[index] = element; 
	v_size++;

}


template <typename T>
void MyVector<T>::erase(int index){
	if(v_size > index){
		for(int i = index; i < v_size ; i++){
			data[i] = data[i+1];
		}
		v_size--;
	}
}

template <typename T>
T& MyVector<T>::at(int index){
	if(index < v_size)
		return data[index];
}

template <typename T>
const T& MyVector<T>::front(){
	return data[0];
}

template <typename T>
const T& MyVector<T>::back(){
	return data[v_size - 1];
}

template <typename T>
int MyVector<T>::size() const{
	return v_size;
}

template <typename T>
int MyVector<T>::capacity() const{
	return v_capacity;
}

template <typename T>
bool MyVector<T>::empty() const{
	return (v_size == 0)? true : false;
}

template <typename T>
void MyVector<T>::shrink_to_fit(){
	v_capacity = v_size;
}


