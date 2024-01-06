
//============================================================================
// Name         : lab3.cpp
// Author       : Tarek Nabih
// Version      : 1.0
// Date Created : 
// Date Modified: 
// Copyright    : All rights are reserved
// Description  : Singly Linked-List implementation in C++
//============================================================================
#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
using namespace std;
//====================================
class Node
{
	private:
		int elem; //data element 
		Node* next; //Link (pointer) to the next Node
		
	public:
		Node(int elem) : elem(elem), next(NULL)
		{}
		friend class MyLinkedList ;
};
//=====================================
class MyLinkedList
{
	private:
		Node* head; // pointer to the head of list
	public:
		MyLinkedList (); // empty list constructor
		~MyLinkedList (); // destructor to clean up all nodes
		bool empty() const; // is list empty?
		void addFront(int elem); // add a new Node at the front of the list
		void removeFront(); // remove front Node from the list
		unsigned int countElem(int elem); //count frequency of an element in the list
		int getIndexOf(int elem); //returns first index of an element in the list, -1 if the element is not present
		void display() const;
		void loadData(string); //read a file and load it into the linked list
		void dumpData(string) const; //write the linked list to a file
		void sort();  // sort the elements of the list
};
//=====================================
void listCommands()
{
	cout<<"List of available Commands:"<<endl
		<<"display            : Display the Linked List"<<endl
		<<"addFront <element> : Add <element> to the front of the Linked List"<<endl
		<<"removeFront        : Remove the front node of the Linked List"<<endl
		<<"count <element>    : count frequency of an element in the list"<<endl
		<<"indexOf <element>  : return first index of an elemenent in the list (-1 of not present)"<<endl
		<<"load <file_name>   : Load the data from <file> and add it into the Linked List"<<endl
		<<"dump <file_name>   : Dump the contents of the Linked list to <file>"<<endl
		<<"sort               : Sort the Linked List using Bubble Sort Algorithm"<<endl
		<<"help               : Display the list of available commands"<<endl
		<<"exit               : Exit the Program"<<endl;
}
//=======================================
// main function
int main()
{

	MyLinkedList myList;

	listCommands();
	string user_input;
	string command;
	string parameter;

	do
	{
		cout<<">";
		getline(cin,user_input);
		
		// parse userinput into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,parameter);
		
		
		if(command=="display") 				myList.display();
		else if(command=="addFront" || command=="add")				myList.addFront(stoi(parameter)),myList.display();
		else if(command=="removeFront" || command=="remove")		myList.removeFront(),myList.display();
		else if(command=="count")			cout<<parameter<<" occurs "<<myList.countElem(stoi(parameter))<<" time(s) in the list"<<endl;
		else if(command=="indexOf")         cout<<"First index of "<<parameter<<" in the list is: "<<myList.getIndexOf(stoi(parameter))<<endl;
		else if(command=="load")			myList.loadData(parameter),myList.display();
		else if(command == "dump")			myList.dumpData(parameter);
		else if(command == "sort")			myList.sort(),myList.display();
		else if(command == "help")			listCommands();
		else if(command == "exit")			break;
		else 								cout<<"Invalid Commad !!"<<endl;
	}while(command!="exit");

	return EXIT_SUCCESS;
}
//====================================
// constructor
MyLinkedList::MyLinkedList ()
{
	this->head = NULL;
}
//====================================
// destructor to clean up all nodes
MyLinkedList::~MyLinkedList () 
{
	while(!empty()) removeFront(); //as long is it not empty then remove the front
}
//====================================
// Check if the list is empty or not
bool MyLinkedList::empty() const 
{
	return head == NULL;  // because if heaed is empty then it is all empty
}
//====================================
// add a node at the front of the list
void MyLinkedList::addFront(int elem)
{
  Node* a = new Node(elem); //making a new node with the new number
  a->elem = elem;            //double insuring
  a->next = head;            // pointing the head of the nodes
  head = a;                //making the new head equal to a
  
}
//====================================
// remove the first node from the list
void MyLinkedList::removeFront()
{
  Node * remove = head;        //keeping what the head is pointing to to delete it later
  head = remove->next;         //moving the head to the next node
  delete remove;               // delete the the first node
}
//====================================
// count frequency of an element in the list
unsigned int MyLinkedList::countElem(int elem)
{
	int count(0);
	Node*a = head;

	while(a!= NULL){
		if(a->elem == elem){
			count++;           // if the element of a is the required element the increment count
		}
		a = a->next;   
	}

	return count;  	                //returning the count
}
//==============================================
// get first index of an element in the the list.
// returns -1 if the element is not present
int MyLinkedList::getIndexOf(int elem)
{







	
// 	int count(1); // so that the head points to the first thing in the array
//   // the index of the head is gonna be one
//   Node*a = head;    //initializing the node by head
// 	do{
//     if(a->elem == elem){
//       return count;    // if we found it then close the function by giving out the index
//     }
//     a = a->next;        //moving to the next node
//     count++;              //incrementing the index
//   }while( a != NULL );
//   return -1;                //if not found
}
//==============================================
// display all nodes of the linked list
void MyLinkedList::display() const
{
  Node*a = head;              //initialzing the node into the head 
  cout << "head" << endl;     // making the series of nodes
	do{
    if(a == NULL){
      break;                  //if a is null then the seris had ended
    }
    cout << a->elem << endl;   // printing out the element of the node
    a = a->next;                // moving to the next index
  }while( a != NULL );          
  cout << "done" << endl;


}
//====================================
// sort the elments of the list using bubble_sort
void MyLinkedList::sort()
{
  int happen(1); // to check whether the swapping happened   
  Node* first;    // initializing the node
  
  while(happen){
    happen = 0;          //it is normally zero unless proven otherwise
    first = head;
    while(first->next != NULL){
      if(first->elem > first->next->elem){  //if the current node have higher value then swap
        int temp;  
        temp = first->next->elem;            //the swapping process
          first->next->elem = first->elem;
          first->elem = temp;
          happen = 1;                  //telling the program that the swapping occured
        }
      first = first->next;        //going the next process
    }
  }  
}
//==============================================
//Load data from a file and add it to the Linked List
void MyLinkedList::loadData(string path)
{
	ifstream file(path ); //making a file
  if(file.fail()) {
    cerr << "file could not be opened" << endl;
  }
  //Node*a = head; 
  int number;          
	while( file >> number ){ //getting the numbers from the file
    addFront(number);        //adding the numbers to the sequence
  }
  file.close();        //closing the file

  

}
//=============================================
//Dump/write the contents of the list to a file
void MyLinkedList::dumpData(string path) const
{
	ofstream file(path); //you have to write .txt when you add the file's name
  if(file.fail()) {
    cerr << "file could not be opened" << endl;
  }
  Node*a = head;   //initializing the sequence
	do{
    file << a->elem << endl;      //just outputting into the file
    a = a->next;            //going to the next node
  }while( a != NULL );  
  file.close();
}
//==================================================

