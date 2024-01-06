//============================================================================
// Name         : lab4.cpp
// Author       : Tarek Nabih
// Version      : 1.0
// Date Created : 
// Date Modified: 
// Copyright    : All rights are reserved
// Description  : Doubly LinkedList implementation in C++
//============================================================================
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<exception>
using namespace std;

template  <typename E>
class MyList;
template  <typename E>
class Node
{
	private:
		E elem; //data element (type string in this case)
		Node* next; //Link (pointer) to the next Node
		Node* prev; //Link (pointer) to the previous Node
		friend class MyList<E>;
		
	public:
		Node(): next(NULL), prev(NULL)
		{}
		Node(E elem) : elem(elem), next(NULL), prev(NULL)
		{}
};
template  <typename E>
class MyList
{
	private:
		Node<E>* head; 	// pointer to the head of List
		Node<E>* tail; 	// pointer to the tail of List
		int size;
	public:
		MyList (); // empty list constructor
		~MyList (); // destructor to clean up all nodes
		bool empty() ; // is list empty?
		E& front(); // get the value (element) from front Node of list
		E& back() ;  // get the value (element) from last Node of the List 
		void addBefore(Node<E> *ptr,  E elem);	 //add a new node before ptr
		void addFront( E elem); // add a new node to the front of list
		void addBack( E  elem); //add a new node to the back of the list
		void removeFront(); // remove front node from list
		void removeBack();  // remove last node from list
		void displayadmin();
		void displaymember();
		void displayfitness();
		E& findTheNumber(int f);
		int givesize(){return size;}
		void removebefore(Node<E> *ptr){
			//Node<E>* u = ptr;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			delete ptr;
		}
		Node<E>* findTherefrence(int f){
			int ff = 0;
			Node<E> * a = head;              
			do{
				a = a->next;  
				if(a == NULL || a->next == NULL){
					break;                  //if a is null then the seris had ended
				}
				if(f == ff)
					break;
				ff++;
			}while( a->next != NULL );          
			return a;
		}
};
//END-Node stuff==================================================================================================================================






//doubly linked list functions================================================================================================================================
template  <typename E>
MyList<E>::MyList ()
{
	head = new  Node<E>;
	tail = new  Node<E>;
	head->next=tail;
	tail->prev=head;
	size = 0;
}
template  <typename E>
MyList<E>::~MyList () // destructor to clean up all nodes
{
	while (!empty()) removeFront();
	delete head;
	delete tail;
}
template  <typename E>
bool MyList<E>::empty()  // is list empty?
{
	return (head->next == tail);
}
template  <typename E>
E& MyList<E>::front()  // get front element
{
	return head->next->elem;
}
template  <typename E>
E& MyList<E>::back()  // get front element
{
	return tail->prev->elem;
}
template  <typename E>
void MyList<E>::addBefore(Node<E> *ptr,  E eelem)
{
	Node<E>* u = new Node<E>;
	u->elem = eelem;
	u->next = ptr;
	u->prev = ptr->prev;
	ptr->prev->next = u;
	ptr->prev = u;
	size++;
}
template  <typename E>
void MyList<E>::addFront( E eelem) // add to front of list
{

	Node<E>* u = new Node<E>;
	u->elem = eelem;
	u->next = head->next;
	u->prev = head;
	head->next->prev = u;
	head->next = u;
	size++;
}
template  <typename E>
void MyList<E>::addBack( E elem) // add to Back of the list
{
	Node<E>* u = new Node<E>;
	u->elem = elem;
	u->prev = tail->prev;
	u->next = tail;
	tail->prev->next = u;
	tail->prev = u;
	size++;
}
template  <typename E>
void MyList<E>::removeFront() // remove front item from list
{
	Node<E>* u = new Node<E>;
	u = head->next;
	head->next = head->next->next;
	head->next->prev= head;
	delete u;
	size--;
}
template  <typename E>
void MyList<E>::removeBack() // remove last item from list
{
	Node<E>* u = new Node<E>;
	u = tail->prev;
	tail->prev = tail->prev->prev;
	tail->prev->next= tail;
	delete u;
	size--;
}
template  <class admin>
void MyList<admin>::displayadmin(){
	Node<admin> * a = head;              //initialzing the node into the head 
 	 //cout << "<<<<<<<<<<<admins>>>>>>>>>>>" << endl;     // making the series of nodes
	do{
	a = a->next;  
    if(a == NULL || a->next == NULL){
      break;                  //if a is null then the seris had ended
    }
     a->elem.display() ;   // printing out the element of the node              // moving to the next index
  }while( a->next != NULL );          
  //cout << "<<<<<<<done>>>>>>>" << endl;

}
template  <class member>
void MyList<member>::displaymember(){
	Node<member> * a = head;              //initialzing the node into the head 
 	 //cout << "<<<<<<<<<<<members>>>>>>>>>>>" << endl;     // making the series of nodes
	do{
	a = a->next;  
    if(a == NULL || a->next == NULL){
      break;                  //if a is null then the seris had ended
    }
     a->elem.display() ;   // printing out the element of the node              // moving to the next index
  }while( a->next != NULL );          
  //cout << "<<<<<<<done>>>>>>>" << endl;
}
template  <class fitnessClass>
void MyList<fitnessClass>::displayfitness(){
	Node<fitnessClass> * a = head;              //initialzing the node into the head 
 	 //cout << "<<<<<<<<<<<FitnessClasses>>>>>>>>>>>" << endl;     // making the series of nodes
	do{
	a = a->next;  
    if(a == NULL || a->next == NULL){
      break;                  //if a is null then the seris had ended
    }
     a->elem.display() ; 
	 //a->elem.allmembersInClass();
  }while( a->next != NULL );          
  //cout << "<<<<<<<done>>>>>>>" << endl;
}
template  <typename E>
E& MyList<E>::findTheNumber(int f){
			int ff = 0;
			Node<E> * a = head;              
			do{
				a = a->next;  
				if(a == NULL || a->next == NULL){
					break;                  //if a is null then the seris had ended
				}
				if(f == ff)
					break;
				ff++;
			}while( a->next != NULL );          
			return a->elem;
}
//================================================================================================================================
