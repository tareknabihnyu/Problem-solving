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

class Node
{
	private:
		string elem; //data element (type string in this case)
		Node* next; //Link (pointer) to the next Node
		Node* prev; //Link (pointer) to the previous Node
		friend class DoublyLinkedList;
		
	public:
		Node(): next(NULL), prev(NULL)
		{}
		Node(string elem) : elem(elem), next(NULL), prev(NULL)
		{}
};
//==============================================================
class DoublyLinkedList
{
	private:
		Node* head; 	// pointer to the head of List
		Node* tail; 	// pointer to the tail of List
	public:
		DoublyLinkedList (); // empty list constructor
		~DoublyLinkedList (); // destructor to clean up all nodes
		bool empty() const; // is list empty?
		const string& front() const; // get the value (element) from front Node of list
		const string& back() const;  // get the value (element) from last Node of the List 
		void addBefore(Node *ptr, const string& elem);	 //add a new node before ptr
		void addFront(const string& elem); // add a new node to the front of list
		void addBack(const string & elem); //add a new node to the back of the list
		void removeFront(); // remove front node from list
		void removeBack();  // remove last node from list
		void reverseList();	// reverse the list
		bool isPalindrome(); //check if the List is Palindrome or not
		void display() const;	// display all element of the list
};
//===================================
void listCommands()
{
	cout<<"List of available Commands:"<<endl
		<<"display            : Display the Doubly Linkled List"<<endl
		<<"front              : Display the first element of the List"<<endl
		<<"back               : Display the last element of the List"<<endl
		<<"addFront <elem>    : Add a new Node at the begining of the List"<<endl
		<<"addBack  <elem>    : Add a new Node at the end of the List"<<endl
		<<"removeFront        : Remove the first Node of the Linked List"<<endl
		<<"removeBack         : Remove the last  Node of the Linked List"<<endl	
		<<"isempty            : Check if the List is empty?"<<endl
		<<"reverse            : Reverse the Linked List"<<endl
		<<"isPalindrome       : Check if the List is Palindrome or not?"<<endl
		<<"help               : Display the list of available commands"<<endl
		<<"exit               : Exit the Program"<<endl;
}
//===================================
int main()
{
	DoublyLinkedList myList;
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
		
		try
		{
			if(command=="display") 				myList.display();
			else if(command=="front")			cout<<"Front = "<<myList.front()<<endl;
			else if(command=="back")			cout<<"Back = "<<myList.back()<<endl;
			else if(command=="addFront")		myList.addFront(parameter),myList.display();
			else if(command=="addBack")		 	myList.addBack(parameter),myList.display();
			else if(command=="removeFront")		myList.removeFront(),myList.display();
			else if(command=="removeBack")		myList.removeBack(),myList.display();
			else if(command=="isempty")			cout<<"List is "<<(myList.empty()? "Empty":"Not Empty")<<endl;
			else if(command=="reverse")			myList.reverseList(),myList.display();
			else if(command=="isPalindrome")	cout<<"List is "<<(myList.isPalindrome()? "Palindrome":"Not Palindrome")<<endl;
			else if(command == "help")			listCommands();
			else if(command == "exit")			break;
			else 								cout<<"Invalid Commad !!"<<endl;
		}
		catch(exception &e)
		{
			cout<<"Exception: "<<e.what()<<endl;
		}

	}while(command!="exit" and command!="quit");

	return EXIT_SUCCESS;
}
//============================================================
DoublyLinkedList::DoublyLinkedList ()
{
	head = new Node;
	tail = new Node;
	head->next=tail;
	tail->prev=head;
}
//============================================================
DoublyLinkedList::~DoublyLinkedList () // destructor to clean up all nodes
{
	while (!empty()) removeFront();
	delete head;
	delete tail;
}
//============================================================
bool DoublyLinkedList::empty() const // is list empty?
{
	return (head->next == tail);
}
//============================================================
const string& DoublyLinkedList::front() const // get front element
{
	return head->next->elem;
}
//============================================================
const string& DoublyLinkedList::back() const // get front element
{
	return tail->prev->elem;
}
//============================================================
void DoublyLinkedList::addBefore(Node *ptr, const string& elem)
{
	Node* u = new Node;
	u->elem = elem;
	u->next = ptr;
	u->prev = ptr->prev;
	ptr->prev->next = u;
	ptr->prev = u;
}
//============================================================
void DoublyLinkedList::addFront(const string& elem) // add to front of list
{

	Node* u = new Node;
	u->elem = elem;
	u->next = head->next;
	u->prev = head;
	head->next->prev = u;
	head->next = u;
}
//============================================================
void DoublyLinkedList::addBack(const string& elem) // add to Back of the list
{
	Node* u = new Node;
	u->elem = elem;
	u->prev = tail->prev;
	u->next = tail;
	tail->prev->next = u;
	tail->prev = u;
}
//============================================================
void DoublyLinkedList::removeFront() // remove front item from list
{
	Node* u = new Node;
	u = head->next;
	head->next = head->next->next;
	head->next->prev= head;
	delete u;
}
//============================================================
void DoublyLinkedList::removeBack() // remove last item from list
{
	Node* u = new Node;
	u = tail->prev;
	tail->prev = tail->prev->prev;
	tail->prev->next= tail;
	delete u;
}
//============================================================
void DoublyLinkedList::display() const
{
	Node *curr=head;
	while(curr!=NULL)
	{
		cout<<"+------";
		curr=curr->next;
	}
	cout<<"+"<<endl<<"|";
	curr=head;
	while(curr!=NULL)
	{
		if (curr == head)		cout<<" Head |";
		else if(curr == tail)	cout<<" Tail |";
		else 					cout<<setw(5)<<curr->elem<<" |";
	
		curr=curr->next;
	}
	curr=head;
	cout<<endl;
	while(curr!=NULL)
	{
		cout<<"+------";
		curr=curr->next;
	}
	cout<<"+"<<endl;
}
//============================================================
void DoublyLinkedList::reverseList()
{
	
	Node* a = new Node;
	Node* b = new Node;
	a = head; b = a->next; 
	a->prev = a->next;
	a->next = NULL; 
	a = b;
 	while (a != tail){
		 b = a->next;
		 a-> next = a->prev;
		 a-> prev = b;
		 a = b;
	 }
	 a->next = a->prev;
	 a->prev = NULL;
	Node* i = tail;
	tail = head;
	head = i;
}
//============================================================
bool DoublyLinkedList::isPalindrome()
{
	Node*a = new Node;
	a = head->next;
	Node*b = new Node;
	b = tail->prev;
	bool isIT(1);
	while(a != b && b->next != a ){
		if(a->elem != b->elem ){
			isIT = 0; break;
		}
		a = a->next; b = b->prev;
	}
	return isIT;

}
